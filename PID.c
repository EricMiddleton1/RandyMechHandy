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
    pid->prevErr = 0.f;
    pid->setPoint = 0.f;
}

void PID_set(struct PID *pid, float setPoint) {
    pid->setPoint = setPoint;
}

float PID_update(struct PID *pid, float curPoint, float dt) {
    float err = pid->setPoint - curPoint;
    float deriv = (err - pid->prevErr) / dt;
    pid->integral += err * dt;

    float out = pid->kp*err + pid->ki*pid->integral + pid->kd*deriv;

    pid->prevErr = err;

    return out;
}
