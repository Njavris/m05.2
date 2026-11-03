; c10d18 FUN_c10d18 size=24
c10d18  mov r12,#0x0
c10d1a  mov r13,0xf000
c10d1e  jnb r13.0x6,0xc10d26
c10d22  mov r12,#0x40
c10d26  jnb r13.0x7,0xc10d2c
c10d2a  bset r12.0x7
c10d2c  mov r4,r12
c10d2e  rets
