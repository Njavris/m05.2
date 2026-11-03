; c2316a gap_c2316a size=112
c2316a  cmp r12,#0x0
c2316c  jmpr cc_EQ,0xc23188
c2316e  cmp r12,#0x4000
c23172  jmpr cc_EQ,0xc23196
c23174  cmp r12,#0x8000
c23178  jmpr cc_EQ,0xc231a8
c2317a  cmp r12,#0xc000
c2317e  jmpr cc_EQ,0xc231ba
c23180  cmp r12,#0xff00
c23184  jmpr cc_EQ,0xc231cc
c23186  jmpr cc_UC,0xc231d6
c23188  mov 0xcb22,0xff1c
c2318c  mov r12,#0x3fff
c23190  mov 0xcb20,r12
c23194  rets
c23196  mov r12,#0x4000
c2319a  mov 0xcb22,r12
c2319e  mov r13,#0x7fff
c231a2  mov 0xcb20,r13
c231a6  rets
c231a8  mov r12,#0x8000
c231ac  mov 0xcb22,r12
c231b0  mov r13,#0xbfff
c231b4  mov 0xcb20,r13
c231b8  rets
c231ba  mov r12,#0xc000
c231be  mov 0xcb22,r12
c231c2  mov r13,#0xfeff
c231c6  mov 0xcb20,r13
c231ca  rets
c231cc  mov 0xcb22,0xff1c
c231d0  mov 0xcb20,0xff1e
c231d4  rets
c231d6  mov 0xcb22,r12
