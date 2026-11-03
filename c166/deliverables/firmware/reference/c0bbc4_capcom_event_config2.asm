c0bbc4: mov r1,r12
c0bbc6: bclr 0xff10.0xb
c0bbc8: movbz r12,RL1
c0bbca: mov r2,r12
c0bbcc: shl r12,#0x3
c0bbce: add r12,r2
c0bbd0: shl r12,#0x1
c0bbd2: mov r1,r1
c0bbd4: mov [r12+#0xc412],r13
c0bbd8: mov [r12+#0xc414],r14
c0bbdc: mov [r12+#0xc410],r15
c0bbe0: mov 0xc40c,[r0]
c0bbe4: mov r12,[r0+#0x2]
c0bbe8: mov 0xc400,r12
c0bbec: movbz r12,RL1
c0bbee: calls 0xc0dc8a
c0bbf2: bset 0xff10.0xb
c0bbf4: rets
