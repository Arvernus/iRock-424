/**
 * @file BatShutoffList.h
 * @author Joscha Wagner (joscha@nebensound.com)
 * @brief defines the Signals and limits used
 *
 * Copyright (c) Nebensound GmbH 2023
 *
 */

/**
 * @brief list of all sorts off shutoff possible
 *
 * @param Name name of the shutoff type
 */
// clang-format off
//                 Name     Warning Final
#define BatShutoffTypeList \
    BatShutoffType(Ovp,     OVP,    false) \
    BatShutoffType(Lvp,     LVP,    false) \
    BatShutoffType(Final,   FINAL,  true) \
    BatShutoffType(Ocp,     OCP,    false)
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
#define BatShutoffTriggerList \
    BatShutoffTrigger(AD_C1,            Ovp,    MaxCompare, 0,      0,          3.75,    3.60) \
    BatShutoffTrigger(AD_C2,            Ovp,    MaxCompare, 0,      0,          3.75,    3.60) \
    BatShutoffTrigger(AD_C3,            Ovp,    MaxCompare, 0,      0,          3.75,    3.60) \
    BatShutoffTrigger(AD_C4,            Ovp,    MaxCompare, 0,      0,          3.75,    3.60) \
    BatShutoffTrigger(AD_C1,            Lvp,    MinCompare, 2.9,    3.2,        0,      0) \
    BatShutoffTrigger(AD_C2,            Lvp,    MinCompare, 2.9,    3.2,        0,      0) \
    BatShutoffTrigger(AD_C3,            Lvp,    MinCompare, 2.9,    3.2,        0,      0) \
    BatShutoffTrigger(AD_C4,            Lvp,    MinCompare, 2.9,    3.2,        0,      0) \
    BatShutoffTrigger(AD_C1,            Final,  AllCompare, 2.8,    3.2,        3.85,    4.0) \
    BatShutoffTrigger(AD_C2,            Final,  AllCompare, 2.8,    3.2,        3.85,    4.0) \
    BatShutoffTrigger(AD_C3,            Final,  AllCompare, 2.8,    3.2,        3.85,    4.0) \
    BatShutoffTrigger(AD_C4,            Final,  AllCompare, 2.8,    3.2,        3.85,    4.0)
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
#define BatShutoffActorList \
    BatShutoffActor(Status_OVP,     Ovp,        false) \
    BatShutoffActor(LED1,           Ovp,        false) \
    BatShutoffActor(Status_LVP,     Lvp,        false) \
    BatShutoffActor(LED2,           Lvp,        true) \
    BatShutoffActor(Status_FinalSO, Final,      false)
// clang-format on