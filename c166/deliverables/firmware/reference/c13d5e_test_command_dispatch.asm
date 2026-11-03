c13d5e: movbz r12,0xfd18
c13d62: and r12,#0xff7f
c13d66: jmpr cc_NE,0xc13d72
c13d68: mov 0xc5e8,0xff1c
c13d6c: mov 0xc5ea,0xff1c
c13d70: rets
c13d72: mov r12,0xc5e8
c13d76: mov r13,0xc5ea
c13d7a: sub r12,#0x3e8
c13d7e: subc r13,#0x0
c13d80: jmpr cc_NC,0xc13dbe
c13d82: sub 0xc5e8,0xff1e
c13d86: subc 0xc5ea,0xff1e
c13d8a: mov r12,0xfd18
c13d8e: jnb r12.0x0,0xc13d98
c13d92: calls 0xc0fb36
c13d96: rets
c13d98: mov r12,0xfd18
c13d9c: jnb r12.0x1,0xc13da6
c13da0: calls 0xc0d6f0
c13da4: rets
c13da6: mov r12,0xfd18
c13daa: jnb r12.0x2,0xc13dc6
c13dae: calls 0xc10afc
c13db2: mov r12,#0xfa
c13db6: mov r13,#0x0
c13db8: calls 0xc10a74
c13dbc: rets
c13dbe: movb RL1,#0x80
c13dc2: andb 0xfd18,RL1
c13dc6: rets
