; c12c92 gap_c12c92 size=18
c12c92  movb RL1,0xc5a1
c12c96  movb RL2,[r0]
c12c98  subb RL1,RL2
c12c9a  cmpb RL1,RL2
c12c9c  jmpr cc_EQ,0xc12ca4
c12c9e  calls 0xc126d2
c12ca2  jmpr cc_UC,0xc12cb0
