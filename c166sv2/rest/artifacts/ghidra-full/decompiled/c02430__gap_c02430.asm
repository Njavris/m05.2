; c02430 gap_c02430 size=30
c02430  calls 0xc02386
c02434  mov r12,#0xff06
c02438  mov r13,[r12]
c0243a  bfldl r13,#0x20,#0x20
c0243e  mov [r12],r13
c02440  extp 0x380, #0x2
c02444  movb RL1,0x1
c02448  movb 0x20,RL1
c0244c  rets
