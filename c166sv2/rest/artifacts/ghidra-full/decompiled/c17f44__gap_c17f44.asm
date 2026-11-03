; c17f44 gap_c17f44 size=280
c17f44  mov r12,0xc818
c17f48  cmp r12,#0x1
c17f4a  jmpr cc_EQ,0xc17f70
c17f4c  mov r12,#0x7534
c17f50  mov r13,0xc936
c17f54  calls 0xc284d8
c17f58  mov r14,r4
c17f5a  mov r12,#0x5d9c
c17f5e  mov r13,#0xc0
c17f62  calls 0xc27ca4
c17f66  mov 0xc814,r4
c17f6a  mov 0xc810,0xff1c
c17f6e  jmpr cc_UC,0xc17fb6
c17f70  mov r12,#0x5252
c17f74  mov r13,#0xc0
c17f78  mov r14,0xc9d0
c17f7c  calls 0xc28544
c17f80  mov r14,r4
c17f82  mov r12,#0x5db0
c17f86  mov r13,#0xc0
c17f8a  calls 0xc27ca4
c17f8e  mov 0xc814,r4
c17f92  mov r12,#0x7534
c17f96  mov r13,0xc936
c17f9a  calls 0xc284d8
c17f9e  mov r14,r4
c17fa0  mov r12,#0x7cdc
c17fa4  mov r13,#0xc0
c17fa8  calls 0xc27ca4
c17fac  mov 0xc810,r4
c17fb0  movb RL1,#0x1
c17fb2  movb 0xc7c1,RL1
c17fb6  mov r12,0xc814
c17fba  cmp r12,0xc80c
c17fbe  jmpr cc_ULE,0xc17ff6
c17fc0  mov r13,0xc80c
c17fc4  calls 0xc28852
c17fc8  extp 0x301, #0x1
c17fcc  cmp r4,0x1c4c
c17fd0  jmpr cc_ULE,0xc1803e
c17fd2  mov r12,0xc7c6
c17fd6  extp 0x301, #0x1
c17fda  cmp r12,0x1c4e
c17fde  jmpr cc_C,0xc1804a
c17fe0  mov r12,0xc80c
c17fe4  extp 0x301, #0x1
c17fe8  mov r13,0x1c4c
c17fec  calls 0xc276a4
c17ff0  mov 0xc80c,r4
c17ff4  jmpr cc_UC,0xc18038
c17ff6  mov r12,0xc814
c17ffa  cmp r12,0xc80c
c17ffe  jmpr cc_NC,0xc1804a
c18000  mov r12,0xc80c
c18004  mov r13,0xc814
c18008  calls 0xc28852
c1800c  extp 0x301, #0x1
c18010  cmp r4,0x1c4c
c18014  jmpr cc_ULE,0xc1803e
c18016  mov r12,0xc7c6
c1801a  extp 0x301, #0x1
c1801e  cmp r12,0x1c4e
c18022  jmpr cc_C,0xc1804a
c18024  mov r12,0xc80c
c18028  extp 0x301, #0x1
c1802c  mov r13,0x1c4c
c18030  calls 0xc28852
c18034  mov 0xc80c,r4
c18038  mov 0xc7c6,0xff1c
c1803c  jmpr cc_UC,0xc1804a
c1803e  mov r12,0xc814
c18042  mov 0xc80c,r12
c18046  movb 0xc7c1,0xff1c
c1804a  mov r12,0xc80c
c1804e  calls 0xc1c2b8
c18052  mov r12,0xc810
c18056  calls 0xc1c2be
c1805a  rets
