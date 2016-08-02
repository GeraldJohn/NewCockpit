#ifndef ASSIGNGPSCOM_H
#define ASSIGNGPSCOM_H

#include "SimGpsCom.h"

//! Gps Encoder -> GpsCom
DataRefIdent gpsComEncIdent[][58] = {
    "sim/GPS/g430n1_chapter_up",
    "sim/GPS/g430n1_chapter_dn",
    "sim/GPS/g430n1_page_up",
    "sim/GPS/g430n1_page_dn",
    "sim/GPS/g430n1_cursor",
    "sim/GPS/g430n1_popup"
};
//      SimGpsComData( ident,        Page, EncNr, EncSw, DownResp, &UpResp, &NKSt, hasPowerFlag, hasPowerFlag),
SimGpsBase *enc_gpsCom[] = {
    new SimGpsComData(gpsComEncIdent[0], 0, 0, 0, 0, 1),
    new SimGpsComData(gpsComEncIdent[1], 0, 0, 0, 1, 0),
    new SimGpsComData(gpsComEncIdent[2], 0, 1, 0, 0, 1),
    new SimGpsComData(gpsComEncIdent[3], 0, 1, 0, 1, 0),
    new SimGpsComData(gpsComEncIdent[4], 0, 0, 1),
    new SimGpsComData(gpsComEncIdent[5], 0, 1, 0),
};


#endif // ASSIGNGPSCOM_H

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


//! GPS Commands
//DataRefIdent gpsSignComIdent[][58] = {
//    "sim/FMS/key_0",
//    "sim/FMS/key_1",
//    "sim/FMS/key_2",
//    "sim/FMS/key_3",
//    "sim/FMS/key_4",
//    "sim/FMS/key_5",
//    "sim/FMS/key_6",
//    "sim/FMS/key_7",
//    "sim/FMS/key_8",
//    "sim/FMS/key_9",
//    "sim/FMS/key_A",
//    "sim/FMS/key_B",
//    "sim/FMS/key_C",
//    "sim/FMS/key_D",
//    "sim/FMS/key_E",
//    "sim/FMS/key_F",
//    "sim/FMS/key_G",
//    "sim/FMS/key_H",
//    "sim/FMS/key_I",
//    "sim/FMS/key_J",
//    "sim/FMS/key_K",
//    "sim/FMS/key_L",
//    "sim/FMS/key_M",
//    "sim/FMS/key_N",
//    "sim/FMS/key_O",
//    "sim/FMS/key_P",
//    "sim/FMS/key_Q",
//    "sim/FMS/key_R",
//    "sim/FMS/key_S",
//    "sim/FMS/key_T",
//    "sim/FMS/key_U",
//    "sim/FMS/key_V",
//    "sim/FMS/key_W",
//    "sim/FMS/key_X",
//    "sim/FMS/key_Y",
//    "sim/FMS/key_Z"
//};

//SimGpsBase *gpsSignCom[] = {
//    new SimGpsComData(gpsSignComIdent[0], 0),
//    new SimGpsComData(gpsSignComIdent[1], 0),
//    new SimGpsComData(gpsSignComIdent[2], 0),
//    new SimGpsComData(gpsSignComIdent[3], 0),
//    new SimGpsComData(gpsSignComIdent[4], 0),
//    new SimGpsComData(gpsSignComIdent[5], 0),
//    new SimGpsComData(gpsSignComIdent[6], 0),
//    new SimGpsComData(gpsSignComIdent[7], 0),
//    new SimGpsComData(gpsSignComIdent[8], 0),
//    new SimGpsComData(gpsSignComIdent[9], 0),
//    new SimGpsComData(gpsSignComIdent[10], 0),
//    new SimGpsComData(gpsSignComIdent[11], 0),
//    new SimGpsComData(gpsSignComIdent[12], 0),
//    new SimGpsComData(gpsSignComIdent[13], 0),
//    new SimGpsComData(gpsSignComIdent[14], 0),
//    new SimGpsComData(gpsSignComIdent[15], 0),
//    new SimGpsComData(gpsSignComIdent[16], 0),
//    new SimGpsComData(gpsSignComIdent[17], 0),
//    new SimGpsComData(gpsSignComIdent[18], 0),
//    new SimGpsComData(gpsSignComIdent[19], 0),
//    new SimGpsComData(gpsSignComIdent[20], 0),
//    new SimGpsComData(gpsSignComIdent[21], 0),
//    new SimGpsComData(gpsSignComIdent[22], 0),
//    new SimGpsComData(gpsSignComIdent[23], 0),
//    new SimGpsComData(gpsSignComIdent[24], 0),
//    new SimGpsComData(gpsSignComIdent[25], 0),
//    new SimGpsComData(gpsSignComIdent[26], 0),
//    new SimGpsComData(gpsSignComIdent[27], 0),
//    new SimGpsComData(gpsSignComIdent[28], 0),
//    new SimGpsComData(gpsSignComIdent[29], 0),
//    new SimGpsComData(gpsSignComIdent[30], 0),
//    new SimGpsComData(gpsSignComIdent[31], 0),
//    new SimGpsComData(gpsSignComIdent[32], 0),
//    new SimGpsComData(gpsSignComIdent[33], 0),
//    new SimGpsComData(gpsSignComIdent[34], 0),
//    new SimGpsComData(gpsSignComIdent[35], 0),
//    new SimGpsComData(gpsSignComIdent[36], 0) };

//DataRefIdent fmsMoveComIdent[][58] = {
//    "sim/FMS/type_apt",
//    "sim/FMS/type_vor",
//    "sim/FMS/type_ndb",
//    "sim/FMS/type_fix",
//    "sim/FMS/fix_next",
//    "sim/FMS/fix_prev"
//};

//SimGpsBase *gpsMoveCom[] = {
//    new SimGpsComData(fmsMoveComIdent[0], 0),
//    new SimGpsComData(fmsMoveComIdent[1], 0),
//    new SimGpsComData(fmsMoveComIdent[2], 0),
//    new SimGpsComData(fmsMoveComIdent[3], 0),
//    new SimGpsComData(fmsMoveComIdent[4], 0),
//    new SimGpsComData(fmsMoveComIdent[5], 0) };
//! Mögliche 8 Positionen in der Efis Anzeige
//int _active_pos[8][2] ={{0,9},{1,9},{3,9},{3,11},{3,13},{3,15},{3,17},{3,19}};
//_row = _active_pos[n][0];
//_pos = _active_pos[n][1];

