#ifndef ASSIGNAPDATA_H
#define ASSIGNAPDATA_H

#include "SimApData.h"

//! AP things
DataRefIdent apIdent[][58] = {

    "sim/cockpit2/autopilot/altitude_dial_ft",
    "sim/cockpit2/autopilot/vvi_dial_fpm",
    "sim/cockpit2/autopilot/heading_dial_deg_mag_pilot",
    "sim/cockpit2/radios/actuators/nav1_obs_deg_mag_pilot",
    "sim/cockpit2/radios/actuators/nav2_obs_deg_mag_pilot",
    "sim/cockpit2/gauges/indicators/altitude_ft_pilot",
    "sim/cockpit2/gauges/indicators/vvi_fpm_pilot",
    "sim/cockpit2/gauges/indicators/compass_heading_deg_mag"
};

///                *ident,    Mode,Row,MMax,Low,   UpperL ,Faktor, Jump, NKSt, hasPowerFlag
SimData *apdata[] = {
    new SimApData(apIdent[0], _alt,  0, 2,     0,   30000,    1,   false),
    new SimApData(apIdent[1], _vvi,  0, 0, -3000,    3000,   10,   false),
    new SimApData(apIdent[2], _hdg,  0, 1,     0,     360,    0.1),
    new SimApData(apIdent[3], _obs1, 0, 1,     0,     360,    0.1),
    new SimApData(apIdent[4], _obs2, 0, 1,     0,     360,    0.1),
    new SimApData(apIdent[5], _alt,  1),
    new SimApData(apIdent[6], _vvi,  1),
    new SimApData(apIdent[7], _hdg,  1) ,
    new SimApData(apIdent[7], _obs1, 1) ,
    new SimApData(apIdent[7], _obs2, 1)      };


#endif // ASSIGNAPDATA_H
