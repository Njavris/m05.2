; c0d8fa gap_c0d8fa size=26
c0d8fa  mov r12,#0xc282
c0d8fe  movbz r13,0xc256
c0d902  shl r13,#0x1
c0d904  add r12,r13
c0d906  mov r13,[r12]
c0d908  and r13,#0xf7ff
c0d90c  mov [r12],r13
c0d90e  mov 0xc3b6,0xfe70
c0d912  rets
