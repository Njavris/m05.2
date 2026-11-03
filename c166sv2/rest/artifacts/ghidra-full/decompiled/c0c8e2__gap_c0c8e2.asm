; c0c8e2 gap_c0c8e2 size=50
c0c8e2  mov r12,#0xc282
c0c8e6  movbz r13,0xc256
c0c8ea  shl r13,#0x1
c0c8ec  add r12,r13
c0c8ee  mov r13,[r12]
c0c8f0  and r13,#0xfffe
c0c8f4  mov [r12],r13
c0c8f6  movb 0xc2b2,0xff1c
c0c8fa  bclr 0xff66.0x6
c0c8fc  mov 0xfe46,#0x0
c0c900  bclr 0xff66.0x7
c0c902  extr #0x1
c0c904  bset 0xf170.0x6
c0c906  bclr 0xfd00.0xd
c0c908  mov r12,#0x1
c0c90a  or 0xc2aa,r12
c0c90e  calls 0xc0d70a
c0c912  rets
