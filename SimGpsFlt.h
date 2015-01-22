#ifndef SIMGPSFLT_H
#define SIMGPSFLT_H

#include "SimGpsBase.h"



//! Deklaration class SimGpsFltData
class SimGpsFltData : public SimGpsBase {

public:
    SimGpsFltData(const char  *ident,
                  const int   &Mode,             //Zugehörigkeits Modus
                  const int   &Row = 0,
                  const int   &Pos = 9,
                  const int   &CModeMax = 1,         //max Einstell Pos
                  const int   &LowLimit = 0,     //für Parts
                  const int   &UpLimit = 9,      //für Parts
                  const float &Faktor = 1,         //für NKSt
                  const bool  &Jump = true,       //Überspringen an Grenzwerten
                  const int   &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimFloat _drFlt;
    short _changemode;          //Pos der aktuellen Änderung
    int _cmodemax;

protected:
    String _gpsD, _gpsD_old;
private:
    int  i, _mode, _row, _pos, _lower, _upper, _jump;
    float _faktor;
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd();
};



//! Definition class SimGpsFltData
SimGpsFltData::SimGpsFltData(const char  *ident,
                             const int   &Mode,             //Zugehörigkeits Modus
                             const int   &Row,
                             const int   &Pos,
                             const int   &CModeMax,         //max Einstell Pos
                             const int   &LowLimit,         //für Parts
                             const int   &UpLimit,          //für Parts
                             const float &Faktor,
                             const bool  &Jump,             //Überspringen an Grenzwerten
                             const int   &NKSt,
                             const bool *hasPowerFlag
                             ) : SimGpsBase(NKSt, hasPowerFlag),
    _mode(Mode),
    _row(Row),
    _pos(Pos),
    _cmodemax(CModeMax),
    _lower(LowLimit),
    _upper(UpLimit),
    _faktor(Faktor),
    _jump(Jump)
{
    _drFlt.assign((const _XpRefStr_ *)ident);
}

//! Definition Methode _update
void SimGpsFltData::_update(bool updateOutput){

    /// Ist der intern gesetzte Mode gleich dem aktiven Mode
    if (_mode == _active_page){
        _gpsD_old = _gpsD;

        _gpsD = String(_drFlt);       //Print String erzeugen

        if (_gpsD != _gpsD_old){
            _print = true;
        }
        print_Lcd();

    }
}//end void

//! Definition Methode _updateActive
void SimGpsFltData::_updateActive(){}

//! Definition Methode _print_lcd
void SimGpsFltData::print_Lcd(){
    if (_print) {
        _print = false;
        blink::_blink = true ;

        /// -> Lcd
        Lcd2.setCursor (10, _row);
        Lcd2.print("         ");
        Lcd2.setCursor (_pos, _row);        //15 - _gpsD.length()
        Lcd2.print(_gpsD);
    }
}



//! GPS & EFIS? things  Float
DataRefIdent gpsFltIdent[][58] = {
    "sim/cockpit2/radios/indicators/gps_bearing_deg_mag",
    "sim/cockpit2/radios/indicators/gps_dme_distance_nm",
    "sim/cockpit2/radios/indicators/gps_dme_time_min",
    "sim/cockpit2/radios/indicators/gps_dme_speed_kts",
    "sim/cockpit/misc/barometer_setting"
};


//!                       *ident, Mode, Row, CModeMax, LowLimit, UpLimit, Faktor, Jump, NKSt, hasPowerFlag,
SimGpsBase *gpsFltData[] = {
    new SimGpsFltData(gpsFltIdent[0], 0, 1),
    new SimGpsFltData(gpsFltIdent[1], 0, 2),
    new SimGpsFltData(gpsFltIdent[2], 0, 3),
    new SimGpsFltData(gpsFltIdent[3], -1, -1),
    new SimGpsFltData(gpsFltIdent[4], 2, 0, 7) };

#endif // SIMGPSFLT_H
