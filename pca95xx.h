#ifndef PCA95XX_H_
#define PCA95XX_H_

#include <Arduino.h>

#define PCA95XX_IN_REG 0x00
#define PCA95XX_OUT_REG 0x01
#define PCA95XX_POL_REG 0x02
#define PCA95XX_CONF_REG 0x03

#define PCA95XX_IN_ALL 0xFF
#define PCA95XX_OUT_ALL 0x00
#define PCA95XX_POL_DEFAULT_ALL 0x00
#define PCA95XX_POL_INVERTED_ALL 0xFF

void pca95xx_configure(uint8_t addr, uint8_t polInv = PCA95XX_POL_DEFAULT_ALL, uint8_t io = PCA95XX_OUT_ALL);

uint8_t pca95xx_in(uint8_t addr);

void pca95xx_out(uint8_t addr, uint8_t data);

#endif // PCA95XX_H_
