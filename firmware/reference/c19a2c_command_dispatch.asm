c19a2c: mov r1,r12
c19a2e: cmpb RL1,#0x6
c19a30: jmpr cc_UGT,0xc19a66
c19a32: movbz r12,RL1
c19a34: shl r12,#0x1
c19a36: add r12,#0x7666
c19a3a: mov r12,[r12]
c19a3c: jmpi cc_UC,[r12]
c19a66: rets
