; c1477a gap_c1477a size=52
c1477a  mov [-r0],r8
c1477c  mov r12,#0x1
c1477e  calls 0xc19a2c
c14782  mov r12,#0x0
c14784  calls 0xc1168a
c14788  mov r8,r4
c1478a  mov r12,#0x1
c1478c  calls 0xc1168a
c14790  mov r12,r4
c14792  mov [-r0],r12
c14794  cmp r8,#0x0
c14796  jmpr cc_EQ,0xc147a0
c14798  mov r12,[r0]
c1479a  jmpr cc_EQ,0xc147a0
c1479c  mov r8,#0x1
c1479e  jmpr cc_UC,0xc147a2
c147a0  mov r8,#0x0
c147a2  mov r12,r8
c147a4  add r0,#0x2
c147a6  calls 0xc14712
c147aa  mov r8,[r0+]
c147ac  rets
