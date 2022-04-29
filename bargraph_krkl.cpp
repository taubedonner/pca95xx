#include "bargraph_krkl.h"

#include "pca95xx.h"

uint8_t krkl_sa0 = 0u;
uint8_t krkl_sa1 = 0u;
uint16_t krkl_buf = 0u;

void bargraph_krkl_rgb_out(uint8_t rgb, uint8_t offset, uint8_t mask)
{
    krkl_buf &= ~(mask << 8u);
    krkl_buf |= ((rgb & KRKL_BIT_R) << offset) << 8u;
    krkl_buf |= ((rgb & KRKL_BIT_G) << offset) << 8u;
    krkl_buf |= ((rgb & KRKL_BIT_B) << offset) << 8u;
    pca95xx_out(krkl_sa1, (uint8_t)(krkl_buf >> 8u));
}

void bargraph_krkl_init(uint8_t sa0, uint8_t sa1)
{
    krkl_sa0 = sa0;
    krkl_sa1 = sa1;
    pca95xx_configure(krkl_sa0);
    pca95xx_configure(krkl_sa1);
}

void bargraph_krkl_init()
{
    bargraph_krkl_init(KRKL_BARGRAPH_SA0, KRKL_BARGRAPH_SA1);
}

void bargraph_krkl_out(uint8_t level)
{
    krkl_buf &= ~KRKL_MASK_BARGRAPH;
    krkl_buf |= (~((1u << level) - 1u)) & KRKL_MASK_BARGRAPH;
    pca95xx_out(krkl_sa0, (uint8_t)(krkl_buf));
    pca95xx_out(krkl_sa1, (uint8_t)(krkl_buf >> 8u));

}

void bargraph_krkl_rgb1_out(uint8_t rgb)
{
    bargraph_krkl_rgb_out(rgb, KRKL_OFFSET_RGB1, KRKL_MASK_RGB1);
}

void bargraph_krkl_rgb2_out(uint8_t rgb)
{
    bargraph_krkl_rgb_out(rgb, KRKL_OFFSET_RGB2, KRKL_MASK_RGB2);
}
