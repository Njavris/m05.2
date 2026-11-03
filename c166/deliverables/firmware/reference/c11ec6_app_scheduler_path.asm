c11ec6: bclr 0xff10.0xb
c11ec8: diswdt
c11ecc: mov r6,0x7096
c11ed0: or r6,0x7094
c11ed4: jmpr cc_EQ,0xc11ee2
c11ed6: mov r4,0x7094
c11eda: mov r5,0x7096
c11ede: calls 0xc28c4e
c11ee2: bclr 0xff06.0x2
c11ee4: srst
c11ee8: mov r6,[r0+]
c11eea: rets
