/**
 * @file PinList.h
 * @author Joscha Wagner (joscha@nebensound.com)
 * @brief Definition of all Pins for iRock V2_3 hardware
 *
 * Copyright (c) Nebensound GmbH 2021
 */

// I2C definitions

/*
 * A Pin is defined by the following parameters:
 *
 *	* PinId	        Id of the Pin an enum (e.g. PinPA1) which is the index
 *					into the Pin table
 *  * PinNo         The number of the Pin on the Processor a symbolic constant
 *                   of the used hardware board (e.g. PA1)
 *	* Type			Type of the Pin. One of the following values:
 *						* AnalogInputPin
 *                      * AnalogOutputPin
 *	                    * DigitalInputPin
 *	                    * DigitalInputPullUpPin
 *	                    * DigitalInputPullDownPin
 *	                    * DigitalOutputPin
 *                      * DigitalOutputOpenDrainPin
 *	                    * VrefIntExternPin
 *  * Gain          Factor (float) to multiply the Analog Value with
 *	* Offset        Offset (float) to add to the Analog Value
 *	* Inverted		Boolean defining if the Digital Value should be inverted
 *	* Generic  	    This boolean attribute defines if the Pin is a Generic
 *                   Pin and allows to be added to a Signal at run-time.
 *                   Only Output Pins allow dynamic addition at run-time.
 *                   For other Pins the attribute is ignored and should
 *                   be set to false.
 *	* Description 	Description of the Pin
 *
 *
 * Please define here the list of all Pins
 */
// clang-format off
//      PinName             Pin/Address PinType                     Gain    Offset  Invert  Generic Description
#define PinList \
    Pin(PinDip1,            PA15,       DigitalInputPullUpPin,      1.0,    0.0,    true,   false,  "Dip switch 1") \
    Pin(PinDip2,            PC10,       DigitalInputPullUpPin,      1.0,    0.0,    true,   false,  "Dip switch 2") \
    Pin(PinDip3,            PC11,       DigitalInputPullUpPin,      1.0,    0.0,    true,   false,  "Dip switch 3") \
    Pin(PinAD_C1,           PA7,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 1 voltage") \
    Pin(PinAD_C2,           PA6,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 2 voltage") \
    Pin(PinAD_C3,           PA4,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 3 voltage") \
    Pin(PinAD_C4,           PA3,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 4 voltage") \
    Pin(PinAD_C5,           PA2,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 5 voltage") \
    Pin(PinAD_C6,           PA0,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 6 voltage") \
    Pin(PinAD_C7,           PC3,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 7 voltage") \
    Pin(PinAD_C8,           PC0,        AnalogInputPin,             2.0,    0.0,    false,  false,  "Cell 8 voltage") \
    Pin(PinGPO_LVP,         PA8,        DigitalOutputPin,           1.0,    0.0,    true,   false,  "GPO LVP") \
    Pin(PinGPO_OVP,         PB12,       DigitalOutputPin,           1.0,    0.0,    true,   false,  "GPO UVP") \
    Pin(PinBU_C1,           PC9,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 1") \
    Pin(PinBU_C2,           PC8,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 2") \
    Pin(PinBU_C3,           PC7,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 3") \
    Pin(PinBU_C4,           PC6,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 4") \
    Pin(PinBU_C5,           PB15,       DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 5") \
    Pin(PinBU_C6,           PB2,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 6") \
    Pin(PinBU_C7,           PC14,       DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 7") \
    Pin(PinBU_C8,           PC13,       DigitalOutputPin,           1.0,    0.0,    false,  false,  "BU Cell 8") \
    Pin(PinLED1,            PB4,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "LED 1") \
    Pin(PinLED2,            PB3,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "LED 2") \
    Pin(PinLED3,            PD2,        DigitalOutputPin,           1.0,    0.0,    false,  false,  "LED 3")
// clang-format on
