; c28dbe fp_to_int size=50
c28dba  mov r4,#0x0
c28dbc  jmpr cc_UC,0xc28de4
c28dbe  mov [-r0],r7
c28dc0  mov [-r0],r8
c28dc2  mov [-r0],r9
c28dc4  calls 0xc28ed2
c28dc8  jb r4.0x0,0xc28dba
c28dcc  cmp r1,#0x3ff
c28dd0  jmpr cc_C,0xc28dba
c28dd2  shl r7,#0xb
c28dd4  shr r8,#0x5
c28dd6  or r7,r8
c28dd8  sub r1,#0x40e
c28ddc  jmpr cc_UGT,0xc28dbc
c28dde  neg r1
c28de0  shr r7,r1
c28de2  mov r4,r7
c28de4  mov r9,[r0+]
c28de6  mov r8,[r0+]
c28de8  mov r7,[r0+]
c28dea  rets
