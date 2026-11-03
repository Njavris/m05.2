c01144: movb RL1,0xc0af
c01148: cmpb RL1,#0x5
c0114a: jmpr cc_UGT,0xc0117c
c0114c: movbz r12,RL1
c0114e: shl r12,#0x1
c01150: add r12,#0x428
c01154: mov r12,[r12]
c01156: jmpi cc_UC,[r12]
c0117c: movb 0xc0af,0xff1c
c01180: rets
