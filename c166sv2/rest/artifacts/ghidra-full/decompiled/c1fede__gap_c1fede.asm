; c1fede gap_c1fede size=76
c1fede  movb RL1,0xc93c
c1fee2  cmpb RL1,#0x3
c1fee4  jmpr cc_NE,0xc1ff22
c1fee6  mov r12,0xca2a
c1feea  extp 0x301, #0x1
c1feee  cmp r12,0x39d6
c1fef2  jmpr cc_UGT,0xc1fefa
c1fef4  movb 0xca86,0xff1c
c1fef8  rets
c1fefa  mov r12,0xca2a
c1fefe  extp 0x301, #0x1
c1ff02  cmp r12,0x39d6
c1ff06  jmpr cc_ULE,0xc1ff1a
c1ff08  extp 0x301, #0x1
c1ff0c  cmp r12,0x39d8
c1ff10  jmpr cc_UGT,0xc1ff1a
c1ff12  movb RL1,#0x1
c1ff14  movb 0xca86,RL1
c1ff18  rets
c1ff1a  movb RL1,#0x2
c1ff1c  movb 0xca86,RL1
c1ff20  rets
c1ff22  movb RL1,#0x3
c1ff24  movb 0xca86,RL1
c1ff28  rets
