/*
 * modbus_crc.h
 *
 *  Created on:
 *      Author:
 */

#ifndef INC_MODBUS_CRC_H_
#define INC_MODBUS_CRC_H_

#define HW_CRC

uint16_t modbus_rtu_crc(uint8_t *buf, uint8_t len);


#endif /* INC_MODBUS_CRC_H_ */
