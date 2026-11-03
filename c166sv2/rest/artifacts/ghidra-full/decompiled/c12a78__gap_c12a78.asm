; c12a78 gap_c12a78 size=98
c12a78  mov r4,#0x7fc
c12a7c  mov r5,#0xe0
c12a80  calls 0xc28c54
c12a84  sub r10,#0x8625
c12a88  subc r11,#0x6450
c12a8c  jmpr cc_EQ,0xc12aa6
c12a8e  mov r4,#0x7fc
c12a92  mov r5,#0xe0
c12a96  calls 0xc28c54
c12a9a  sub r10,#0x6450
c12a9e  subc r11,#0x8633
c12aa2  jmpa cc_NE,0xc12ab4
c12aa6  diswdt
c12aaa  bclr 0xff10.0xb
c12aac  srst
c12ab0  jmpa cc_UC,0xc12f6e
c12ab4  movb RL1,0xc5a9
c12ab8  jmpr cc_EQ,0xc12abe
c12aba  mov r13,#0x2
c12abc  jmpr cc_UC,0xc12ac2
c12abe  mov r13,0xc5b4
c12ac2  mov r12,r13
c12ac4  cmp r12,#0xffff
c12ac8  jmpr cc_EQ,0xc12ae8
c12aca  add r12,#0x1
c12acc  cmp r12,0xc59e
c12ad0  jmpr cc_ULE,0xc12ad6
c12ad2  sub 0xc59e,0xff1e
c12ad6  cmp r12,0xc59e
