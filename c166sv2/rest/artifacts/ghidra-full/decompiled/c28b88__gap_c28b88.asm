; c28b88 gap_c28b88 size=42
c28b88  mov [-r0],r1
c28b8a  mov r1,r5
c28b8c  jmpr cc_NN,0xc28b94
c28b8e  neg r5
c28b90  neg r4
c28b92  subc r5,#0x0
c28b94  jnb r11.0xf,0xc28ba0
c28b98  cpl r1
c28b9a  neg r11
c28b9c  neg r10
c28b9e  subc r11,#0x0
c28ba0  calls 0xc28bb2
c28ba4  jnb r1.0xf,0xc28bae
c28ba8  neg r5
c28baa  neg r4
c28bac  subc r5,#0x0
c28bae  mov r1,[r0+]
c28bb0  rets
