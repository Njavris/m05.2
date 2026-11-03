; c0d528 event_init size=58
c0d528  mov [-r0],r6
c0d52a  bclr 0xff10.0xb
c0d52c  calls 0xc0bd58
c0d530  movb RL6,#0x0
c0d532  movbz r13,RL6
c0d534  shl r13,#0x3
c0d536  mov r14,#0x1
c0d538  movbz r12,RL6
c0d53a  movb RL1,[r13+#0xc390]
c0d53e  movbz r13,RL1
c0d540  calls 0xc0bca4
c0d544  addb RL6,#0x1
c0d546  cmpb RL6,#0x2
c0d548  jmpr cc_C,0xc0d532
c0d54a  movb 0xc370,0xff1c
c0d54e  mov r6,0xc372
c0d552  jmpr cc_NE,0xc0d558
c0d554  calls 0xc0d39e
c0d558  calls 0xc0d516
c0d55c  bset 0xff10.0xb
c0d55e  mov r6,[r0+]
c0d560  rets
