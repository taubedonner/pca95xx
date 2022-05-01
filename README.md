# Simple driver for PCA9538 and PCA9554 registers

## About

This is a library that implements basic abstraction (input, output, configuration) for TI I2C 8-bit registers. There is also a small board specific library (KRKL) that controls an LED bargraph and two RGB LEDs connected to PCA9538 I2C register.

## Tested on

| **Register** | **Arduino** | **Energia** | **Note** |
| :-------- |:---:|:---:|:-----|
| PCA9538 | X | X | *Arduino Uno* and *MSP432P401R* |
| PCA9554 | X |  | *Arduino Uno* (Proteus) |
