; c11eec scheduler_tick size=24
c11eec  subb 0xc54c,0xff1e
c11ef0  movb RL1,0xc54c
c11ef4  cmpb RL1,0xc550
c11ef8  jmpr cc_ULE,0xc11efe
c11efa  movb 0xc54c,0xff1c
c11efe  calls 0xc147c6
c11f02  rets
