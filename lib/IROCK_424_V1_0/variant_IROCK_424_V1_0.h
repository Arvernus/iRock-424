/*
 *******************************************************************************
 * Copyright (c) 2011-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define PA0 PIN_A0
#define PA1 PIN_A1
#define PA2 PIN_A2
#define PA3 PIN_A3
#define PA4 PIN_A4
#define PA5 PIN_A5
#define PA6 PIN_A6
#define PA7 PIN_A7
#define PA8 8
#define PA9 9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15
#define PB0 PIN_A8
#define PB1 PIN_A9
#define PB2 18
#define PB3 19
#define PB4 20
#define PB5 21
#define PB6 22
#define PB7 23
#define PB8 24
#define PB9 25
#define PB10 26
#define PB11 27
#define PB12 28
#define PB13 29
#define PB14 30
#define PB15 31
#define PC0 PIN_A10
#define PC1 PIN_A11
#define PC2 PIN_A12
#define PC3 PIN_A13
#define PC4 PIN_A14
#define PC5 PIN_A15
#define PC6 38
#define PC7 39
#define PC8 40
#define PC9 41
#define PC10 42
#define PC11 43
#define PC12 44
#define PC13 45
#define PC14 46
#define PC15 47
#define PD2 48
#define PH0 49
#define PH1 50

// Alternate pins number
#define PA2_ALT1 (PA2 | ALT1)
#define PA3_ALT1 (PA3 | ALT1)
#define PA6_ALT1 (PA6 | ALT1)
#define PA7_ALT1 (PA7 | ALT1)
#define PA14_ALT1 (PA14 | ALT1)
#define PB4_ALT1 (PB4 | ALT1)
#define PB5_ALT1 (PB5 | ALT1)
#define PC6_ALT1 (PC6 | ALT1)
#define PC7_ALT1 (PC7 | ALT1)
#define PC10_ALT1 (PC10 | ALT1)
#define PC11_ALT1 (PC11 | ALT1)

#define NUM_DIGITAL_PINS 51
#define NUM_ANALOG_INPUTS 16

// On-board LED pin number
#ifndef LED_BUILTIN
#define LED_BUILTIN PB4
#endif

// On-board user button
#ifndef USER_BTN
#define USER_BTN PNUM_NOT_DEFINED
#endif

// SPI definitions
#ifndef PIN_SPI_SS
#define PIN_SPI_SS PA4
#endif
#ifndef PIN_SPI_SS1
#define PIN_SPI_SS1 PA15
#endif
#ifndef PIN_SPI_SS2
#define PIN_SPI_SS2 PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
#define PIN_SPI_SS3 PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
#define PIN_SPI_MOSI PA7
#endif
#ifndef PIN_SPI_MISO
#define PIN_SPI_MISO PA6
#endif
#ifndef PIN_SPI_SCK
#define PIN_SPI_SCK PA5
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
#define PIN_WIRE_SDA PB9
#endif
#ifndef PIN_WIRE_SCL
#define PIN_WIRE_SCL PB8
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
#define TIMER_TONE TIM6
#endif
#ifndef TIMER_SERVO
#define TIMER_SERVO TIM7
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
#define SERIAL_UART_INSTANCE 1 // Connected to ST-Link
#endif

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
#define PIN_SERIAL_RX PA10
#endif
#ifndef PIN_SERIAL_TX
#define PIN_SERIAL_TX PA9
#endif

#define ENABLE_HWSERIAL2
#ifndef PIN_SERIAL2_RX
#define PIN_SERIAL2_RX PB11
#endif
#ifndef PIN_SERIAL2_TX
#define PIN_SERIAL2_TX PB10
#endif

// RS485 Definitions
#ifndef RS485_SERIAL_PORT
#define RS485_SERIAL_PORT Serial2
#endif
#ifndef PIN_RS485_RX
#define PIN_RS485_RX PIN_SERIAL2_RX
#endif
#ifndef PIN_RS485_TX
#define PIN_RS485_TX PIN_SERIAL2_TX
#endif
#ifndef PIN_RS485_DE_RE
#define PIN_RS485_DE_RE PB14
#endif
#ifndef PIN_RS485_CTS
#define PIN_RS485_CTS PB13
#endif

// Modbus Definitions
#define ENABLE_MODBUS 1
#define NUMBER_OF_CELLS 8

/* Extra HAL modules */
#if !defined(HAL_DAC_MODULE_DISABLED)
#define HAL_DAC_MODULE_ENABLED
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#ifndef SERIAL_PORT_MONITOR
#define SERIAL_PORT_MONITOR Serial
#endif
#ifndef SERIAL_PORT_HARDWARE
#define SERIAL_PORT_HARDWARE Serial
#endif
#endif