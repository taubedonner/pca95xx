/**
 * This is a small board specific library that
 * controls an LED bargraph and two RGB LEDs
 * connected to PCA9538 I2C register.
 * 
 */

#ifndef BARGRAPH_KRKL_H_
#define BARGRAPH_KRKL_H_

#include <Arduino.h>

// Bars from 0 to 7
// Default address (Ax = 0b11)
#define KRKL_BARGRAPH_SA0 0x73

// Bars from 8 to 9 & RGB LEDs
// Default address (Ax = 0b00)
#define KRKL_BARGRAPH_SA1 0x70

#define KRKL_BIT_R 0x02u
#define KRKL_BIT_G 0x04u
#define KRKL_BIT_B 0x01u
#define KRKL_MASK_RGB1 0x1Cu
#define KRKL_MASK_RGB2 0xE0u
#define KRKL_MASK_BARGRAPH 0x3FFu

#define KRKL_OFFSET_RGB1 0x2u
#define KRKL_OFFSET_RGB2 0x5u

// Initialize registers with custom addresses
void bargraph_krkl_init(uint8_t sa0, uint8_t sa1);

// Initialize registers connected to LEDs
void bargraph_krkl_init();

// Display level on graph. From 0 to 10
void bargraph_krkl_out(uint8_t level);

// Change state of RGB LED 1 (VL-4)
// Set with KRKL_BIT_x bits (eg. KRKL_BIT_R | KRKL_BIT_G)
void bargraph_krkl_rgb1_out(uint8_t rgb);

// Change state of RGB LED 2 (VL-3)
// Set with KRKL_BIT_x bits (eg. KRKL_BIT_R | KRKL_BIT_G)
void bargraph_krkl_rgb2_out(uint8_t rgb);

#endif // BARGRAPH_KRKL_H_
