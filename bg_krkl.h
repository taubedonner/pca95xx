/**
 * This is a small board specific library that
 * controls an LED bargraph and two RGB LEDs
 * connected to PCA9538 I2C register.
 * 
 */

#ifndef BG_KRKL_H_
#define BG_KRKL_H_

#include <Arduino.h>

// Bars from 0 to 7
// Default address for 1st PCA9538 (Ax = 0b11)
#define KRKL_SA0 0x73

// Bars from 8 to 9 & RGB LEDs
// Default address for 2nd PCA9538 (Ax = 0b00)
#define KRKL_SA1 0x70

#if defined(ARDUINO_AVR_UNO)
#define KRKL_PIN_RESET 9
#elif defined(ENERGIA_MSP_EXP432P401R)
#define KRKL_PIN_RESET 17
#else
#define KRKL_PIN_RESET -1
#endif

#define KRKL_BIT_R 0x01u
#define KRKL_BIT_G 0x02u
#define KRKL_BIT_B 0x04u
#define KRKL_MASK_RGB1 0x1Cu
#define KRKL_MASK_RGB2 0xE0u
#define KRKL_MASK_BARGRAPH 0x03FFu
#define KRKL_OFFSET_RGB1 0x2u
#define KRKL_OFFSET_RGB2 0x5u

class BG_KRKL
{
    public:
    // SA0 = 0x73, SA1 = 0x70, RESET = KRKL_PIN_RESET
    BG_KRKL();

    // sa0 - 1st register slave address
    // sa1 - 2nd register slave address
    // resetPin - digital pin of reset signal (if -1, then it will not be used)
    BG_KRKL(uint8_t sa0, uint8_t sa1, int8_t resetPin = KRKL_PIN_RESET);

    // Initial configuration for register pins
    void init();

    // Display level on graph. From 0 to 10
    void bargraph(uint8_t level);

    // Change state of RGB LED 1 (VL-4 on board)
    // Set with KRKL_BIT_x bits (eg. KRKL_BIT_R | KRKL_BIT_G)
    void rgb1(uint8_t rgb);

    // Change state of RGB LED 2 (VL-3 on board)
    // Set with KRKL_BIT_x bits (eg. KRKL_BIT_R | KRKL_BIT_G)
    void rgb2(uint8_t rgb);

    private:
    uint8_t sa0 = 0u;
    uint8_t sa1 = 0u;
    int8_t resetPin = -1;
    uint16_t regBuffer = 0u;

    void rgbCommon(uint8_t rgb, uint8_t offset, uint8_t mask);
    
};

#endif // BARGRAPH_KRKL_H_
