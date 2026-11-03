c108b4: movbz r12,0xc4cc
c108b8: cmp r12,#0x80
c108bc: jmpr cc_SLE,0xc108c8
c108be: mov 0xc4d2,0xff1c
c108c2: mov 0xc4d4,0xff1c
c108c6: rets
c108c8: subb 0xc4cc,0xff1e
c108cc: rets
