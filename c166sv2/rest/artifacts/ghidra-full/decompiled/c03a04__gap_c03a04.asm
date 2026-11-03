; c03a04 gap_c03a04 size=18
c03a04  mov r12,#0xff04
c03a08  mov r13,[r12]
c03a0a  bfldl r13,#0x1,#0x1
c03a0e  mov [r12],r13
c03a10  srvwdt
c03a14  jmpr cc_UC,0xc03a14
