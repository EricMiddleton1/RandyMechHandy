/*
 * PID.c
 *
 *  Created on: Feb 25, 2017
 *      Author: eric
 */

#include "PID.h"

float PID_init(struct PID *pid, float kp, float ki, float kd) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->integral = 0.f;
    pid->prevIn = 0.;
    pid->setPoint = 0.f;
    pid->curPoint = 0.f;
}

float PID_update(struct PID *pid, float dt) {
    float err = pid->setPoint - pid->curPoint;

    //float out = pid->kp*err + pid->ki*integral + pid->kd*
}
