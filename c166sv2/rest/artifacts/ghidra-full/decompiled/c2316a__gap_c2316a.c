// c2316a gap_c2316a size=112 cc=unknown proto=undefined gap_c2316a(void)

void gap_c2316a(short param_1)

{
  if (param_1 == 0) {
    Ram00cb22 = 0;
    Ram00cb20 = 0x3fff;
    return;
  }
  if (param_1 == 0x4000) {
    Ram00cb22 = 0x4000;
    Ram00cb20 = 0x7fff;
    return;
  }
  if (param_1 == -0x8000) {
    Ram00cb22 = 0x8000;
    Ram00cb20 = 0xbfff;
    return;
  }
  if (param_1 == -0x4000) {
    Ram00cb22 = 0xc000;
    Ram00cb20 = 0xfeff;
    return;
  }
  if (param_1 == -0x100) {
    Ram00cb22 = 0;
    Ram00cb20 = 0xffff;
    return;
  }
  Ram00cb22 = param_1;
  Ram00cb20 = param_1;
  return;
}

