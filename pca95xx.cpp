#include "pca95xx.h"
#include <Wire.h>

uint8_t pca95xx_i2c_buf = 0u;

// Returns 1 when failed
bool pca95xx_i2c_sendData(uint8_t addr, uint8_t cmd, uint8_t data = 0u)
{
    Wire.beginTransmission(addr);
    Wire.write(cmd);
    if (cmd != PCA95XX_IN_REG) Wire.write(data);
    if (Wire.endTransmission()) return 1;
    return 0;
}

// Returns 1 when failed
bool pca95xx_i2c_receiveData(uint8_t addr)
{
    if (pca95xx_i2c_sendData(addr, PCA95XX_IN_REG)) return 1;
    delay(15);
    Wire.requestFrom(addr, 1u, 1u);
    while (Wire.available() < 1);
    pca95xx_i2c_buf = Wire.read();
    return 0;
}

// Send RESET signal to the register (used with PCA9538)
void pca95xx_reset(int8_t resetPin)
{
    if (resetPin < 0) return;
    pinMode(resetPin, PCA95XX_PIN_RESET_MODE);
    digitalWrite(resetPin, LOW);
    delay(1);
    digitalWrite(resetPin, HIGH);
    delay(1);
}

// All pins in output mode by default
void pca95xx_configure(uint8_t addr, uint8_t polInv, uint8_t io)
{
    pca95xx_i2c_sendData(addr, PCA95XX_POL_REG, polInv);
    pca95xx_i2c_sendData(addr, PCA95XX_CONF_REG, io);
    delay(15);
}

uint8_t pca95xx_in(uint8_t addr)
{
    if (!pca95xx_i2c_receiveData(addr)) return 0u;
    return pca95xx_i2c_buf;
}

void pca95xx_out(uint8_t addr, uint8_t data)
{
    pca95xx_i2c_sendData(addr, PCA95XX_OUT_REG, data);
}
