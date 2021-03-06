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
 //   short _changemode;          //Pos der aktuellen Änderung
    int _cmodemax;
    static bool _print;

protected:
    String _gpsD, _gpsD_old;
private:
    int  i, _mode, _row, _pos, _lower, _upper, _jump;
    float _faktor;
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd();
};

//! define static
bool SimGpsFltData::_print = true;

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

////! Definition Methode _print_lcd
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




#endif // SIMGPSFLT_H
