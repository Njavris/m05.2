; c104f4 farcall_06 size=48
c104f4  mov 0xfc40,r0
c104f8  scxt 0xfe10,#0xfc40
c104fc  push 0xfe00
c104fe  mov 0xfe00,#0x301
c10502  push 0xfe04
c10504  mov 0xfe04,#0x303
c10508  bclr 0xff10.0xb
c1050a  diswdt
c1050e  mov r12,0xffac
c10512  or 0xfdfe,r12
c10516  bclr 0xffac.0xd
c10518  srst
c1051c  pop 0xfe04
c1051e  pop 0xfe00
c10520  pop 0xfe10
c10522  reti
