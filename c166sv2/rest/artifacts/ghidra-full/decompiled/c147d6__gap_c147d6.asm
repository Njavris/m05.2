; c147d6 gap_c147d6 size=78
c147d6  mov r12,#0xc282
c147da  movbz r13,0xc256
c147de  shl r13,#0x1
c147e0  add r12,r13
c147e2  mov r13,[r12]
c147e4  and r13,#0xbfff
c147e8  mov [r12],r13
c147ea  mov r12,#0x6
c147ec  calls 0xc19a2c
c147f0  calls 0xc0e4e6
c147f4  movb RL1,0xc92f
c147f8  jmpr cc_NE,0xc14822
c147fa  mov r12,#0xd70a
c147fe  mov r13,#0xc0
c14802  mov 0xc208,r12
c14806  mov 0xc20a,r13
c1480a  extp 0x301, #0x1
c1480e  movb RL2,0x1036
c14812  cmpb RL2,#0x2
c14814  jmpr cc_EQ,0xc1481a
c14816  cmpb RL2,#0x3
c14818  jmpr cc_NE,0xc14822
c1481a  mov r12,#0x8000
c1481e  or 0xc288,r12
c14822  rets
