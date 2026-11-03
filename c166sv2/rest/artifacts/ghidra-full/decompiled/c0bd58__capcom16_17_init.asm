; c0bd58 capcom16_17_init size=70
c0bd58  bset 0xff18.0x0
c0bd5a  bset 0xff18.0x1
c0bd5c  movb RL1,#0x10
c0bd60  movb 0xc390,RL1
c0bd64  mov r12,#0xfe60
c0bd68  mov 0xc392,r12
c0bd6c  mov r13,#0xff22
c0bd70  mov 0xc394,r13
c0bd74  mov r14,#0xf160
c0bd78  mov 0xc396,r14
c0bd7c  movb RL2,#0x11
c0bd80  movb 0xc398,RL2
c0bd84  mov r15,#0xfe62
c0bd88  mov 0xc39a,r15
c0bd8c  mov r3,#0xff22
c0bd90  mov 0xc39c,r3
c0bd94  mov r4,#0xf162
c0bd98  mov 0xc39e,r4
c0bd9c  rets
