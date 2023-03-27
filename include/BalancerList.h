/**
 * @file BalancerSignalsTest.h
 * @author Joscha Wagner (joscha@nebensound.com)
 * @brief defines the Signals and limits used
 *
 * Copyright (c) Nebensound GmbH 2021
 *
 */

#define BALANCER_ACTIVATION_METHOD ((Signals::GetAnalogValue(AD_C1) + \
                                     Signals::GetAnalogValue(AD_C2) + \
                                     Signals::GetAnalogValue(AD_C3) + \
                                     Signals::GetAnalogValue(AD_C4) + \
                                     Signals::GetAnalogValue(AD_C5) + \
                                     Signals::GetAnalogValue(AD_C6) + \
                                     Signals::GetAnalogValue(AD_C7) + \
                                     Signals::GetAnalogValue(AD_C8)) > 26.9)

/**
 * @brief list of all signals and their max and mins that will trigger final shut off
 *
 * @param SignalID signal id of the Signal
 * @param SignalID_BU BU attached to current
 * @param min minimal offset to other cells to trigger
 * @param max maximal offset to other cells to trigger final shut off
 */
// clang-format off
//                 ID       BU      Mode        Min     Min_Release Max     Max_Release
#define BalancerSignalList \
    BalancerSignal(AD_C1,   BU_C1,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C2,   BU_C2,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C3,   BU_C3,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C4,   BU_C4,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C5,   BU_C5,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C6,   BU_C6,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C7,   BU_C7,  AllCompare, 0.004,  0.001,      3.6,      3.5) \
    BalancerSignal(AD_C8,   BU_C8,  AllCompare, 0.004,  0.001,      3.6,      3.5)
// clang-format on