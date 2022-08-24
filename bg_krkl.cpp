#include "bg_krkl.h"

#include <Wire.h>
#include "pca95xx.h"

BG_KRKL::BG_KRKL()
{
    BG_KRKL(KRKL_SA0, KRKL_SA1, KRKL_PIN_RESET);
}

BG_KRKL::BG_KRKL(uint8_t sa0, uint8_t sa1, int8_t resetPin)
{
    this->sa0 = sa0;
    this->sa1 = sa1;
    this->resetPin = resetPin;
    this->regBuffer = KRKL_MASK_BARGRAPH;
}

void BG_KRKL::rgbCommon(uint8_t rgb, uint8_t offset, uint8_t mask)
{
    regBuffer &= ~(mask << 8u);
    regBuffer |= ((rgb & KRKL_BIT_R) << offset) << 8u;
    regBuffer |= ((rgb & KRKL_BIT_G) << offset) << 8u;
    regBuffer |= ((rgb & KRKL_BIT_B) << offset) << 8u;
    pca95xx_out(sa1, (uint8_t)(regBuffer >> 8u));
}

void BG_KRKL::init()
{
    pca95xx_reset(resetPin);
    Wire.begin();
    pca95xx_configure(sa0);
    pca95xx_configure(sa1);
    bargraph(0);
}

void BG_KRKL::bargraph(uint8_t level)
{
    regBuffer &= ~KRKL_MASK_BARGRAPH;
    regBuffer |= (~((1u << level) - 1u)) & KRKL_MASK_BARGRAPH;
    pca95xx_out(sa0, (uint8_t)(regBuffer));
    pca95xx_out(sa1, (uint8_t)(regBuffer >> 8u));

}

void BG_KRKL::rgb1(uint8_t rgb)
{
    rgbCommon(rgb, KRKL_OFFSET_RGB1, KRKL_MASK_RGB1);
}

void BG_KRKL::rgb2(uint8_t rgb)
{
    rgbCommon(rgb, KRKL_OFFSET_RGB2, KRKL_MASK_RGB2);
}
