/*
 * Receiver.c
 *
 *  Created on: Dec 19, 2016
 *      Author: eric
 */

#include <stdint.h>

#include "hw_types.h"
#include "hw_memmap.h"
#include "timer.h"
#include "Timer.h"

const uint32_t GPIO_PORTS[] = {GPIOA0_BASE, GPIOA0_BASE, GPIOA0_BASE, GPIOA0_BASE, GPIOA1_BASE};
const uint8_t GPIO_PINS[] = {0x01, 0x02, 0x40, 0x80, 0x01};

const uint32_t TIMERS[] = {TIMERA1_BASE, TIMERA3_BASE, TIMERA3_BASE, TIMERA2_BASE, TIMERA0_BASE};
const uint32_t TIMER_INSTANCES[] = {TIMER_A, TIMER_A, TIMER_B, TIMER_B, TIMER_A};


#define MIN(a, b)           (((a) < (b)) ? (a) : (b))
#define MAX(a, b)           (((a) > (b)) ? (a) : (b))
#define CLAMP(n, a, b)      (MIN((b), MAX((a), (n))))
#define ABS(n)              ((n > 0) ? (n) : (-n))

#define CPU_FREQ            (80000000L)

#define RC_PULSE_MIN        (1 * CPU_FREQ / 1000) //1ms
#define RC_PULSE_MAX        (2 * CPU_FREQ / 1000) //2ms

#define MOTOR_UPDATE_RATE   (50)
#define MOTOR_PWM_TOP       (CPU_FREQ / MOTOR_UPDATE_RATE)
//#define MOTOR_MIN_PULSE     (1 * CPU_FREQ / 1000) //1ms
//#define MOTOR_MAX_PULSE     (2 * CPU_FREQ / 1000) //2ms

void Timer_init() {
    //Timer1A - motor0
    //Timer2B - motor1
    //Timer3A - motor2
    //Timer3B - motor3
    //Timer0A - motor4

    //Configure timers
    TimerConfigure(TIMERA0_BASE,
                   TIMER_CFG_SPLIT_PAIR |
                   TIMER_CFG_A_PWM);
    TimerConfigure(TIMERA1_BASE,
                   TIMER_CFG_SPLIT_PAIR |
                   TIMER_CFG_A_PWM);
    TimerConfigure(TIMERA2_BASE,
                   TIMER_CFG_SPLIT_PAIR |
                   TIMER_CFG_B_PWM);
    TimerConfigure(TIMERA3_BASE,
                   TIMER_CFG_SPLIT_PAIR |
                   TIMER_CFG_A_PWM |
                   TIMER_CFG_B_PWM);

    //Set upper 8-bits of interval load value
    TimerPrescaleSet(TIMERA0_BASE, TIMER_A, (MOTOR_PWM_TOP) >> 16);
    TimerPrescaleSet(TIMERA1_BASE, TIMER_A, (MOTOR_PWM_TOP) >> 16);
    TimerPrescaleSet(TIMERA2_BASE, TIMER_B, (MOTOR_PWM_TOP) >> 16);
    TimerPrescaleSet(TIMERA3_BASE, TIMER_BOTH, (MOTOR_PWM_TOP) >> 16);

    //Set lower 16-bits of interval load value
    TimerLoadSet(TIMERA0_BASE, TIMER_A, (MOTOR_PWM_TOP) & 0xFFFF);
    TimerLoadSet(TIMERA1_BASE, TIMER_A, (MOTOR_PWM_TOP) & 0xFFFF);
    TimerLoadSet(TIMERA2_BASE, TIMER_B, (MOTOR_PWM_TOP) & 0xFFFF);
    TimerLoadSet(TIMERA3_BASE, TIMER_BOTH, (MOTOR_PWM_TOP) & 0xFFFF);

    //Set motors to minimum
    Motor_set(0, 0.f);
    Motor_set(1, 0.f);
    Motor_set(2, 0.f);
    Motor_set(3, 0.f);
    Motor_set(4, 0.f);

    //Enable timers
    TimerEnable(TIMERA0_BASE, TIMER_A);
    TimerEnable(TIMERA1_BASE, TIMER_A);
    TimerEnable(TIMERA2_BASE, TIMER_B);
    TimerEnable(TIMERA3_BASE, TIMER_BOTH);
}

void Motor_set(uint8_t motor, float val) {
    if(motor > 4)
        return;

    val = CLAMP(val, -1.f, 1.f);

    uint32_t match = MOTOR_PWM_TOP -
            (ABS(val)*(MOTOR_PWM_TOP - 1));
    match = (val > 0) ? (match) : (MOTOR_PWM_TOP - match);
    TimerPrescaleMatchSet(TIMERS[motor], TIMER_INSTANCES[motor], (match >> 16) & 0xFF);
    TimerMatchSet(TIMERS[motor], TIMER_INSTANCES[motor], match & 0xFFFF);
    GPIOPinWrite(GPIO_PORTS[motor], GPIO_PINS[motor], (val > 0) ? 0x00 : GPIO_PINS[motor]);
}
