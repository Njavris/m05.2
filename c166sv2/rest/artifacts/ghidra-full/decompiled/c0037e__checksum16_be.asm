; c0037e checksum16_be size=58
c0037e  mov r1,r12
c00380  mov r2,r13
c00382  mov r1,#0x0
c00384  diswdt
c00388  jmpr cc_UC,0xc003a6
c0038a  exts r13, #0x1
c0038c  mov r2,[r12]
c0038e  and r2,#0xff
c00392  shl r2,#0x8
c00394  add r1,r2
c00396  exts r13, #0x1
c00398  mov r2,[r12]
c0039a  and r2,#0xff00
c0039e  shr r2,#0x8
c003a0  add r1,r2
c003a2  add r12,#0x2
c003a4  addc r13,#0x0
c003a6  mov r2,r12
c003a8  mov r3,r13
c003aa  sub r2,r14
c003ac  subc r3,r15
c003ae  jmpr cc_C,0xc0038a
c003b0  co_mac_unknown 0x7a
c003b2  co_mac_unknown 0x85
c003b4  mov r4,r1
c003b6  rets
