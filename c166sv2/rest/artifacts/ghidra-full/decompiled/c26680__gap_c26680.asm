; c26680 gap_c26680 size=46
c26680  mov r12,#0x17
c26684  mov r13,#0x18
c26688  mov r14,#0x10
c2668c  calls 0xc24c46
c26690  mov r12,0xc99a
c26694  extp 0x380, #0x1
c26698  mov 0x8e4,r12
c2669c  extp 0x301, #0x1
c266a0  cmp r12,0x3df0
c266a4  jmpr cc_ULE,0xc266ac
c266a6  movb RL1,#0x1
c266a8  movb 0xcc5a,RL1
c266ac  rets
