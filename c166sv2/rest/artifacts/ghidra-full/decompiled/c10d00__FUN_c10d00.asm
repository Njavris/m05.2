; c10d00 FUN_c10d00 size=24
c10d00  mov r13,#0xf000
c10d04  mov r12,#0x0
c10d06  srvwdt
c10d0a  mov r14,[r13]
c10d0c  jnb r14.0x0,0xc10d14
c10d10  cmp r12,#0x0
c10d12  jmpr cc_EQ,0xc10d0a
c10d14  mov r4,r12
c10d16  rets
