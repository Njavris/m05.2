; c17574 gap_c17574 size=242
c17574  mov [-r0],r7
c17576  mov [-r0],r6
c17578  extp 0x301, #0x1
c1757c  mov r12,0x2314
c17580  extp 0x380, #0x1
c17584  cmp r12,0x82a
c17588  jmpr cc_SGT,0xc175a0
c1758a  extp 0x380, #0x1
c1758e  mov r6,0x82a
c17592  extp 0x301, #0x1
c17596  cmp r6,0x2316
c1759a  jmpr cc_SGT,0xc175a0
c1759c  movb RL6,#0x1
c1759e  jmpr cc_UC,0xc175a2
c175a0  movb RL6,#0x0
c175a2  movb RL7,RL6
c175a4  movb RL6,#0x0
c175a6  mov r12,0xc8a0
c175aa  extp 0x301, #0x1
c175ae  cmp r12,0x234e
c175b2  jmpr cc_NC,0xc1760a
c175b4  movb RL2,#0xb
c175b6  movb RL1,#0x0
c175b8  jmpr cc_UC,0xc17606
c175ba  mov r14,#0x631e
c175be  mov r15,#0xc0
c175c2  movbs r12,RL1
c175c4  shl r12,#0x1
c175c6  mov r13,#0x0
c175c8  add r14,r12
c175ca  addc r15,r13
c175cc  exts r15, #0x1
c175ce  mov r14,[r14]
c175d0  cmp r14,0xc8a0
c175d4  jmpr cc_UGT,0xc17604
c175d6  mov r14,#0x6336
c175da  mov r15,#0xc0
c175de  add r14,r12
c175e0  addc r15,r13
c175e2  exts r15, #0x1
c175e4  mov r14,[r14]
c175e6  cmp r14,0xc8a0
c175ea  jmpr cc_ULE,0xc17604
c175ec  mov r14,#0x6350
c175f0  mov r15,#0xc0
c175f4  add r14,r12
c175f6  addc r15,r13
c175f8  exts r15, #0x1
c175fa  mov r12,[r14]
c175fc  cmp r12,0xc9d0
c17600  jmpr cc_C,0xc17604
c17602  movb RL6,#0x1
c17604  addb RL1,#0x1
c17606  cmpb RL1,RL2
c17608  jmpr cc_SLE,0xc175ba
c1760a  extp 0x301, #0x1
c1760e  mov r12,0x2318
c17612  cmp r12,0xc952
c17616  jmpr cc_SGT,0xc1762a
c17618  mov r12,0xc952
c1761c  extp 0x301, #0x1
c17620  cmp r12,0x231a
c17624  jmpr cc_SGT,0xc1762a
c17626  movb RL2,#0x1
c17628  jmpr cc_UC,0xc1762c
c1762a  movb RL2,#0x0
c1762c  movb RL1,RL2
c1762e  mov r12,r1
c17630  extp 0x301, #0x1
c17634  movb RL1,0x2312
c17638  jmpr cc_EQ,0xc1765a
c1763a  cmpb RL7,#0x0
c1763c  jmpr cc_EQ,0xc1765a
c1763e  cmpb RL6,#0x0
c17640  jmpr cc_EQ,0xc1765a
c17642  mov r6,0xc06a
c17646  extp 0x301, #0x1
c1764a  cmp r6,0x231c
c1764e  jmpr cc_ULE,0xc1765a
c17650  mov r1,r12
c17652  cmpb RL1,#0x0
c17654  jmpr cc_EQ,0xc1765a
c17656  movb RL6,#0x1
c17658  jmpr cc_UC,0xc1765c
c1765a  movb RL6,#0x0
c1765c  movb 0xc78e,RL6
c17660  mov r6,[r0+]
c17662  mov r7,[r0+]
c17664  rets
