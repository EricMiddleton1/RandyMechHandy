//*****************************************************************************
// rom_pin_mux_config.c
//
// configure the device pins for different signals
//
// Copyright (c) 2016, Texas Instruments Incorporated - http://www.ti.com/
// All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

// This file was automatically generated on 2/26/2017 at 1:38:23 AM
// by TI PinMux version 4.0.1482
//
//*****************************************************************************

#include "pin_mux_config.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "pin.h"
#include "gpio.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
//*****************************************************************************
void PinMuxConfig(void)
{


    //
    // Set unused pins to PIN_MODE_0 with the exception of JTAG pins 16,17,19,20
    //
    MAP_PinModeSet(PIN_03, PIN_MODE_0);
    MAP_PinModeSet(PIN_04, PIN_MODE_0);
    MAP_PinModeSet(PIN_05, PIN_MODE_0);
    MAP_PinModeSet(PIN_15, PIN_MODE_0);
    MAP_PinModeSet(PIN_45, PIN_MODE_0);
    MAP_PinModeSet(PIN_52, PIN_MODE_0);
    MAP_PinModeSet(PIN_53, PIN_MODE_0);

    //
    // Enable Peripheral Clocks
    //
    MAP_PRCMPeripheralClkEnable(PRCM_TIMERA1, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_TIMERA3, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_TIMERA2, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_ADC, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA0, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA2, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA3, PRCM_RUN_MODE_CLK);
    //
    // Configure PIN_21 for TimerPWM2 GT_PWM02
    //
    MAP_PinTypeTimer(PIN_21, PIN_MODE_9);
    //
    // Configure PIN_01 for TimerPWM6 GT_PWM06
    //
    MAP_PinTypeTimer(PIN_01, PIN_MODE_3);
    //
    // Configure PIN_02 for TimerPWM7 GT_PWM07
    //
    MAP_PinTypeTimer(PIN_02, PIN_MODE_3);
    //
    // Configure PIN_64 for TimerPWM5 GT_PWM05
    //
    MAP_PinTypeTimer(PIN_64, PIN_MODE_3);
    //
    // Configure PIN_17 for TimerPWM0 GT_PWM00
    //
    MAP_PinTypeTimer(PIN_17, PIN_MODE_5);
    //
    // Configure PIN_57 for ADC0 ADC_CH0
    //
    MAP_PinTypeADC(PIN_57, PIN_MODE_255);
    //
    // Configure PIN_58 for ADC0 ADC_CH1
    //
    MAP_PinTypeADC(PIN_58, PIN_MODE_255);
    //
    // Configure PIN_59 for ADC0 ADC_CH2
    //
    MAP_PinTypeADC(PIN_59, PIN_MODE_255);
    //
    // Configure PIN_60 for ADC0 ADC_CH3
    //
    MAP_PinTypeADC(PIN_60, PIN_MODE_255);
    //
    // Configure PIN_50 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_50, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA0_BASE, 0x1, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_55 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_55, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA0_BASE, 0x2, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_61 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_61, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA0_BASE, 0x40, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_62 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_62, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA0_BASE, 0x80, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_63 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_63, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x1, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_06 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_06, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x80, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_07 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_07, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA2_BASE, 0x1, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_08 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_08, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA2_BASE, 0x2, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_16 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_16, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA2_BASE, 0x80, GPIO_DIR_MODE_OUT);
    //
    // Configure PIN_18 for GPIO Output
    //
    MAP_PinTypeGPIO(PIN_18, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA3_BASE, 0x10, GPIO_DIR_MODE_OUT);
}
