/*
 * PID.h
 *
 *  Created on: Feb 25, 2017
 *      Author: eric
 */

#ifndef PID_H_
#define PID_H_

struct PID {
    float kp, ki, kd;

    float integral, prevErr, setPoint;
};

float PID_init(struct PID*, float kp, float ki, float kd);

void PID_set(struct PID*, float setPoint);
float PID_update(struct PID*, float curPoint, float dt);


#endif /* PID_H_ */
