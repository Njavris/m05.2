; c1823c gap_c1823c size=152
c1823c  calls 0xc18da6
c18240  movb RL1,0xc93c
c18244  cmpb RL1,#0x3
c18246  jmpr cc_NE,0xc182c6
c18248  movb RL2,0xc853
c1824c  jmpr cc_EQ,0xc1828c
c1824e  mov r12,#0x613e
c18252  mov r13,#0xc0
c18256  mov r14,0xc984
c1825a  calls 0xc27ca4
c1825e  mov r12,r4
c18260  cmp r12,0xc79c
c18264  jmpr cc_ULE,0xc1826c
c18266  movb RL1,0xc81d
c1826a  jmpr cc_EQ,0xc1827c
c1826c  movb RL1,#0x1
c1826e  movb 0xc81d,RL1
c18272  movb 0xc7ef,0xff1c
c18276  movb 0xc81c,RL1
c1827a  jmpr cc_UC,0xc18282
c1827c  movb RL1,#0x1
c1827e  movb 0xc7ef,RL1
c18282  mov 0xc7ac,0xff1c
c18286  movb 0xc7f7,0xff1c
c1828a  rets
c1828c  movb RL1,0xc852
c18290  jmpr cc_EQ,0xc182c0
c18292  mov r12,#0x61f4
c18296  mov r13,#0xc0
c1829a  mov r14,0xc984
c1829e  calls 0xc27ca4
c182a2  mov r12,r4
c182a4  cmp r12,0xc7ac
c182a8  jmpr cc_UGT,0xc182b4
c182aa  movb 0xc7f7,0xff1c
c182ae  movb 0xc81c,0xff1c
c182b2  jmpr cc_UC,0xc182ba
c182b4  movb RL1,#0x1
c182b6  movb 0xc7f7,RL1
c182ba  movb 0xc7ef,0xff1c
c182be  rets
c182c0  movb 0xc7ef,0xff1c
c182c4  rets
c182c6  mov 0xc79c,0xff1c
c182ca  movb 0xc7ef,0xff1c
c182ce  movb 0xc81c,0xff1c
c182d2  rets
