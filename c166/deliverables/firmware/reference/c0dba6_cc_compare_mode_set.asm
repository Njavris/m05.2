c0dba6: mov r2,r12
c0dba8: movbz r12,RL2
c0dbaa: mov r13,r12
c0dbac: shl r13,#0x3
c0dbae: add r13,r12
c0dbb0: shl r13,#0x1
c0dbb2: movb RL1,[r13+#0xc41d]
c0dbb6: movb RL2,0xc40e
c0dbba: jmpa cc_EQ,0xc0dbce
c0dbbe: cmpb RL1,#0x10
c0dbc2: jmpa cc_NE,0xc0dbca
c0dbc6: bclr 0xff2c.0x0
c0dbc8: rets
c0dbca: bclr 0xff2c.0x1
c0dbcc: rets
c0dbce: cmpb RL1,#0x10
c0dbd2: jmpa cc_NE,0xc0dbda
c0dbd6: bset 0xff2c.0x0
c0dbd8: rets
c0dbda: bset 0xff2c.0x1
c0dbdc: rets
