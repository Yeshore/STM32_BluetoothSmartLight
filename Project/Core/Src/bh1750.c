#include "bh1750.h"

uint8_t BH1750_SendCmd(BH1750_MODE cmd)
{
	return HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDR_WRITE, (uint8_t *)&cmd, 1, 0xFFFF);
}

uint8_t BH1750_ReadData(uint8_t *data)
{
	return HAL_I2C_Master_Receive(&hi2c2, BH1750_ADDR_READ, data, 2, 0xFFFF);
}

uint16_t BH1750_GetLux(uint8_t *data)
{
	uint16_t lux = 0;
  lux = data[0];
  lux <<= 8;
  lux += data[1];
  lux = (int)(lux / 1.2);
  return lux;
}
