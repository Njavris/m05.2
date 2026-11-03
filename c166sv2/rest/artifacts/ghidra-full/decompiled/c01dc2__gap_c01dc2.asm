; c01dc2 gap_c01dc2 size=42
c01dc2  mov r12,#0x450
c01dc6  mov r13,#0x80
c01dca  extp r13, #0x1
c01dcc  mov r14,[r12]
c01dce  bfldh r14,#0x3,#0x1
c01dd2  extp r13, #0x1
c01dd4  mov [r12],r14
c01dd6  mov r12,#0x430
c01dda  mov r13,#0x80
c01dde  extp r13, #0x1
c01de0  mov r14,[r12]
c01de2  bfldh r14,#0x3,#0x1
c01de6  extp r13, #0x1
c01de8  mov [r12],r14
c01dea  rets
