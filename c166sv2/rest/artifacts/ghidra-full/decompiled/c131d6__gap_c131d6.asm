; c131d6 gap_c131d6 size=278
c131d6  movbz r12,0xc5c4
c131da  movb RL1,[r12+#0xf63e]
c131de  movbz r12,0xc5c7
c131e2  movb 0xc5c8,RL1
c131e6  movb [r12+#0xf63e],RL1
c131ea  movb 0xc5c0,0xff1c
c131ee  movb 0xc5c5,0xff1c
c131f2  movb RL1,0xc578
c131f6  cmpb RL1,#0x3
c131f8  jmpr cc_EQ,0xc131fe
c131fa  cmpb RL1,#0x2
c131fc  jmpr cc_NE,0xc132e2
c131fe  movb RL1,0xc578
c13202  cmpb RL1,#0x2
c13204  jmpr cc_NE,0xc1326e
c13206  movb RL2,0xc5c8
c1320a  cmpb RL2,#0x81
c1320e  jmpr cc_EQ,0xc13218
c13210  cmpb RL2,#0x85
c13214  jmpr cc_EQ,0xc1323a
c13216  jmpr cc_UC,0xc132e2
c13218  calls 0xc131be
c1321c  cmpb RL4,#0x0
c1321e  jmpr cc_EQ,0xc13228
c13220  movb RL1,#0x1
c13222  movb 0xc5ab,RL1
c13226  jmpr cc_UC,0xc13232
c13228  movb RL1,#0x1
c1322a  movb 0xc5c0,RL1
c1322e  mov 0xc5c2,0xff1c
c13232  mov r12,#0x2
c13234  calls 0xc12910
c13238  rets
c1323a  calls 0xc125e6
c1323e  cmpb RL4,#0x0
c13240  jmpr cc_NE,0xc13248
c13242  calls 0xc12688
c13246  rets
c13248  calls 0xc131ce
c1324c  calls 0xc12690
c13250  bset 0xfd14.0xd
c13252  mov r12,#0x2
c13254  calls 0xc12910
c13258  mov r10,#0x8625
c1325c  mov r11,#0x6450
c13260  mov r4,#0x7fc
c13264  mov r5,#0xe0
c13268  calls 0xc28c62
c1326c  rets
c1326e  movb RL1,0xc5c8
c13272  cmpb RL1,#0x85
c13276  jmpr cc_NE,0xc132e2
c13278  calls 0xc125e6
c1327c  cmpb RL4,#0x0
c1327e  jmpr cc_NE,0xc13298
c13280  calls 0xc12688
c13284  movbz r12,0xc5c4
c13288  movb RL2,#0x1
c1328a  movb RL1,[r12+#0xf63f]
c1328e  movb 0xc5c9,RL1
c13292  movb 0xc5c5,RL2
c13296  rets
c13298  calls 0xc131ce
c1329c  calls 0xc12690
c132a0  movbz r12,0xc5c4
c132a4  movb RL1,[r12+#0xf63f]
c132a8  movbz r12,0xc5c7
c132ac  movb 0xc5c9,RL1
c132b0  movb [r12+#0xf63f],RL1
c132b4  movb RL1,0xc5c9
c132b8  cmpb RL1,#0x3
c132ba  jmpr cc_NE,0xc132d8
c132bc  mov r12,#0x3
c132be  calls 0xc12910
c132c2  mov r10,#0x6450
c132c6  mov r11,#0x8633
c132ca  mov r4,#0x7fc
c132ce  mov r5,#0xe0
c132d2  calls 0xc28c62
c132d6  rets
c132d8  mov r12,#0x31
c132dc  calls 0xc128ec
c132e0  rets
c132e2  mov r12,#0x12
c132e6  calls 0xc128ec
c132ea  rets
