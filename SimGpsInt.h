#ifndef SIMGPSINT_H
#define SIMGPSINT_H

#include "SimGpsBase.h"
#include "HardEnc.h"
#include "blink.h"

class SimGpsIntData : public SimGpsBase {

public:
    SimGpsIntData(const char *ident,
                  const int &Page, //Zugehörigkeits Modus
                  const int &Row = 0,
                  const int &Pos = 9,
                  const int &CModeMax = 1, //max Einstell Pos
                  const int &LowLimit = 0, //für Parts
                  const int &UpLimit = 9, //für Parts
                  const float &Faktor = 1, //für NKSt
                  const bool &Jump = true, //Überspringen an Grenzwerten
                  const int &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimInteger _drInt;
    short _changemode; //Pos der aktuellen Änderung
    int _cmodemax;

protected:
    String _gpsD = "", _gpsD_old = "";
private:
    int _page, _row, _pos, _lower, _upper, _jump, _faktor;
    static short _active_row;

    void _setup(void);
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd();
    void change_Date();
};//end class

short SimGpsIntData::_active_row = 0;


SimGpsIntData::SimGpsIntData(const char *ident,
                             const int &Page, //Zugehörigkeits Modus
                             const int &Row,
                             const int &Pos,
                             const int &CModeMax, //max Einstell Pos
                             const int &LowLimit, //für Parts
                             const int &UpLimit, //für Parts
                             const float &Faktor,
                             const bool &Jump, //Überspringen an Grenzwerten
                             const int &NKSt,
                             const bool *hasPowerFlag
                             ) : SimGpsBase(NKSt, hasPowerFlag),
    _page(Page),
    _row(Row),
    _pos(Pos),
    _cmodemax(CModeMax),
    _lower(LowLimit),
    _upper(UpLimit),
    _faktor(Faktor),
    _jump(Jump)
{
    _drInt.assign((const _XpRefStr_ *) ident);
}

void SimGpsIntData::_setup(void) {}

void SimGpsIntData::_update(bool updateOutput){

    if (_page == _active_mode){

        if (_page == 0 & _row == 0){ //
            switch (_drInt) {
            case 1: _gpsD = "Airport "; break;
            case 2: _gpsD = "NDB "; break;
            case 4: _gpsD = "VOR "; break;
            case 11: _gpsD = "Fix "; break;
            case 12: _gpsD = "VOR "; break;
            default: _gpsD = "Unknown "; break; } }

        if (_page == 1){

            if (_row == 0){

                if (_row == _active_row){
                    if(myGps1Enc._diff){
                        change_Date();
                        blink::_blink = true;
                        _gpsD = String(int(10 * pow(2, _drInt))) + " ";
                    }//end if _diff
                }// end if _row == _active_row
            }// end if _row == 0

            if (_row == 1){
                switch (_drInt) {
                case 0: _gpsD = "APP"; break;
                case 1: _gpsD = "VOR"; break;
                case 2: _gpsD = "MAP"; break;
                case 3: _gpsD = "NAV"; break;
                case 4: _gpsD = "PLN"; break;
                default: break;
                }//end switch
            }//end if row == 1

            if (_row == 3){
                if(_drInt){_gpsD = "%";}
                else{_gpsD = " ";}
            }//end if row == 3
        }//end if page == 1 dh Efis

        if (_gpsD != _gpsD_old){
            _print = true;

            _gpsD_old = _gpsD;
        }
        print_Lcd();
    }//end if _page == _activemode
}//end void

void SimGpsIntData::_updateActive(){}

void SimGpsIntData::change_Date() {
    _drInt = _drInt + (myGps1Enc._diff * pow(10, myGps1EncSw._Cmode_set + 1) * _faktor);

    if (_jump) {
        if (_drInt > _upper) {_drInt = _drInt - _upper - _lower + 1;}

        if (_drInt < _lower) {_drInt = _drInt + _upper - _lower + 1;} }
    else {
        if (_drInt > _upper) {_drInt = _upper;}

        if (_drInt < _lower) {_drInt = _lower;} }
} //end void


void SimGpsIntData::print_Lcd(){
    if (_print) {
        _print = false;
        blink::_blink = true ;

        // Lcd2.setCursor (9, _row);
        // Lcd2.print(" ");
        Lcd2.setCursor (_pos, _row); //15 - _gpsD.length()
        //Lcd2.blink();
        Lcd2.print(_gpsD);
    }
}

#endif // SIMGPSINT_H
