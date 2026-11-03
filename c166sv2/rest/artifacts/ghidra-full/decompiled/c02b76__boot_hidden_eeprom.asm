; c02b76 boot_hidden_eeprom size=36
c02b76  extp 0x3ff, #0x1
c02b7a  mov r12,0x3000
c02b7e  jmpr cc_UC,0xc02b8c
c02b80  extp 0x3ff, #0x1
c02b84  mov r12,0x3000
c02b88  srvwdt
c02b8c  jb r12.0x0,0xc02b80
c02b90  extp 0x3ff, #0x1
c02b94  mov r4,0x3000
c02b98  rets
