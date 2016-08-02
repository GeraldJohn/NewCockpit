#ifndef SIMRADIO_DATA_H
#define SIMRADIO_DATA_H

#include "SimData.h"

//! Deklaration class SimRadioData
class SimRadioData : public SimData{

public:
    SimRadioData (const char *ident,
                  const int &Mode, //zugehöriger Modus
                  const int &Digits = 2,
                  const int &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimInteger _drInt;
    static int _pageSet;
    static bool _print;
    static bool _swaped;
    static FlightSimInteger _drInt_active;
    static const String radioH[9];
    String _radioD;
    static const int posRadioData;

private:
    int _mode;
    int _digits;
    int _nkst;

    void _update(bool updateOutput);
    void _updateActive();
    void Lcd_print();
};


//!Initialisierung static & Definition static String Array radio
int SimRadioData::_pageSet = 0;
bool SimRadioData::_print = true;
bool SimRadioData::_swaped = false;
//String SimRadioData::_radioD = "";
FlightSimInteger SimRadioData::_drInt_active;
const int SimRadioData::posRadioData = 7;

//!  RADIO Modes <= Mode RotarySwitch in ModeSwitch.ino
enum Radio_Modes {
    _com1,
    _com2,
    _nav1,
    _nav2,
    _adf1,
    _adf2,
    _atc,
    _test
};


const String SimRadioData::radioH[9] = {
    "Com1:           ",
    "Com2:           ",
    "Nav1:           ",
    "Nav2:           ",
    "ADF1:           ",
    "ADF2:           ",
    "ATC :           ",
    "Test:           ",
    "Stdb:           "};


//! Definition class SimRadioData
SimRadioData::SimRadioData(const char *ident,
                           const int &Mode,
                           const int &Digits,
                           const int &NKSt,
                           const bool *hasPowerFlag
                           ) : SimData(NKSt, hasPowerFlag),
    _mode(Mode),
    _digits(Digits),
    _nkst(NKSt)
{
    _drInt.assign((const _XpRefStr_ *)ident);
}



//! Deklaration class SimStbyRadioData
class SimStbyRadioData : public SimData{

public:
    SimStbyRadioData(const char *ident,
                     const int &Page, //zugehörige Seite
                     const int &Digits, //max Einstell Pos
                     const int &LowLimit = 0, //für Parts
                     const int &UpLimit = 9, //für Parts
                     const float &Step = 1, //für NKSt
                     const bool &Jump = true, //Überspringen an Grenzwerten
                     const int &NKSt = 0, //Anzahl der NKSt
                     const bool *hasPowerFlag = &SimObject::hasPower );

    FlightSimInteger _drInt;
 //   short _changemode; //Pos der aktuellen Änderung
    int _digits;
    static int _pageSet; //aktuell gewählter Modus
    static bool _print;  //soll drInt im Lcd gezeigt werden; plus: static drInt_active = drInt
    static bool _swap;
    static String _radioD;
    static FlightSimInteger _drInt_active;
    static const int posRadioData;

private:
    int _drInt_VK;
    int _drInt_NK;
    int _page;
    int _nkst;
    int _lower;
    int _upper;
    float _step;
    int _jump;
    void _update(bool updateOutput);
    void _updateActive();
    void Lcd_print();
    void change_Freq();
};//end Deklaration

//!Initialisierung static
int SimStbyRadioData::_pageSet = 0;
bool SimStbyRadioData::_print = false;
bool SimStbyRadioData::_swap = false;
String SimStbyRadioData::_radioD = "";
FlightSimInteger SimStbyRadioData::_drInt_active;
const int SimStbyRadioData::posRadioData = 7;

//! Definition class SimStbyRadioData
SimStbyRadioData::SimStbyRadioData(const char *ident,
                                   const int &Page,
                                   const int &Digits,
                                   const int &LowLimit,
                                   const int &UpLimit,
                                   const float &Step,
                                   const bool &Jump,
                                   const int &NKSt,
                                   const bool *hasPowerFlag
                                   ) : SimData(NKSt, hasPowerFlag),
    _digits(Digits),
    _page(Page),
    _nkst(NKSt),
    _lower(LowLimit),
    _upper(UpLimit),
    _step(Step),
    _jump(Jump)
{
    _drInt.assign((const _XpRefStr_ *) ident);
} //end constructor


//! Definition Methode _updateActive
void SimRadioData::_updateActive(){}

//! Definition Methode _update
void SimRadioData::_update(bool updateOutput){
    if (_mode == _pageSet){
        /// Stdby _swap == true =>
        if (_print){
            _print = false;
            _drInt_active = _drInt;
            Lcd_print();
        }

        /// SimRadioData._swaped == true => Frequenztausch aufrufen
        if (_swaped) {
            _swaped = false;
            _drInt = _drInt_active;
            Lcd_print();
        }
    }
}

//! Definition Methode Lcd_print()
void SimRadioData::Lcd_print(){

    if(_nkst){
        _radioD = String(_drInt);
        _radioD = _radioD.substring(0, 3) + "." + _radioD.substring(3); }

    else{
        _radioD = String(_drInt);
        while (_radioD.length() < _digits + 1) {
            _radioD = "0" + _radioD;
        }
    }

    Lcd0.setCursor (posRadioData, 0);
    Lcd0.print(_radioD);
    blink::_blink = true;
}


//! Definition Methode SimStbyRadioData::_updateActive
void SimStbyRadioData::_updateActive(){}

//! Definition Methode _update
void SimStbyRadioData::_update(bool updateOutput){

    /// Ist der inherente Mode gleich dem gesetzten Mode
    if (_page == _pageSet){

        /// RadioEncSw wird unter Null auf Digits gesetzt
        myRadioEncSw._Cmode_set < 0 ? myRadioEncSw._Cmode_set = _digits : 0;

        /// Wurde der Encoder verändert ? Frequenzänderung wird aufgerufen
        if (myRadioEnc._diff != 0) {
            change_Freq();
            myRadioEnc._diff = 0; }

        if (_print){
            _drInt_active = _drInt;
            Lcd_print();
        }

        /// Swap == true => Frequenztausch aufrufen
        if (_swap) {
            _swap = false;
            //! Die static active Frequences werden getauscht
            SimData::swap_Date(_drInt_active, SimRadioData::_drInt_active);
            /// inherente Frequenz erhält getauschten Wert
            _drInt = _drInt_active;
            SimRadioData::_swaped = true;
            Lcd_print();
        }


    } //end if _mode == _pageSet
} //end void



//! Definition Method change_Freq
void SimStbyRadioData::change_Freq(){
    if (_nkst){
        int i = _nkst;

        /// Vorkomma Teil erstellen
        _drInt_VK = _drInt / pow(10, i);

        /// Nachkomma Teil !
        _drInt_NK = (_drInt % int(pow(10, i)));

        _drInt_NK = (_drInt % int(pow(10, i))) * 10;

        /// If dataref value ends in 20 or 70 then reinstate missing 0.005 MHz
        _drInt_NK % 100 == 20 || _drInt_NK % 100 == 70 ? _drInt_NK += 5 : 0;

        /// Ist der Change Mode 1, dh. Vorkomma wert wird geändert
        if (myRadioEncSw._Cmode_set == 1){
            _drInt_VK += myRadioEnc._diff;
            _drInt_NK /= 10;

            ///Wert wird anhand der Grenzen Korrigiert
            while (_drInt_VK > _upper) {_drInt_VK = _lower;}
            while (_drInt_VK < _lower) {_drInt_VK = _upper;}


        } //end if Cmode_set 1

        /// ChangeMode_Set 0 => Nachkommastellen ändern
        else if (myRadioEncSw._Cmode_set == 0){
            _drInt_NK += myRadioEnc._diff * _step;
            _drInt_NK /= 10;
            /// Änderung an Vorkommateil unterbinden
            _drInt_NK >= pow(10, i) ? _drInt_NK = 0 : 0;
            _drInt_NK < 0 ? _drInt_NK = 100 - _step / 10 : 0;
        }//end else Cmode_set 0


        /// FlightSimInteger wiederherstellen
        _drInt = _drInt_VK * pow(10, i) + int(_drInt_NK);

    }//end if _nkst

    /// Keine NKSt
    //todo prüfen warum Sprünge auftreten
    else {
        /// lokal Array mit _codemax Teilen deklarieren
        int _drIntPart[_digits + 1];

        /// Aufteilung in Digits fache Teile
        for (int i = 0; i <= _digits; i++){
            _drIntPart[i] = _drInt % int(pow(10, i + 1)) / pow(10, i); }//end for

        /// Ändern des Teils der _modeset entspricht
        _drIntPart[myRadioEncSw._Cmode_set] += myRadioEnc._diff;

        /// Teil an den Grenzen umspringen lassen
        while (_drIntPart[myRadioEncSw._Cmode_set] > _upper) {_drIntPart[myRadioEncSw._Cmode_set] = _lower;}
        while (_drIntPart[myRadioEncSw._Cmode_set] < _lower) {_drIntPart[myRadioEncSw._Cmode_set] = _upper;}


        /// FlightSimInteger wiederherstellen -> 0, ++
        int _drIntTemp = 0;
        for (int j = 0; j <= _digits; j++){
            _drIntTemp = _drIntTemp + (_drIntPart[j] * int(pow(10, j)));
        }//end for
        _drInt = _drIntTemp;

    } //end else keine NkSt
    Lcd_print();
} //end void

//! Definition SimStbyRadioData Lcd_print
void SimStbyRadioData::Lcd_print(){

    if (_nkst){
        _radioD = String(_drInt);
        _radioD = _radioD.substring(0, 3) + "." + _radioD.substring(3);
    }
    else {
        _radioD = String(_drInt);
        while (_radioD.length() < _digits + 1) {
            _radioD = "0" + _radioD;
        }
    }

    /// RadioLcd zweite Zeile
    Lcd0.setCursor (posRadioData, 1);
    Lcd0.print(_radioD);
}

#endif // SIMRADIO_DATA_H
