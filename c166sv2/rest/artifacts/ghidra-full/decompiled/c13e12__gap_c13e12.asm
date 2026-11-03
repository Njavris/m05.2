; c13e12 gap_c13e12 size=54
c13e12  extp 0x301, #0x1
c13e16  mov r8,0x1068
c13e1a  cmp r8,#0x4
c13e1c  jmpr cc_NE,0xc13e2a
c13e1e  mov r12,#0x1
c13e20  mov r13,#0x0
c13e22  calls 0xc146de
c13e26  mov r8,r4
c13e28  jmpr cc_UC,0xc13e8e
c13e2a  mov r12,#0x0
c13e2c  calls 0xc10398
c13e30  mov r8,r4
c13e32  extp 0x301, #0x1
c13e36  movb RL1,0x1081
c13e3a  cmpb RL1,#0x2
c13e3c  jmpr cc_NE,0xc13e8e
c13e3e  mov r12,#0x7
c13e40  mov r13,r8
c13e42  calls 0xc14cde
c13e46  jmpr cc_UC,0xc13e8e
