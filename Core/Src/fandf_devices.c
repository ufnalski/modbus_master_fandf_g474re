/*
 * fandf_devices.c
 *
 *  Created on: 2 sie 2024
 *      Author: user
 */

#include "fandf_devices.h"
#include "modbus_crc.h"
#include "usart.h"

uint8_t meter_data_received_flag = 0;
uint8_t led_data_confirmed_flag = 0;
uint8_t RxData[32];
uint8_t TxData[32];
uint8_t energy_meter_heartbeat = 0;

char lcd_line[32];

void AskLe01mForEnergyConsumption(void)
{
	// See e.g. https://www.youtube.com/watch?v=TBvcYIUUW0o
	TxData[0] = METER_ADDR;
	TxData[1] = 0x03;  // Function code for Read Holding Registers
	TxData[2] = 0x00;
	TxData[3] = 0x00; // starting address
	TxData[4] = 0x00;
	TxData[5] = 0x03; // number of registers to read: 3 * 2 bytes = 6 bytes to be read
	uint16_t crc = modbus_rtu_crc(TxData, 6);
	TxData[6] = crc & 0xFF;   // CRC LOW
	TxData[7] = (crc >> 8) & 0xFF;  // CRC HIGH

	HAL_UARTEx_ReceiveToIdle_IT(&huart5, (uint8_t*) (&RxData), 32); // pull-up resistor!!!
	sendData(TxData, 8); // 6 bytes of data + 2 bytes of crc
}

void SendMrledtTotalCost(float _total_cost)
{
	TxData[0] = LED_ADDR;
	TxData[1] = 0x10; // Function code for Write Multiple Holding Registers
	TxData[2] = 0x00;
	TxData[3] = 0x00; // starting address
	TxData[4] = 0x00;
	TxData[5] = 0x02; // number of registers
	TxData[6] = 0x04; // number of bytes (number of registers x 2)
	if (_total_cost > -99.9)
	{
		TxData[7] = ((int16_t) (_total_cost * 10)) >> 8;
		TxData[8] = ((int16_t) (_total_cost * 10));
		TxData[9] = 0x00;
		TxData[10] = 0x03;  // decimal place
	}
	else
	{
		TxData[7] = ((int16_t) _total_cost) >> 8;
		TxData[8] = ((int16_t) _total_cost);
		TxData[9] = 0x00;
		TxData[10] = 0x00;  // decimal place
	}
	uint16_t crc = modbus_rtu_crc(TxData, 11);
	TxData[11] = crc & 0xFF;   // CRC LOW
	TxData[12] = (crc >> 8) & 0xFF;  // CRC HIGH

	HAL_UARTEx_ReceiveToIdle_IT(&huart5, (uint8_t*) (&RxData), 32);
	sendData(TxData, 13); // 11 bytes of data + 2 bytes of crc
}

void DisplayConsumptionAndCost(float _total_energy, float _total_cost)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 10);
	ssd1306_WriteString("Modbus Master STM32", Font_6x8, White);
	ssd1306_SetCursor(5, 20);
	ssd1306_WriteString("LE-01M Energy Meter", Font_6x8, White);
	ssd1306_SetCursor(5, 30);
	if (1 == energy_meter_heartbeat)
	{
		sprintf(lcd_line, "  ufnalski.edu.pl  *");
	}
	else
	{
		sprintf(lcd_line, "  ufnalski.edu.pl");
	}
	ssd1306_WriteString(lcd_line, Font_6x8, White);
	sprintf(lcd_line, "Energy: %7.2f kWh", _total_energy);
	ssd1306_SetCursor(5, 44);
	ssd1306_WriteString(lcd_line, Font_6x8, White);
	sprintf(lcd_line, "Budget: %7.2f PLN", _total_cost);
	ssd1306_SetCursor(5, 55);
	ssd1306_WriteString(lcd_line, Font_6x8, White);

	ssd1306_UpdateScreen();
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if (huart->Instance == UART5)
	{
		if (RxData[0] == METER_ADDR)
		{
			// A fully-fledged implementation needs CRC checking before acting on a message!
			meter_data_received_flag = 1;
			energy_meter_heartbeat = 1 - energy_meter_heartbeat; // toggle
		}
		else if (RxData[0] == LED_ADDR)
		{
			// A fully-fledged implementation needs a CRC check and a successful write confirmation!
			led_data_confirmed_flag = 1;
		}
		else
		{
			;
		}
	}
}

#ifdef HARDWARE_FLOW_CONTROL_RS485

void sendData(uint8_t *data, uint8_t size)
{
	HAL_UART_Transmit(&huart5, data, size, 100);
}

#else

void sendData(uint8_t *data, uint8_t size)
{
	HAL_GPIO_WritePin(MAX3485_EN_GPIO_Port, MAX3485_EN_Pin, GPIO_PIN_SET);
//	HAL_Delay(1);
	HAL_UART_Transmit(&huart5, data, size, 100);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(MAX3485_EN_GPIO_Port, MAX3485_EN_Pin, GPIO_PIN_RESET);
}

#endif
