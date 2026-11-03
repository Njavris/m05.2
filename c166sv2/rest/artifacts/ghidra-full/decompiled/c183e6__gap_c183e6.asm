; c183e6 gap_c183e6 size=50
c183e6  extp 0x301, #0x1
c183ea  mov r12,0x1c22
c183ee  mov 0xc7dc,r12
c183f2  movb RL1,0xc820
c183f6  jmpr cc_NE,0xc183fe
c183f8  movb RL2,0xc81e
c183fc  jmpr cc_EQ,0xc1840e
c183fe  mov r12,#0x8000
c18402  mov 0xc822,r12
c18406  movb RL1,#0x1
c18408  movb 0xc824,RL1
c1840c  rets
c1840e  mov 0xc822,0xff1c
c18412  movb 0xc824,0xff1c
c18416  rets
