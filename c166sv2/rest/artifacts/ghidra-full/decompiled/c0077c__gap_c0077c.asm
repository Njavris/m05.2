; c0077c gap_c0077c size=284
c0077c  mov r2,r12
c0077e  movbz r14,RL2
c00780  shl r14,#0x5
c00782  mov r12,#0x31a
c00786  mov r15,#0x80
c0078a  add r12,r14
c0078c  extp r15, #0x2
c0078e  movb RL1,#0x2
c00790  mov r12,[r12]
c00792  and r12,#0x700
c00796  cmp r12,#0x200
c0079a  jmpr cc_NE,0xc00894
c0079c  movb RL2,0xc000
c007a0  movbz r12,RL2
c007a2  shl r12,#0x5
c007a4  mov r2,#0x310
c007a8  mov r3,#0x80
c007ac  add r2,r12
c007ae  extp r3, #0x2
c007b0  movb RL1,#0x0
c007b2  mov r15,[r2]
c007b4  and r15,#0x3000
c007b8  cmp r15,#0x1000
c007bc  jmpr cc_NE,0xc00894
c007be  mov r15,#0x318
c007c2  add r15,r14
c007c4  mov r1,#0x80
c007c8  extp r1, #0x1
c007ca  mov r14,[r15]
c007cc  and r14,#0x1f
c007d0  cpl r14
c007d2  movbz r4,0xc000
c007d6  and r4,r14
c007d8  extp r1, #0x1
c007da  mov r14,[r15]
c007dc  movbz r15,0xc000
c007e0  add r15,#0x1
c007e2  and r15,#0x1f
c007e6  and r15,r14
c007e8  or r4,r15
c007ea  movb 0xc000,RL4
c007ee  mov r14,#0xf9ff
c007f2  extp r3, #0x1
c007f4  mov [r2],r14
c007f6  mov r14,#0x314
c007fa  add r14,r12
c007fc  mov r15,#0x80
c00800  extp r15, #0x1
c00802  mov r1,[r14]
c00804  jnb r1.0x2,0xc00824
c00808  mov r1,[r13+#0x2]
c0080c  mov r5,[r13+#0x4]
c00810  mov r10,#0x308
c00814  add r10,r12
c00816  mov r11,#0x80
c0081a  extp r11, #0x2
c0081c  mov [r10+#0x2],r5
c00820  mov [r10],r1
c00822  jmpr cc_UC,0xc00844
c00824  mov r1,[r13+#0x2]
c00828  mov r4,[r13+#0x4]
c0082c  mov r4,r1
c0082e  shl r4,#0x2
c00830  mov r5,#0x308
c00834  mov r10,#0x80
c00838  add r5,r12
c0083a  extp r10, #0x3
c0083c  mov r1,#0x0
c0083e  mov [r5+#0x2],r4
c00842  mov [r5],r1
c00844  extp r15, #0x1
c00846  mov r1,[r14]
c00848  and r1,#0xf
c0084c  mov r4,[r13]
c0084e  and r4,#0xf0
c00852  or r1,r4
c00854  extp r15, #0x1
c00856  mov [r14],r1
c00858  movb RL1,#0x0
c0085a  jmpr cc_UC,0xc0087c
c0085c  mov r14,r13
c0085e  add r14,#0xa
c00862  movbz r15,RL1
c00864  add r14,r15
c00866  mov r15,#0x300
c0086a  movb RL4,[r14]
c0086c  movbz r14,RL1
c0086e  add r14,r12
c00870  add r15,r14
c00872  mov r5,#0x80
c00876  extp r5, #0x1
c00878  movb [r15],RL4
c0087a  addb RL1,#0x1
c0087c  mov r14,[r13]
c0087e  and r14,#0xf0
c00882  shr r14,#0x4
c00884  movbz r15,RL1
c00886  cmp r14,r15
c00888  jmpr cc_UGT,0xc0085c
c0088a  mov r12,#0x66bf
c0088e  extp r3, #0x1
c00890  mov [r2],r12
c00892  movb RL1,#0x1
c00894  movb RL4,RL1
c00896  rets
