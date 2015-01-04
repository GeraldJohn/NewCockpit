#ifndef SIMAPDATA_H
#define SIMAPDATA_H


#include "HardEnc.h"
#include "HardLcd.h"
#include "SimData.h"


class SimApData : public SimData {

public:
    SimApData(const char *ident,
              const int &Mode, //Zugehörigkeits Modus
              const uint8_t &Row = 0, //Zeile im Lcd
              const int &CModeMax = 0, //max Einstell Pos
              const int &LowLimit = 0, //für Parts
              const int &UpLimit = 9, //für Parts
              const float &Faktor = 1, //für NKSt
              const bool &Jump = true, //Überspringen an Grenzwerten
              const int &NKSt = 0,
              const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimFloat _drFlt;
    short _changemode; //Pos der aktuellen Änderung
    int _cmodemax;
    static int _active_mode; //aktuell gewählter Modus
    static bool _print;
    static const String autopH[16];
    String _autopD;
    String _autopD_old;
    // static const int Ap_Mode[9];

protected:
private:
    int _mode, i, _lower, _upper;
    uint8_t _row;
    bool _jump;
    float _faktor;

    void _setup(void);
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd();
    void change_Date(); };

int SimApData::_active_mode = 0;
bool SimApData::_print = true;

/*enum AP_Mode {
  _alt,
  _vvi,
  _hdg,
  _obs1,
  _obs2,
  Test_Mode1,
  Test_Mode2,
  Test_Mode3,
  _Count // automagically = 8,
 };*/

const String SimApData::autopH[16] = {
    "Alt : ",
    "Alt -: ",
    "VS : ",
    "VS -: ",
    "HDG : ",
    "HDG -: ",
    "Crs1 : ",
    "HDG -: ",
    "Crs2 : ",
    "HDG -: ",
    "6. : ",
    "nn : ",
    "7. : ",
    "nn : . ",
    "8. : ",
    "nn : " };


SimApData::SimApData(const char *ident,
                     const int &Mode, //Zugehörigkeits Modus
                     const uint8_t &Row,
                     const int &CModeMax, //max Einstell Pos
                     const int &LowLimit, //für Parts
                     const int &UpLimit, //für Parts
                     const float &Faktor,
                     const bool &Jump, //Überspringen an Grenzwerten
                     const int &NKSt,
                     const bool *hasPowerFlag
                     ) : SimData(NKSt, hasPowerFlag),
    _cmodemax(CModeMax),
    _mode(Mode),
    _lower(LowLimit),
    _upper(UpLimit),
    _faktor(Faktor),
    _jump(Jump),
    _row(Row)
{
    _drFlt.assign((const _XpRefStr_ *) ident);
}

void SimApData::_setup(void) {
    _autopD = String(int(_drFlt));
    _autopD_old = _autopD;
    _print = true; }

void SimApData::_update(bool updateOutput) {
    if (_mode == _active_mode) {
        _autopD_old = _autopD;
        myApEncSw._Cmode_set < 0 ? myApEncSw._Cmode_set = _cmodemax : 0;

        if (myApEnc._diff != 0) {
            change_Date(); //Wert_Ändern Methode
            myApEnc._diff = 0; }

        _autopD = String(int(_drFlt)); //Print String erzeugen

        if (_autopD != _autopD_old) {
            _print = true; }

        print_Lcd(); //Ausdruck starten
    } //end if _mode == _active_mode
} //end void


void SimApData::_updateActive() {}

void SimApData::change_Date() {
    _drFlt = _drFlt + (myApEnc._diff * pow(10, myApEncSw._Cmode_set + 1) * _faktor);

    if (_jump) {
        if (_drFlt > _upper) {_drFlt = _drFlt - (_upper - _lower);}

        if (_drFlt < _lower) {_drFlt = _drFlt + (_upper - _lower);} }
    else {
        if (_drFlt > _upper) {_drFlt = _upper;}

        if (_drFlt < _lower) {_drFlt = _lower;} } } //end void

void SimApData::print_Lcd() {
    if (_print) {
        _print = false;
        blink::_blink = true ;
        Lcd1.setCursor(6, _row);
        Lcd1.print(" ");
        Lcd1.setCursor(12 - _autopD.length(), _row); //15 - _autopD.length()
        Lcd1.print(_autopD); } }


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

SimData *apdata[] = {
    new SimApData(apIdent[0], 0, 0, 2, 0, 30000, 1, 0),
    new SimApData(apIdent[1], 1, 0, 0, -3000, 3000, 10, 0),
    new SimApData(apIdent[2], 2, 0, 1, 0, 360, 0.1),
    new SimApData(apIdent[3], 3, 0, 1, 0, 360, 0.1),
    new SimApData(apIdent[4], 4, 0, 1, 0, 360, 0.1),
    new SimApData(apIdent[5], 0, 1),
    new SimApData(apIdent[6], 1, 1),
    new SimApData(apIdent[7], 2, 1) ,
    new SimApData(apIdent[7], 3, 1) ,
    new SimApData(apIdent[7], 4, 1) };


#endif // SIMAPDATA_H
