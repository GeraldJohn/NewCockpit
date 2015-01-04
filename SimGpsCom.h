#ifndef SIMGPSCOM_H
#define SIMGPSCOM_H

#include "SimGpsBase.h"

class SimGpsComData : public SimGpsBase {

public:
    SimGpsComData(const char *ident,
                  const int &Mode, //Zugehörigkeits Modus
                  const int &Row = 0,
                  const int &CModeMax = 1, //max Einstell Pos
                  const int &LowLimit = 0, //für Parts
                  const int &UpLimit = 9, //für Parts
                  const float &Faktor = 1, //für NKSt
                  const bool &Jump = true, //Überspringen an Grenzwerten
                  const int &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimCommand _drCom;
    short _changemode; //Pos der aktuellen Änderung
    int _cmodemax;

protected:
    String _gpsD;
private:
    int i, _mode, _row, _lower, _upper, _jump;
    float _faktor;
    void _update(bool updateOutput);
    void _updateActive(); };

SimGpsComData::SimGpsComData(const char *ident,
                             const int &Mode, //Zugehörigkeits Modus
                             const int &Row,
                             const int &CModeMax, //max Einstell Pos
                             const int &LowLimit, //für Parts
                             const int &UpLimit, //für Parts
                             const float &Faktor,
                             const bool &Jump, //Überspringen an Grenzwerten
                             const int &NKSt,
                             const bool *hasPowerFlag
                             ) : SimGpsBase(NKSt, hasPowerFlag),
    _cmodemax(CModeMax),
    _mode(Mode),
    _row(Row),
    _lower(LowLimit),
    _upper(UpLimit),
    _faktor(Faktor),
    _jump(Jump)
{
    _drCom.assign((const _XpRefStr_ *)ident);
}

void SimGpsComData::_update(bool updateOutput) {} //end void

void SimGpsComData::_updateActive() {}


DataRefIdent gpsSignComIdent[][58] = {
    // "sim/FMS/key_0",
    // "sim/FMS/key_1",
    // "sim/FMS/key_2",
    // "sim/FMS/key_3",
    // "sim/FMS/key_4",
    // "sim/FMS/key_5",
    // "sim/FMS/key_6",
    // "sim/FMS/key_7",
    // "sim/FMS/key_8",
    // "sim/FMS/key_9",
    // "sim/FMS/key_A",
    // "sim/FMS/key_B",
    // "sim/FMS/key_C",
    // "sim/FMS/key_D",
    // "sim/FMS/key_E",
    // "sim/FMS/key_F",
    // "sim/FMS/key_G",
    // "sim/FMS/key_H",
    // "sim/FMS/key_I",
    // "sim/FMS/key_J",
    // "sim/FMS/key_K",
    // "sim/FMS/key_L",
    // "sim/FMS/key_M",
    // "sim/FMS/key_N",
    // "sim/FMS/key_O",
    // "sim/FMS/key_P",
    // "sim/FMS/key_Q",
    // "sim/FMS/key_R",
    // "sim/FMS/key_S",
    // "sim/FMS/key_T",
    // "sim/FMS/key_U",
    // "sim/FMS/key_V",
    // "sim/FMS/key_W",
    // "sim/FMS/key_X",
    // "sim/FMS/key_Y",
    // "sim/FMS/key_Z"
};

SimGpsBase *gpsSignCom[] = {
    new SimGpsComData(gpsSignComIdent[0], 0),
    new SimGpsComData(gpsSignComIdent[1], 0),
    new SimGpsComData(gpsSignComIdent[2], 0),
    new SimGpsComData(gpsSignComIdent[3], 0),
    new SimGpsComData(gpsSignComIdent[4], 0),
    new SimGpsComData(gpsSignComIdent[5], 0),
    new SimGpsComData(gpsSignComIdent[6], 0),
    new SimGpsComData(gpsSignComIdent[7], 0),
    new SimGpsComData(gpsSignComIdent[8], 0),
    new SimGpsComData(gpsSignComIdent[9], 0),
    new SimGpsComData(gpsSignComIdent[10], 0),
    new SimGpsComData(gpsSignComIdent[11], 0),
    new SimGpsComData(gpsSignComIdent[12], 0),
    new SimGpsComData(gpsSignComIdent[13], 0),
    new SimGpsComData(gpsSignComIdent[14], 0),
    new SimGpsComData(gpsSignComIdent[15], 0),
    new SimGpsComData(gpsSignComIdent[16], 0),
    new SimGpsComData(gpsSignComIdent[17], 0),
    new SimGpsComData(gpsSignComIdent[18], 0),
    new SimGpsComData(gpsSignComIdent[19], 0),
    new SimGpsComData(gpsSignComIdent[20], 0),
    new SimGpsComData(gpsSignComIdent[21], 0),
    new SimGpsComData(gpsSignComIdent[22], 0),
    new SimGpsComData(gpsSignComIdent[23], 0),
    new SimGpsComData(gpsSignComIdent[24], 0),
    new SimGpsComData(gpsSignComIdent[25], 0),
    new SimGpsComData(gpsSignComIdent[26], 0),
    new SimGpsComData(gpsSignComIdent[27], 0),
    new SimGpsComData(gpsSignComIdent[28], 0),
    new SimGpsComData(gpsSignComIdent[29], 0),
    new SimGpsComData(gpsSignComIdent[30], 0),
    new SimGpsComData(gpsSignComIdent[31], 0),
    new SimGpsComData(gpsSignComIdent[32], 0),
    new SimGpsComData(gpsSignComIdent[33], 0),
    new SimGpsComData(gpsSignComIdent[34], 0),
    new SimGpsComData(gpsSignComIdent[35], 0),
    new SimGpsComData(gpsSignComIdent[36], 0) };

DataRefIdent gpsMoveComIdent[][58] = {
    // "sim/FMS/type_apt",
    // "sim/FMS/type_vor",
    // "sim/FMS/type_ndb",
    // "sim/FMS/type_fix",
    // "sim/FMS/fix_next",
    // "sim/FMS/fix_prev"
};

SimGpsBase *gpsMoveCom[] = {
    new SimGpsComData(gpsMoveComIdent[0], 0),
    new SimGpsComData(gpsMoveComIdent[1], 0),
    new SimGpsComData(gpsMoveComIdent[2], 0),
    new SimGpsComData(gpsMoveComIdent[3], 0),
    new SimGpsComData(gpsMoveComIdent[4], 0),
    new SimGpsComData(gpsMoveComIdent[5], 0) };



#endif // SIMGPSCOM_H
