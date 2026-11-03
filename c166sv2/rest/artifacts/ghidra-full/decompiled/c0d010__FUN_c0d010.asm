; c0d010 FUN_c0d010 size=48
c0d010  mov 0xfa20,r0
c0d014  scxt 0xfe10,#0xfa20
c0d018  push 0xfe00
c0d01a  mov 0xfe00,#0x301
c0d01e  push 0xfe04
c0d020  mov 0xfe04,#0x303
c0d024  mov r12,#0x2000
c0d028  add 0xc4c8,r12
c0d02c  mov r13,0xc4ca
c0d030  add r13,#0x100
c0d034  mov 0xc4ca,r13
c0d038  pop 0xfe04
c0d03a  pop 0xfe00
c0d03c  pop 0xfe10
c0d03e  reti
