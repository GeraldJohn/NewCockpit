#ifndef ASSIGNRADIODATA_H
#define ASSIGNRADIODATA_H

#include "SimRadioData.h"

//! Radio mode
DataRefIdent freqIdent[][58] = {
    "sim/cockpit2/radios/actuators/com1_frequency_hz",
    "sim/cockpit2/radios/actuators/com2_frequency_hz",
    "sim/cockpit2/radios/actuators/nav1_frequency_hz",
    "sim/cockpit2/radios/actuators/nav2_frequency_hz",
    "sim/cockpit2/radios/actuators/adf1_frequency_hz",
    "sim/cockpit2/radios/actuators/adf2_frequency_hz"
};

///SimRadioData (    *ident,      &Mode, &Digits=2, &NKSt = 0, *hasPowerFlag);
SimData *freq[] = {
    new SimRadioData(freqIdent[0], _com1, 1, 2),
    new SimRadioData(freqIdent[1], _com2, 1, 2),
    new SimRadioData(freqIdent[2], _nav1, 1, 2),
    new SimRadioData(freqIdent[3], _nav2, 1, 2),
    new SimRadioData(freqIdent[4], _adf1),
    new SimRadioData(freqIdent[5], _adf2) };



DataRefIdent freq_stbyIdent[][58] = {
    "sim/cockpit2/radios/actuators/com1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/com2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/nav1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/nav2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/adf1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/adf2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/transponder_code"
};

///SimStbyRadioData(ident, &Mode, &Digits, &LowLimit = 0, &UpLimit = 9, &Step = 1, &Jump = true, &NKSt = 0, *hasPowerFlag);
SimData *freq_stby[] = {
    new SimStbyRadioData(freq_stbyIdent[0], _com1, 1, 118, 136, 25, true, 2),
    new SimStbyRadioData(freq_stbyIdent[1], _com2, 1, 118, 136, 25, true, 2),
    new SimStbyRadioData(freq_stbyIdent[2], _nav1, 1, 108, 117, 50, true, 2),
    new SimStbyRadioData(freq_stbyIdent[3], _nav2, 1, 108, 117, 50, true, 2),
    new SimStbyRadioData(freq_stbyIdent[4], _adf1, 2),
    new SimStbyRadioData(freq_stbyIdent[5], _adf2, 2),
    new SimStbyRadioData(freq_stbyIdent[6], _atc, 3, 0, 7) };

#endif // ASSIGNRADIODATA_H
