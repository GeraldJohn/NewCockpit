#ifndef ASSIGNGPSFLT_H
#define ASSIGNGPSFLT_H

#include "SimGpsFlt.h"

//! GPS & EFIS? things  Float
DataRefIdent gpsFltIdent[][58] = {
    "sim/cockpit2/radios/indicators/gps_bearing_deg_mag",
    "sim/cockpit2/radios/indicators/gps_dme_distance_nm",
    "sim/cockpit2/radios/indicators/gps_dme_time_min",
    "sim/cockpit2/radios/indicators/gps_dme_speed_kts",
    "sim/cockpit/misc/barometer_setting"
};

//!                       *ident, Page, Row, CModeMax, LowLimit, UpLimit, Faktor, Jump, NKSt, hasPowerFlag,
SimGpsBase *gpsFltData[] = {
    new SimGpsFltData(gpsFltIdent[0], 0, 1),
    new SimGpsFltData(gpsFltIdent[1], 0, 2),
    new SimGpsFltData(gpsFltIdent[2], 0, 3),
    new SimGpsFltData(gpsFltIdent[3], -1, -1),
    new SimGpsFltData(gpsFltIdent[4], 2, 0, 7) };

#endif // ASSIGNGPSFLT_H
