/*
 * ControlLoop.h
 *
 *  Created on: Feb 26, 2017
 *      Author: eric
 */

#ifndef CONTROLLOOP_H_
#define CONTROLLOOP_H_

#include <stdint.h>

void ControlLoop_init();

void Controller_setPoint(uint8_t, float);

void Controller_setP(uint8_t, float);
void Controller_setI(uint8_t, float);
void Controller_setD(uint8_t, float);


#endif /* CONTROLLOOP_H_ */
