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

    float integral, prevIn, setPoint, curPoint;
};

float PID_init(struct PID *, float kp, float ki, float kd);

float PID_update(struct PID*, float dt);


#endif /* PID_H_ */
