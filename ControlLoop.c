/*
 * ControlLoop.c
 *
 *  Created on: Feb 26, 2017
 *      Author: eric
 */


#include "ControlLoop.h"

#include "PID.h"
#include "Analog.h"
#include "Timer.h"

#define PID_COUNT       5
#define UPDATE_RATE     (0.01f)

static struct PID __pid[PID_COUNT];

void ControlLoop_init() {
    int i;
    for(i = 0; i < PID_COUNT; ++i) {
        PID_init(&__pid[i], 0.f, 0.f, 0.f);
    }
}

void ControlLoop_update() {
    unsigned int i;
    for(i = 0; i < PID_COUNT; ++i) {
        float actuation = PID_update(__pid + i, Analog_get(i), UPDATE_RATE);
        Motor_set(i, actuation);
    }
}

void Controller_setP(uint8_t controller, float p) {
    if(controller < PID_COUNT)
        __pid[controller].kp = p;
}

void Controller_setI(uint8_t controller, float i) {
    if(controller < PID_COUNT)
        __pid[controller].ki = i;

}

void Controller_setD(uint8_t controller, float d) {
    if(controller < PID_COUNT)
        __pid[controller].kd = d;
}
