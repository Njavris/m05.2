; c10d8e FUN_c10d8e size=112
c10d8e  mov [-r0],r9
c10d90  mov [-r0],r8
c10d92  mov [-r0],r7
c10d94  mov [-r0],r6
c10d96  mov r14,#0xaa
c10d9a  mov r15,#0xc0
c10d9e  mov r8,#0x54
c10da2  mov r9,#0xc0
c10da6  mov r6,r12
c10da8  mov r7,r13
c10daa  mov [-r0],r15
c10dac  mov [-r0],r14
c10dae  calls 0xc10cf2
c10db2  mov r14,[r0+]
c10db4  mov r15,[r0+]
c10db6  mov r12,#0x0
c10db8  bmov r12.0x0,0xff10.0xb
c10dbc  bclr 0xff10.0xb
c10dbe  mov r13,#0x80
c10dc2  exts r15, #0x1
c10dc4  mov [r14],r13
c10dc6  mov r14,#0xaa
c10dca  exts r9, #0x1
c10dcc  mov [r8],r14
c10dce  mov r8,#0x3
c10dd0  exts r7, #0x1
c10dd2  mov [r6],r8
c10dd4  mov r9,r12
c10dd6  calls 0xc10d00
c10dda  mov r12,r9
c10ddc  cmp r12,#0x1
c10dde  jmpa cc_NE,0xc10de8
c10de2  bset 0xff10.0xb
c10de4  jmpa cc_UC,0xc10df0
c10de8  cmp r12,#0x0
c10dea  jmpa cc_NE,0xc10df0
c10dee  bclr 0xff10.0xb
c10df0  calls 0xc10d18
c10df4  mov r6,[r0+]
c10df6  mov r7,[r0+]
c10df8  mov r8,[r0+]
c10dfa  mov r9,[r0+]
c10dfc  rets
