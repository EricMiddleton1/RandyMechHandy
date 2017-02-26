/*
 * Analog.h
 *
 *  Created on: Feb 26, 2017
 *      Author: eric
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#include <stdint.h>

enum AnalogInput {
    ANALOG_M0 = 0,
    ANALOG_M1,
    ANALOG_M2,
    ANALOG_M3,
    ANALOG_M4,

    ANALOG_MAX
};


void Analog_init();

float Analog_get(enum AnalogInput);

#endif /* ANALOG_H_ */
