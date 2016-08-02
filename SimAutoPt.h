#ifndef SIMAUTOPT_H
#define SIMAUTOPT_H

#include "SimData.h"
#include "blink.h"
#include "HardLcd.h"
#include "HardEnc.h"



//! Deklaration class SimAutoPt
class SimAutoPt : public SimData {

    public:
        SimAutoPt(const char      *ident,
                  const uint8_t   &Mode,               //Zugehörigkeits Modus
                  const uint8_t   &Row = 0,            //Zeile im Lcd
                  const uint8_t   &CModeMax = 0,       //max Einstell Pos
                  const int16_t  &LowLimit = 0,       //für Parts
                  const int16_t  &UpLimit = 9,        //für Parts
                  const float     &Faktor = 1,         //für NKSt
                  const bool      &Jump = true,        //Überspringen an Upper/Lower Grenzwerten
                  const uint8_t   &NKSt = 0,           //Nachkommastellen
                  const bool      *hasPowerFlag = &SimObject::hasPower);

        FlightSimFloat _drFlt;
//        short _changemode;          //Pos der aktuellen Änderung
        uint8_t _cmodemax;
        static uint8_t _active_page;         //aktuell gewählter Modus
        static bool _print;
        static const String autopH[16];
        String _autopD;
        String _autopD_old;                          ///LCD Data Strings
//    static const int Ap_Mode[9];

    protected:
    private:
        uint8_t _mode, _row, ;
        int16_t _lower, _upper;
        bool _jump;
        float _faktor;

        void _setup(void);
        void _update(bool updateOutput);
        void _updateActive();
        void print_Lcd();
        void change_Date(); };

//!Initialisierung static
uint8_t SimAutoPt::_active_page = 0;
bool SimAutoPt::_print = true;

enum AP_Mode {
    _alt,
    _vvi,
    _hdg,
    _obs1,
    _obs2,
    Test_Mode1,
    Test_Mode2,
    Test_Mode3,
    _Count // automagically = 8,
};

/// Definition static String Array autopH[16]
const String SimAutoPt::autopH[16] = {          ///LCD Header Strings
    "Alt  :          ",
    "Alt *:          ",
    "VS   :          ",
    "VS  *:          ",
    "HDG  :          ",
    "HDG *:          ",
    "Crs1 :          ",
    "HDG *:          ",
    "Crs2 :          ",
    "HDG *:          ",
    "6. :            ",
    "nn :            ",
    "7. :            ",
    "nn :            ",
    "8. :            ",
    "nn :            "};


//! Definition class SimAutoPt
SimAutoPt::SimAutoPt(const char  *ident,
                     const uint8_t   &Mode,             //Zugehörigkeits Modus
                     const uint8_t   &Row,
                     const uint8_t   &CModeMax,         //max Einstell Pos
                     const int16_t   &LowLimit,         //für Parts
                     const int16_t   &UpLimit,          //für Parts
                     const float &Faktor,
                     const bool  &Jump,             //Überspringen an Grenzwerten
                     const uint8_t   &NKSt,
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

//! Definition Methode _setup
void SimAutoPt::_setup(void) {
    _autopD = String(int(_drFlt));
    _autopD_old = _autopD;
    _print = true; }

//! Definition Methode _update
void SimAutoPt::_update(bool updateOutput) {
    /// Ist der intern gesetzte Mode gleich dem aktiven Mode
    if (_mode == _active_page) {
        _autopD_old = _autopD;
        /// ApEncSw unter Null wird auf CModeMax gesetzt
        myApEncSw._Cmode_set < 0 ? myApEncSw._Cmode_set = _cmodemax : 0;

        /// Wurde der Encoder verändert ? Frequenzänderung wird aufgerufen
        if (myApEnc._diff != 0) {
            change_Date();                  //Wert_Ändern Methode
            myApEnc._diff = 0; }

        _autopD = String(int(_drFlt));       //Print String erzeugen

        if (_autopD != _autopD_old) {
            _print = true; }

        print_Lcd();                        //Ausdruck starten
    } //end if _mode == _active_page
} //end void


//! Definition Methode _updateActive
void SimAutoPt::_updateActive() {}

//! Definition Method change_Date
void SimAutoPt::change_Date() {
    _drFlt = _drFlt + (myApEnc._diff * pow(10, myApEncSw._Cmode_set + 1) * _faktor);

    if (_jump) {
        /// Wert an den Grenzen umspringen lassen
        if (_drFlt > _upper) {_drFlt = _drFlt - (_upper - _lower);}

        if (_drFlt < _lower) {_drFlt = _drFlt + (_upper - _lower);}          }
    else {
        /// Wert an den Grenzen stehen lassen
        if (_drFlt > _upper) {_drFlt = _upper;}

        if (_drFlt < _lower) {_drFlt = _lower;}          } } //end void

//! Definition SimAutoPt print_Lcd
void SimAutoPt::print_Lcd() {
    if (_print) {
        _print = false;
        blink::_blink = true ;
        Lcd1.setCursor(6, _row);
        Lcd1.print("         ");
        Lcd1.setCursor(12 - _autopD.length(), _row);         //15 - _autopD.length()
        Lcd1.print(_autopD); } }




#endif // SIMAutoPt_H
