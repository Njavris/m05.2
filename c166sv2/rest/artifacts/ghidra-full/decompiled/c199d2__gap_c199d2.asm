; c199d2 gap_c199d2 size=28
c199d2  calls 0xc19ab2
c199d6  calls 0xc19ae6
c199da  movb RL1,0xc898
c199de  cmpb RL1,#0x7
c199e0  jmpr cc_UGT,0xc19a0a
c199e2  movbz r12,RL1
c199e4  shl r12,#0x1
c199e6  add r12,#0x7656
c199ea  mov r12,[r12]
c199ec  jmpi cc_UC,[r12]
