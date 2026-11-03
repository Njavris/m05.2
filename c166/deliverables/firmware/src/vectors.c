#include "vectors.h"
#include "mem.h"

/*
 * XC164CS interrupt/trap names, indexed by vector_address / 4.
 * The datasheet's default vector spacing is 4 bytes.
 */
static const char *const vector_names[128] = {
    [0]  = "RESET",
    [2]  = "NMITRAP",
    [4]  = "STOTRAP",
    [6]  = "STUTRAP",
    [10] = "BTRAP",

    [16] = "CC0IC",  [17] = "CC1IC",  [18] = "CC2IC",  [19] = "CC3IC",
    [20] = "CC4IC",  [21] = "CC5IC",  [22] = "CC6IC",  [23] = "CC7IC",
    [24] = "CC8IC",  [25] = "CC9IC",  [26] = "CC10IC", [27] = "CC11IC",
    [28] = "CC12IC", [29] = "CC13IC", [30] = "CC14IC", [31] = "CC15IC",

    [32] = "T0IC",   [33] = "T1IC",   [34] = "T2IC",   [35] = "T3IC",
    [36] = "T4IC",   [37] = "T5IC",   [38] = "T6IC",   [39] = "CRIC",
    [40] = "ADC_CIC",[41] = "ADC_EIC",
    [42] = "ASC0_TIC", [43] = "ASC0_RIC", [44] = "ASC0_EIC",
    [45] = "SSC0_TIC", [46] = "SSC0_RIC", [47] = "SSC0_EIC",

    [48] = "CC16IC", [49] = "CC17IC", [50] = "CC18IC", [51] = "CC19IC",
    [52] = "CC20IC", [53] = "CC21IC", [54] = "CC22IC", [55] = "CC23IC",
    [56] = "CC24IC", [57] = "CC25IC", [58] = "CC26IC", [59] = "CC27IC",
    [60] = "CC28IC",
    [61] = "T7IC",   [62] = "T8IC",

    [64] = "UNASSIGNED_64", [65] = "UNASSIGNED_65",
    [66] = "ASC1_ABIC", [67] = "PLLIC",
    [68] = "CC29IC", [69] = "CC30IC", [70] = "CC31IC", [71] = "ASC0_TBIC",
    [72] = "ASC1_TIC", [73] = "ASC1_RIC", [74] = "ASC1_EIC",
    [75] = "UNASSIGNED_75",
    [76] = "EOPIC", [77] = "CCU6_T12IC", [78] = "CCU6_T13IC",
    [79] = "CCU6_EIC", [80] = "CCU6_IC",
    [81] = "SSC1_TIC", [82] = "SSC1_RIC", [83] = "SSC1_EIC",
    [84] = "CAN0IC", [85] = "CAN1IC", [86] = "CAN2IC", [87] = "CAN3IC",
    [88] = "UNASSIGNED_88",
    [89] = "CAN4IC", [90] = "CAN5IC", [91] = "CAN6IC", [92] = "CAN7IC",
    [93] = "RTC_IC", [94] = "ASC1_TBIC", [95] = "ASC0_ABIC",
};

const char *vector_source_name(u32 vector_address)
{
    u32 index;
    if (vector_address < C166_FLASH_BASE) {
        return "RESERVED";
    }
    index = (vector_address - C166_FLASH_BASE) / 4u;
    if (index >= 128u || vector_names[index] == NULL) {
        return "RESERVED";
    }
    return vector_names[index];
}

int vector_decode_all(vector_t *out, int max)
{
    int count = 0;
    u32 off;

    for (off = 0; off < 0x200u && count < max; off += 4u) {
        u8 op = mem_read8(C166_FLASH_BASE + off);
        u32 target = 0;
        int active = 0;

        if (op == 0xFAu) {                 /* JMPS seg:offset */
            u8 seg = mem_read8(C166_FLASH_BASE + off + 1u);
            u16 offset = mem_read16(C166_FLASH_BASE + off + 2u);
            target = ((u32)seg << 16) | (u32)offset;
            active = (target != 0u);
        }

        out[count].address = C166_FLASH_BASE + off;
        out[count].source = vector_source_name(C166_FLASH_BASE + off);
        out[count].target = target;
        out[count].active = active;
        count++;
    }

    return count;
}
