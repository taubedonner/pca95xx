#include <bg_krkl.h>

// SA0 - 0x21, SA1 = 0x22, RST not used
BG_KRKL bargraph(0x21, 0x22, -1);
//BG_KRKL bargraph;

// Out of bounds check 1
int cnt = -2;

void setup() {
  bargraph.init();
  bargraph.rgb1(KRKL_BIT_R | KRKL_BIT_G);
  bargraph.rgb2(KRKL_BIT_R | KRKL_BIT_B);
}

void loop() {
  // Out of bounds check 2
  if (cnt >= 11) cnt = 0;

  bargraph.bargraph(cnt++);
  bargraph.rgb1(KRKL_BIT_B);
  delay(500);
  
  bargraph.bargraph(cnt++);
  bargraph.rgb2(KRKL_BIT_R | KRKL_BIT_G);
  delay(500);

  bargraph.bargraph(cnt++);
  bargraph.rgb1(KRKL_BIT_G);
  bargraph.rgb2(KRKL_BIT_B);
  delay(500);
}
