#include "stdint.h"
#include "crc.h"
#include "modbus_crc.h"

// Compute the MODBUS RTU CRC
uint16_t modbus_rtu_crc(uint8_t *buf, uint8_t len)
{

#ifdef HW_CRC

	uint16_t crc_hw;
	crc_hw = HAL_CRC_Calculate(&hcrc, (uint32_t*) buf, (uint32_t) len);
	return crc_hw;

#else

	uint16_t crc = 0xFFFF;

	for (uint8_t pos = 0; pos < len; pos++)
	{
		crc ^= (uint16_t) buf[pos];      // XOR byte into least sig. byte of crc

		for (int i = 8; i != 0; i--)
		{    // Loop over each bit
			if ((crc & 0x0001) != 0)
			{      // If the LSB is set
				crc >>= 1;                    // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else
				// Else LSB is not set
				crc >>= 1;                    // Just shift right
		}
	}
	// Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
	return crc;

#endif

}
