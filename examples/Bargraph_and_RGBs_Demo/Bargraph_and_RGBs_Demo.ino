#include <Wire.h>
#include <bargraph_krkl.h>

// SPECIFIC I2C SLAVE ADDRESS
#define KRKL_BARGRAPH_CSA1 0x22
#define KRKL_BARGRAPH_CSA0 0x21

int cnt = -2; // Out of bounds check 1

void setup() {
  Wire.begin();
  //bargraph_krkl_init();
  bargraph_krkl_init(KRKL_BARGRAPH_CSA0, KRKL_BARGRAPH_CSA1);
  bargraph_krkl_rgb1_out(KRKL_BIT_R | KRKL_BIT_G);
  bargraph_krkl_rgb2_out(KRKL_BIT_R | KRKL_BIT_B);
}

void loop() {
  if (cnt >= 11) cnt = 0; // Out of bounds check 2
  bargraph_krkl_out(cnt++);
  bargraph_krkl_rgb1_out(KRKL_BIT_B);
  delay(500);
  bargraph_krkl_out(cnt++);
  bargraph_krkl_rgb2_out(KRKL_BIT_R | KRKL_BIT_G);
  delay(500);
  bargraph_krkl_out(cnt++);
  bargraph_krkl_rgb1_out(KRKL_BIT_G);
  bargraph_krkl_rgb2_out(KRKL_BIT_B);
  delay(500);
}
