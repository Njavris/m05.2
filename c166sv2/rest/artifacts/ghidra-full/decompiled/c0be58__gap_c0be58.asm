; c0be58 gap_c0be58 size=18
c0be58  cmp r12,#0x0
c0be5a  jmpa cc_NE,0xc0be64
c0be5e  bfldh 0xff24,#0x70,#0x50
c0be62  rets
c0be64  bfldh 0xff24,#0x7,#0x5
c0be68  rets
