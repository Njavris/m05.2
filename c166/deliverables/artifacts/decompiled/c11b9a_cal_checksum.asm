c11b9a: mov r12,#0x5000
c11b9e: mov r13,#0xc0
c11ba2: mov 0xc546,0xff1c
c11ba6: mov 0xc548,0xff1c
c11baa: jmpr cc_UC,0xc11bcc
c11bac: exts r13, #0x1
c11bae: mov r14,[r12]
c11bb0: and r14,#0xff
c11bb4: shl r14,#0x8
c11bb6: add 0xc546,r14
c11bba: exts r13, #0x1
c11bbc: mov r14,[r12]
c11bbe: and r14,#0xff00
c11bc2: shr r14,#0x8
c11bc4: add 0xc546,r14
c11bc8: add r12,#0x2
c11bca: addc r13,#0x0
c11bcc: mov r14,r12
c11bce: mov r15,r13
c11bd0: mov r1,#0xaffd
c11bd4: mov r2,#0xc0
c11bd8: sub r14,r1
c11bda: subc r15,r2
c11bdc: jmpr cc_C,0xc11bac
c11bde: extp 0x302, #0x1
c11be2: mov r12,0x2ffe
c11be6: cmp r12,0xc546
c11bea: jmpr cc_NE,0xc11bf2
c11bec: mov r13,#0x1
c11bee: mov 0xc548,r13
c11bf2: rets
