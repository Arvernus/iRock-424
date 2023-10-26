/**
 * @file BatShutOffTriggersTest.h
 * @author Joscha Wagner (joscha@nebensound.com)
 * @brief defines the Signals and limits used
 *
 * Copyright (c) Nebensound GmbH 2021
 *
 */

/**
 * @brief list of all sorts off shutoff possible
 *
 * @param Name name of the shutoff type
 */
// clang-format off
//                 Name     Warning Final
#define BatShutOffTypeList \
    BatShutOffType(Ovp,     OVP,    false) \
    BatShutOffType(Lvp,     LVP,    false) \
    BatShutOffType(Final,   FINAL,  true) \
    BatShutOffType(Ocp,     OCP,    false)
// clang-format on

/**
 * @brief list of all signals and there max and mins that will trigger shut off
 *
 * @param SignalID signal id of the Signal
 * @param ShutOffType defines the type of shut off
 * @param Mode  0 = NoCompare   = no comparison
 *              1 = MinCompare  = min
 *              2 = MaxCompare  = max
 *              3 = AllCompare  = min and max
 * @param Max if the value of the signal is bigger than Max shut off will trigger
 * @param Release if the value of the signal is smaller than Release shut off will return to default
 */
// clang-format off
//                    ID                Type    Mode        Min     Min_Release Max     Max_Release
#define BatShutOffTriggerList \
    BatShutOffTrigger(AD_C1,            Ovp,    MaxCompare, 0,      0,          3.9,    3.65) \
    BatShutOffTrigger(AD_C2,            Ovp,    MaxCompare, 0,      0,          3.9,    3.65) \
    BatShutOffTrigger(AD_C3,            Ovp,    MaxCompare, 0,      0,          3.9,    3.65) \
    BatShutOffTrigger(AD_C4,            Ovp,    MaxCompare, 0,      0,          3.9,    3.65) \
    BatShutOffTrigger(AD_C1,            Lvp,    MinCompare, 2.8,    3.2,        0,      0) \
    BatShutOffTrigger(AD_C2,            Lvp,    MinCompare, 2.8,    3.2,        0,      0) \
    BatShutOffTrigger(AD_C3,            Lvp,    MinCompare, 2.8,    3.2,        0,      0) \
    BatShutOffTrigger(AD_C4,            Lvp,    MinCompare, 2.8,    3.2,        0,      0) \
    BatShutOffTrigger(AD_C1,            Final,  AllCompare, 2.7,    2.8,        4.0,    4.0) \
    BatShutOffTrigger(AD_C2,            Final,  AllCompare, 2.7,    2.8,        4.0,    4.0) \
    BatShutOffTrigger(AD_C3,            Final,  AllCompare, 2.7,    2.8,        4.0,    4.0) \
    BatShutOffTrigger(AD_C4,            Final,  AllCompare, 2.7,    2.8,        4.0,    4.0)
// clang-format on

/**
 * @brief list of all signals that will change on trigger
 * @param SignalID signal id of the Signal
 * @param ShutOffType defines the type of shut off
 * @param inverted is signal inverted
 * @param Lock time in s to lock the Actor after change in ms
 * @param isSSR defines if Actor is a Solid state relay
 */
// clang-format off
//                  ID              Type        inverted
#define BatShutOffActorList \
    BatShutOffActor(Status_OVP,     Ovp,        false) \
    BatShutOffActor(LED1,           Ovp,        false) \
    BatShutOffActor(Status_LVP,     Lvp,        false) \
    BatShutOffActor(LED2,           Lvp,        true) \
    BatShutOffActor(Status_FinalSO, Final,      false)
// clang-format on