#ifndef ASSIGNGPSCOM_H
#define ASSIGNGPSCOM_H

#include "SimGpsBase.h"
#include "SimGpsCom.h"
#include "HardEnc.h"
#include "SimSwitch.h"

//! Gps Encoder -> GpsCom
DataRefIdent gpsComEncIdent[][58] = {
    "sim/GPS/g430n1_chapter_up",
    "sim/GPS/g430n1_chapter_dn",
    "sim/GPS/g430n1_page_up",
    "sim/GPS/g430n1_page_dn",
    "sim/GPS/g430n1_cursor",
    "sim/GPS/g430n1_popup"  };
SimGpsBase *enc_gpsCom[] = {
    new SimGpsComData(gpsComEncIdent[0], 0, 0),
    new SimGpsComData(gpsComEncIdent[1], 0, 0),
    new SimGpsComData(gpsComEncIdent[2], 0, 1),
    new SimGpsComData(gpsComEncIdent[3], 0, 1),
    new SimGpsComData(gpsComEncIdent[4], 0, 0),
    new SimGpsComData(gpsComEncIdent[5], 0, 1),
};



//    "sim/GPS/g430n1_coarse_down",
//    "sim/GPS/g430n1_coarse_up",
//    "sim/GPS/g430n1_fine_down",
//    "sim/GPS/g430n1_fine_up",
//    "sim/GPS/g430n1_nav_com_tog",
//    "sim/GPS/g430n1_com_ff",
//    "sim/GPS/g430n1_nav_ff", };




//    new SimSwitchCom(gpsComIdent[12], 0),
//    new SimSwitchCom(gpsComIdent[13], 0),
//    new SimSwitchCom(gpsComIdent[14], 0),
//    new SimSwitchCom(gpsComIdent[15], 0),
//    new SimSwitchCom(gpsComIdent[16], 0),
//    new SimSwitchCom(gpsComIdent[17], 0),
//    new SimSwitchCom(gpsComIdent[18], 0),
//    new SimSwitchCom(gpsComIdent[19], 0),
//    new SimSwitchCom(gpsComIdent[20], 0),
//    new SimSwitchCom(gpsComIdent[21], 0),
//    new SimSwitchCom(gpsComIdent[22], 0),
//    new SimSwitchCom(gpsComIdent[23], 0),
//    new SimSwitchCom(gpsComIdent[24], 0) };


#endif // ASSIGNGPSCOM_H
