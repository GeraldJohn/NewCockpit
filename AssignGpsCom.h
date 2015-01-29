#ifndef ASSIGNGPSCOM_H
#define ASSIGNGPSCOM_H

#include "SimGpsBase.h"
#include "SimGpsCom.h"

//! GPS Commands
DataRefIdent gpsComIdent[][58] = {
    "sim/GPS/g430n1_zoom_in",           //RNG^
    "sim/GPS/g430n1_zoom_out",          //RNG_dn
    "sim/GPS/g430n1_nav_com_tog",       //PUSH C/V
    "sim/GPS/g430n1_obs",               //OBS BUTTON
    "sim/GPS/g430n1_msg",               //MSG BUTTON
    "sim/GPS/g430n1_fpl",               //FLP BUTTON
    "sim/GPS/g430n1_proc",              //PROC BUTTON
    "sim/GPS/g430n1_direct",            //
    "sim/GPS/g430n1_menu",
    "sim/GPS/g430n1_clr",
    "sim/GPS/g430n1_ent",
    "sim/GPS/g430n1_com_ff",
    "sim/GPS/g430n1_nav_ff",
    "sim/GPS/g430n1_chapter_up",
    "sim/GPS/g430n1_chapter_dn",
    "sim/GPS/g430n1_page_up",
    "sim/GPS/g430n1_page_dn",
    "sim/GPS/g430n2_zoom_in",
    "sim/GPS/g430n2_zoom_out",
    "sim/GPS/g430n2_nav_com_tog",
    "sim/GPS/g430n2_cdi",
    "sim/GPS/g430n2_obs",
    "sim/GPS/g430n2_msg",
    "sim/GPS/g430n2_fpl",
    "sim/GPS/g430n2_proc",
    "sim/GPS/g430n2_direct",
    "sim/GPS/g430n2_menu",
    "sim/GPS/g430n2_clr",
    "sim/GPS/g430n2_ent",
    "sim/GPS/g430n2_com_ff",
    "sim/GPS/g430n2_nav_ff",
    "sim/GPS/g430n2_chapter_up",
    "sim/GPS/g430n2_chapter_dn",
    "sim/GPS/g430n2_page_up",
    "sim/GPS/g430n2_page_dn"
};

SimGpsBase *gpsCom[] = {
    new SimGpsComData(gpsComIdent[0], 0),
    new SimGpsComData(gpsComIdent[1], 0),
    new SimGpsComData(gpsComIdent[2], 0),
    new SimGpsComData(gpsComIdent[3], 0),
    new SimGpsComData(gpsComIdent[4], 0),
    new SimGpsComData(gpsComIdent[5], 0),
    new SimGpsComData(gpsComIdent[6], 0),
    new SimGpsComData(gpsComIdent[7], 0),
    new SimGpsComData(gpsComIdent[8], 0),
    new SimGpsComData(gpsComIdent[9], 0),
    new SimGpsComData(gpsComIdent[10], 0),
    new SimGpsComData(gpsComIdent[11], 0),
    new SimGpsComData(gpsComIdent[12], 0),
    new SimGpsComData(gpsComIdent[13], 0),
    new SimGpsComData(gpsComIdent[14], 0),
    new SimGpsComData(gpsComIdent[15], 0),
    new SimGpsComData(gpsComIdent[16], 0),
    new SimGpsComData(gpsComIdent[17], 0),
    new SimGpsComData(gpsComIdent[18], 0),
    new SimGpsComData(gpsComIdent[19], 0),
    new SimGpsComData(gpsComIdent[20], 0),
    new SimGpsComData(gpsComIdent[21], 0),
    new SimGpsComData(gpsComIdent[22], 0),
    new SimGpsComData(gpsComIdent[23], 0),
    new SimGpsComData(gpsComIdent[24], 0),
    new SimGpsComData(gpsComIdent[25], 0),
    new SimGpsComData(gpsComIdent[26], 0),
    new SimGpsComData(gpsComIdent[27], 0),
    new SimGpsComData(gpsComIdent[28], 0),
    new SimGpsComData(gpsComIdent[29], 0),
    new SimGpsComData(gpsComIdent[30], 0),
    new SimGpsComData(gpsComIdent[31], 0),
    new SimGpsComData(gpsComIdent[32], 0),
    new SimGpsComData(gpsComIdent[33], 0),
    new SimGpsComData(gpsComIdent[34], 0),
    new SimGpsComData(gpsComIdent[35], 0),
    new SimGpsComData(gpsComIdent[36], 0) };


#endif // ASSIGNGPSCOM_H
