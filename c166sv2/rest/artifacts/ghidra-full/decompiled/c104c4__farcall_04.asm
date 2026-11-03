; c104c4 farcall_04 size=48
c104c4  mov 0xfc40,r0
c104c8  scxt 0xfe10,#0xfc40
c104cc  push 0xfe00
c104ce  mov 0xfe00,#0x301
c104d2  push 0xfe04
c104d4  mov 0xfe04,#0x303
c104d8  bclr 0xff10.0xb
c104da  diswdt
c104de  mov r12,0xffac
c104e2  or 0xfdfe,r12
c104e6  bclr 0xffac.0xe
c104e8  srst
c104ec  pop 0xfe04
c104ee  pop 0xfe00
c104f0  pop 0xfe10
c104f2  reti
