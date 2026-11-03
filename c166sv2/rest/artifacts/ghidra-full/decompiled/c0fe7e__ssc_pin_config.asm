; c0fe7e ssc_pin_config size=48
c0fe7e  calls 0xc0feae
c0fe82  mov r12,0xc482
c0fe86  mov r13,[r12]
c0fe88  and r13,#0xf0ff
c0fe8c  mov [r12],r13
c0fe8e  mov r12,0xc482
c0fe92  mov r13,[r12]
c0fe94  bset r13.0xa
c0fe96  mov [r12],r13
c0fe98  mov r12,0xc488
c0fe9c  mov r13,[r12]
c0fe9e  bset r13.0xa
c0fea0  mov [r12],r13
c0fea2  mov r12,0xc490
c0fea6  mov r13,[r12]
c0fea8  bclr r13.0x7
c0feaa  mov [r12],r13
c0feac  rets
