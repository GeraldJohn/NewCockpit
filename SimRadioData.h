#ifndef SIMRADIO_DATA_H
#define SIMRADIO_DATA_H

#include "HardEnc.h"
#include "HardLcd.h"
#include "SimData.h"


class SimRadioData : public SimData{

public:
    SimRadioData (const char *ident,
                  const int &Mode, //zugehöriger Modus
                  const int &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimInteger _drInt;
    static int _modeSet;
    static bool _print;
    static bool _swap;
    static FlightSimInteger _drInt_active;
    static const String radioH[9];
    static String _radio_data;
    static const int posRadioData;

private:
    int _mode;
    int _nkst;

    void _update(bool updateOutput);
    void _updateActive();
    void prep_Lcd();
};

int SimRadioData::_modeSet = 0;
bool SimRadioData::_print = true;
bool SimRadioData::_swap = false;
String SimRadioData::_radio_data = "";
FlightSimInteger SimRadioData::_drInt_active;
const int SimRadioData::posRadioData = 7;

const String SimRadioData::radioH[9] = {
    "Com1: ",
    "Com2: ",
    "Nav1: ",
    "Nav2: ",
    "ADF1: ",
    "ADF2: ",
    "ATC : ",
    "Test: ",
    "Stdb: . " };


SimRadioData::SimRadioData(const char *ident,
                           const int &Mode, //Modus
                           const int &NKSt,
                           const bool *hasPowerFlag
                           ) : SimData(NKSt, hasPowerFlag),
    _mode(Mode),
    _nkst(NKSt)
{
    _drInt.assign((const _XpRefStr_ *)ident);
}



class SimStbyRadioData : public SimData{

public:
    SimStbyRadioData(const char *ident,
                     const int &Mode, //Zugehörigkeits Modus
                     const int &CModeMax, //max Einstell Pos
                     const int &LowLimit = 0, //für Parts
                     const int &UpLimit = 9, //für Parts
                     const float &Step = 1, //für NKSt
                     const bool &Jump = true, //Überspringen an Grenzwerten
                     const int &NKSt = 0, //Anzahl der NKSt
                     const bool *hasPowerFlag = &SimObject::hasPower );

    FlightSimInteger _drInt;
    short _changemode; //Pos der aktuellen Änderung
    int _cmodemax;
    static int _modeSet; //aktuell gewählter Modus
    static bool _print; //aktuell gewählter Modus
    static bool _swap;
    static String _radio_data;
    static FlightSimInteger _drInt_active;
    static const int posRadioData;

private:
    int _drInt_VK;
    int _drInt_NK;
    int _mode;
    int _nkst;
    int _lower;
    int _upper;
    float _step;
    int _jump;
    void _update(bool updateOutput);
    void _updateActive();
    void prep_Lcd();
    void change_Freq();
};//end Deklaration

int SimStbyRadioData::_modeSet = 0;
bool SimStbyRadioData::_print = true;
bool SimStbyRadioData::_swap = false;
String SimStbyRadioData::_radio_data = "";
FlightSimInteger SimStbyRadioData::_drInt_active;
const int SimStbyRadioData::posRadioData = 7;

SimStbyRadioData::SimStbyRadioData(const char *ident,
                                   const int &Mode,
                                   const int &CModeMax,
                                   const int &LowLimit,
                                   const int &UpLimit,
                                   const float &Step,
                                   const bool &Jump,
                                   const int &NKSt,
                                   const bool *hasPowerFlag
                                   ) : SimData(NKSt, hasPowerFlag),
    _cmodemax(CModeMax),
    _mode(Mode),
    _nkst(NKSt),
    _lower(LowLimit),
    _upper(UpLimit),
    _step(Step),
    _jump(Jump)
{
    _drInt.assign((const _XpRefStr_ *) ident);
} //end constructor


void SimRadioData::_updateActive(){}

void SimRadioData::_update(bool updateOutput){
    if (_mode == _modeSet){
        if (SimStbyRadioData::_swap){
            _drInt_active = _drInt; }

        if (_swap) {
            _swap = false;
            _drInt = _drInt_active;
            _print = true; }

        prep_Lcd();
    }
}

void SimRadioData::prep_Lcd(){
    if (_print){
        _print = false;

        if(_nkst){
            _radio_data = String(_drInt);
            _radio_data = _radio_data.substring(0, 3) + "." + _radio_data.substring(3); }

        else{
            _radio_data = String(_drInt); };


        Lcd0.setCursor (posRadioData, 0);
        Lcd0.print(_radio_data);
    }
}


void SimStbyRadioData::_updateActive(){}

void SimStbyRadioData::_update(bool updateOutput){

    if (_mode == _modeSet){

        myRadioEncSw._Cmode_set < 0 ? myRadioEncSw._Cmode_set = _cmodemax : 0;

        if (myRadioEnc._diff != 0) {
            change_Freq();
            myRadioEnc._diff = 0; }

        if (_swap) {
            _swap = false;
            _drInt_active = _drInt;
            SimData::swap_Date(_drInt_active, SimRadioData::_drInt_active);

            _drInt = _drInt_active;
            SimRadioData::_swap = true; }

        prep_Lcd();

    } //end if _mode == _modeSet
} //end void



void SimStbyRadioData::change_Freq(){
    if (_nkst){
        int i = _nkst;

        _drInt_VK = _drInt / pow(10, i);

        _drInt_NK = (_drInt % int(pow(10, i)));

        _drInt_NK = (_drInt % int(pow(10, i))) * 10;

        _drInt_NK % 100 == 20 || _drInt_NK % 100 == 70 ? _drInt_NK += 5 : 0;

        if (myRadioEncSw._Cmode_set == 1){
            _drInt_VK += myRadioEnc._diff;
            _drInt_NK /= 10;

            while (_drInt_VK > _upper) _drInt_VK = _lower;
            while (_drInt_VK < _lower) _drInt_VK = _upper;


        } //end if Cmode_set 1

        else if (myRadioEncSw._Cmode_set == 0){
            _drInt_NK += myRadioEnc._diff * _step;
            _drInt_NK /= 10;
            _drInt_NK >= pow(10, i) ? _drInt_NK = 0 : 0;
            _drInt_NK < 0 ? _drInt_NK = 100 - _step / 10 : 0;
        }//end else Cmode_set 0


        _drInt = _drInt_VK * pow(10, i) + int(_drInt_NK);

    }//end if _nkst

    //todo prüfen warum Sprünge auftreten
    else {
        int _drIntPart[_cmodemax + 1];

        for (int i = 0; i <= _cmodemax; i++){
            _drIntPart[i] = _drInt % int(pow(10, i + 1)) / pow(10, i); }//end for

        _drIntPart[myRadioEncSw._Cmode_set] += myRadioEnc._diff;

        while (_drIntPart[myRadioEncSw._Cmode_set] > _upper) {_drIntPart[myRadioEncSw._Cmode_set] = _lower;}
        while (_drIntPart[myRadioEncSw._Cmode_set] < _lower) {_drIntPart[myRadioEncSw._Cmode_set] = _upper;}


        _drInt = 0;
        for (int j = 0; j <= _cmodemax; j++){
            _drInt = _drInt + (_drIntPart[j] * int(pow(10, j))); }//end for

    } //end else keine NkSt
    prep_Lcd();
} //end void

void SimStbyRadioData::prep_Lcd(){

    if (_nkst){

        _radio_data = String(_drInt);
        _radio_data = _radio_data.substring(0, 3) + "." + _radio_data.substring(3); }


    /*

  String(_drInt % int(pow(10, _nkst))).length() > 2 ? _radio_data += "." : _radio_data += ".0";
  _radio_data += String(_drInt % int(pow(10, _nkst))); }
 */
    else {
        _radio_data = String(_drInt) + " "; }

    //blink::_blink = true ;
    Lcd0.setCursor (posRadioData, 1);
    Lcd0.print(_radio_data); }


DataRefIdent freqIdent[][58] = {
    "sim/cockpit2/radios/actuators/com1_frequency_hz",
    "sim/cockpit2/radios/actuators/com2_frequency_hz",
    "sim/cockpit2/radios/actuators/nav1_frequency_hz",
    "sim/cockpit2/radios/actuators/nav2_frequency_hz",
    "sim/cockpit2/radios/actuators/adf1_frequency_hz",
    "sim/cockpit2/radios/actuators/adf2_frequency_hz"
};

SimData *freq[] = {
    new SimRadioData(freqIdent[0], 0, 2),
    new SimRadioData(freqIdent[1], 1, 2),
    new SimRadioData(freqIdent[2], 2, 2),
    new SimRadioData(freqIdent[3], 3, 2),
    new SimRadioData(freqIdent[4], 4),
    new SimRadioData(freqIdent[5], 5) };

DataRefIdent freq_stbyIdent[][58] = {
    "sim/cockpit2/radios/actuators/com1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/com2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/nav1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/nav2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/adf1_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/adf2_standby_frequency_hz",
    "sim/cockpit2/radios/actuators/transponder_code"
};

SimData *freq_stby[] = {
    new SimStbyRadioData(freq_stbyIdent[0], 0, 1, 118, 136, 25, true, 2),
    new SimStbyRadioData(freq_stbyIdent[1], 1, 1, 118, 136, 25, true, 2),
    new SimStbyRadioData(freq_stbyIdent[2], 2, 1, 108, 117, 50, true, 2),
    new SimStbyRadioData(freq_stbyIdent[3], 3, 1, 108, 117, 50, true, 2),
    new SimStbyRadioData(freq_stbyIdent[4], 4, 2),
    new SimStbyRadioData(freq_stbyIdent[5], 5, 2),
    new SimStbyRadioData(freq_stbyIdent[6], 6, 3, 0, 7) };


#endif // SIMRADIO_DATA_H
