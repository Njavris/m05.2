; c01ad4 can_bootloader_wait size=78
c01ad4  sub r0,#0x8
c01ad8  calls 0xc019d6
c01adc  mov r12,#0x2000
c01ae0  mov r13,#0xc0
c01ae4  mov [r0],r12
c01ae6  mov [r0+#0x2],r13
c01aea  mov r14,#0x4
c01aec  mov [-r0],r14
c01aee  mov r15,#0x6
c01af0  add r15,r0
c01af2  mov r4,r15
c01af4  calls 0xc01eea
c01af8  mov r12,r4
c01afa  mov r13,r5
c01afc  mov r15,#0x2
c01afe  add r15,r0
c01b00  mov r4,r15
c01b02  calls 0xc01eea
c01b06  mov r14,r4
c01b08  mov r15,r5
c01b0a  calls 0xc01d9a
c01b0e  add r0,#0x2
c01b10  srvwdt
c01b14  mov r4,[r0+#0x4]
c01b18  mov r5,[r0+#0x6]
c01b1c  calls 0xc01ec8
c01b20  jmpr cc_UC,0xc01b20
