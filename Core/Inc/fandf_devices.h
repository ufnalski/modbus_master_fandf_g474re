/*
 * fandf_devices.h
 *
 *  Created on: 2 sie 2024
 *      Author: user
 */

#ifndef INC_FANDF_DEVICES_H_
#define INC_FANDF_DEVICES_H_

#include "main.h"
#include "ssd1306.h"
#include "stdio.h"

#define HARDWARE_FLOW_CONTROL_RS485

#define METER_ADDR 0x6B //107
#define LED_ADDR 0x69 //105

void sendData(uint8_t *data, uint8_t size);
void AskLe01mForEnergyConsumption(void);
void SendMrledtTotalCost(float _total_cost);
void DisplayConsumptionAndCost(float _total_energy, float _total_cost);

#endif /* INC_FANDF_DEVICES_H_ */
