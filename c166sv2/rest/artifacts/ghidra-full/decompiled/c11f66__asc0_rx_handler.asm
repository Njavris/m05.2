; c11f66 asc0_rx_handler size=52
c11f66  mov 0xfce0,r0
c11f6a  scxt 0xfe10,#0xfce0
c11f6e  scxt 0xff0e,#0x10
c11f72  push 0xfe00
c11f74  mov 0xfe00,#0x301
c11f78  push 0xfe04
c11f7a  mov 0xfe04,#0x303
c11f7e  push 0xfe0c
c11f80  push 0xfe0e
c11f82  calls 0xc11f60
c11f86  movbz r12,RL4
c11f88  calls 0xc1293c
c11f8c  pop 0xfe0e
c11f8e  pop 0xfe0c
c11f90  pop 0xfe04
c11f92  pop 0xfe00
c11f94  pop 0xff0e
c11f96  pop 0xfe10
c11f98  reti
