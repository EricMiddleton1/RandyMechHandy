/*
 * Analog.c
 *
 *  Created on: Feb 26, 2017
 *      Author: eric
 */


#include "Analog.h"

#include "hw_memmap.h"
#include "adc.h"

#define M0_MIN  0
#define M0_MAX  4096

#define M1_MIN  0
#define M1_MAX  4096

#define M2_MIN  0
#define M2_MAX  4096

#define M3_MIN  0
#define M3_MAX  4096

#define M4_MIN  0
#define M4_MAX  4096

const uint32_t GPIO_SEL_PORT[] = {GPIOA1_BASE, GPIOA2_BASE};
const uint32_t GPIO_SEL_PIN[] = {0x80, 0x01};

const uint32_t ADC_CH_MAP[ANALOG_MAX] = {ADC_CH_0, ADC_CH_0, ADC_CH_1, ADC_CH_2, ADC_CH_3};

static void __handler0();
static void __handler1();
static void __handler2();
static void __handler3();

static uint16_t __m0, __m1, __m2, __m3, __m4;
static int __adc0State;

void Analog_init() {
    __m0 = 0;
    __m1 = 0;
    __m2 = 0;
    __m3 = 0;
    __m4 = 0;
    __adc0State = 0;

    GPIOPinWrite(GPIO_SEL_PORT[__adc0State], GPIO_SEL_PIN[__adc0State], GPIO_SEL_PIN[__adc0State]);

    ADCChannelEnable(ADC_BASE, ADC_CH_0);
    ADCChannelEnable(ADC_BASE, ADC_CH_1);
    ADCChannelEnable(ADC_BASE, ADC_CH_2);
    ADCChannelEnable(ADC_BASE, ADC_CH_3);

    ADCEnable(ADC_BASE);

    ADCIntRegister(ADC_BASE, ADC_CH_0, __handler0);
    ADCIntRegister(ADC_BASE, ADC_CH_1, __handler1);
    ADCIntRegister(ADC_BASE, ADC_CH_2, __handler2);
    ADCIntRegister(ADC_BASE, ADC_CH_3, __handler3);
}

float Analog_get(enum AnalogInput in) {
    float retval;

    ADCDisable(ADC_BASE);
    switch(in) {
    case ANALOG_M0:
        retval = ((float)__m0 - M0_MIN) / (M0_MAX - M0_MIN);
    break;

    case ANALOG_M1:
        retval = ((float)__m1 - M1_MIN) / (M1_MAX - M1_MIN);
    break;

    case ANALOG_M2:
        retval = ((float)__m2 - M2_MIN) / (M2_MAX - M2_MIN);
    break;

    case ANALOG_M3:
        retval = ((float)__m3 - M3_MIN) / (M3_MAX - M3_MIN);
    break;

    case ANALOG_M4:
        retval = ((float)__m4 - M4_MIN) / (M4_MAX - M4_MIN);
    break;
    }
    ADCEnable(ADC_BASE);

    return retval;
}

static void __handler0() {
    unsigned long intStatus = ADCIntStatus(ADC_BASE, ADC_CH_0);
    ADCIntClear(ADC_BASE, ADC_CH_0, intStatus);

    if(__adc0State) {
        while(ADCFIFOLvlGet(ADC_BASE, ADC_CH_0) > 0) {
            __m1 = ((uint32_t)__m1 + ADCFIFORead(ADC_BASE, ADC_CH_0)) >> 1;
        }
    }
    else {
        while(ADCFIFOLvlGet(ADC_BASE, ADC_CH_0) > 0) {
            __m0 = ((uint32_t)__m0 + ADCFIFORead(ADC_BASE, ADC_CH_0)) >> 1;
        }
    }

    GPIOPinWrite(GPIO_SEL_PORT[__adc0State], GPIO_SEL_PIN[__adc0State], 0x00);
    __adc0State = !__adc0State;
    GPIOPinWrite(GPIO_SEL_PORT[__adc0State], GPIO_SEL_PIN[__adc0State], GPIO_SEL_PIN[__adc0State]);
}

static void __handler1() {
    unsigned long intStatus = ADCIntStatus(ADC_BASE, ADC_CH_1);
    ADCIntClear(ADC_BASE, ADC_CH_1, intStatus);

    while(ADCFIFOLvlGet(ADC_BASE, ADC_CH_1) > 0) {
        __m2 = ((uint32_t)__m2 + ADCFIFORead(ADC_BASE, ADC_CH_1)) >> 1;
    }
}

static void __handler2() {
    unsigned long intStatus = ADCIntStatus(ADC_BASE, ADC_CH_2);
    ADCIntClear(ADC_BASE, ADC_CH_2, intStatus);

    while(ADCFIFOLvlGet(ADC_BASE, ADC_CH_2) > 0) {
        __m3 = ((uint32_t)__m3 + ADCFIFORead(ADC_BASE, ADC_CH_2)) >> 1;
    }
}

static void __handler3() {
    unsigned long intStatus = ADCIntStatus(ADC_BASE, ADC_CH_3);
    ADCIntClear(ADC_BASE, ADC_CH_3, intStatus);

    while(ADCFIFOLvlGet(ADC_BASE, ADC_CH_3) > 0) {
        __m4 = ((uint32_t)__m4 + ADCFIFORead(ADC_BASE, ADC_CH_3)) >> 1;
    }
}
