/*
 * Communicator.h
 *
 *  Created on: Oct 27, 2016
 *      Author: eric
 */

#ifndef COMMUNICATOR_H_
#define COMMUNICATOR_H_

#include <stdint.h>

typedef enum PacketType {
	SET_MOTOR = 0,
	SET_MOTOR_FREQ,

	MAX_TYPE
} PacketType;

typedef struct Packet {
	PacketType type;

	uint8_t *payload;
	uint16_t payloadSize;
} Packet;

typedef void(*PacketHandler)(const Packet*);


void Communicator_init();

void Communicator_processBuffer(const uint8_t*, uint32_t);

void Communicator_sendPacket(const Packet*);

void Communicator_registerHandler(PacketType, PacketHandler);

void Communicator_floatToByte(uint8_t*, float*);
void Communicator_byteToFloat(float*, uint8_t*);

#endif /* COMMUNICATOR_H_ */
