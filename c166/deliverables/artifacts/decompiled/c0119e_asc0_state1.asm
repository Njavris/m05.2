c0119e: jb 0xffc4.0xb,0xc011a8
c011a2: sub 0xc0b0,0xff1e
c011a6: rets
c011a8: mov r12,0xc0b0
c011ac: cmp r12,#0x14
c011b0: jmpr cc_ULE,0xc011d0
c011b2: cmp r12,#0x1c
c011b6: jmpr cc_NC,0xc011d0
c011b8: movb RL1,#0x2
c011ba: mov r13,#0xf0c6
c011be: movb 0xc0af,RL1
c011c2: movb 0xc0ae,0xff1c
c011c6: mov r14,[r13]
c011c8: bfldl r14,#0x2,#0x2
c011cc: mov [r13],r14
c011ce: bset 0xffb0.0x4
c011d0: mov 0xc0b0,0xff1c
c011d4: rets
