; c03de2 boot_hidden_store32 size=22
c03de2  mov r5,r4
c03de4  shr r5,#0xe
c03de6  shl r5,#0x1
c03de8  mov r5,[r5+#0xfe00]
c03dec  bmov r4.0xe,r5.0x0
c03df0  bmov r4.0xf,r5.0x1
c03df4  shr r5,#0x2
c03df6  rets
