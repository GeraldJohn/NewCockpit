#ifndef SIMGPSLOCAL_H
#define SIMGPSLOCAL_H

#include "SimGpsBase.h"
#include "HardLcd.h"
#include "SimLed.h"
#include "HardSwitch.h"

//! Deklaration class SimGpsLocal
class SimGpsLocal : public SimGpsBase {

public:
    SimGpsLocal  (byte  *source,
                  const int   &Mode = 0,               //Zugehörigkeits Modus
                  const int   &Row = 0,
                  const int   &Pos = 9,
                  const int   &NKSt = 0,
                  const bool  *hasPowerFlag = &SimObject::hasPower);

protected:
    String _gpsD = "", _gpsD_old = "";
private:
    int  _mode, _row, _pos;
    static short _active_row;

    byte _source;

    void _setup(void);
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd(); };

//! Definition class SimGpsLocal
SimGpsLocal::SimGpsLocal( byte *source,
                         const int  &Mode,             //Zugehörigkeits Modus
                         const int  &Row,
                         const int  &Pos,
                         const int  &NKSt,
                         const bool *hasPowerFlag
                         ) : SimGpsBase(NKSt, hasPowerFlag),
    _mode(Mode),
    _row(Row),
    _pos(Pos),
    _source(*source)
{ }

//! Definition Methode _setup
void SimGpsLocal::_setup(void) {}

//! Definition Methode _update
void SimGpsLocal::_update(bool updateOutput){

    /// Ist der interne Mode gleich dem aktiven Mode
    //if (_mode == _active_mode){
    // _gpsD_old = _gpsD;

        //!Led Check_Mode:
    if (_active_mode == 7){

            //!led_byte Anzeige
        //String led_byte_D[6];

        //for (int i = 0; i < 6; i++){
        _gpsD = String(_source , BIN);

        while (_gpsD.length() < 8){_gpsD = "0" + _gpsD;}


        //Lcd2.setCursor (_pos, _row);
        //Lcd2.print (_gpsD);

        Lcd2.setCursor (0, 1);
        Lcd2.print (String(SimLEDBase::_led_byte[0], BIN));
        Lcd2.setCursor (0, 2);
        Lcd2.print (String(SimLEDBase::_led_byte[1], BIN));
        Lcd2.setCursor (0, 3);
        Lcd2.print (String(SimLEDBase::_led_byte[2], BIN));
        Lcd2.setCursor (10, 1);
        Lcd2.print (String(SimLEDBase::_led_byte[3], BIN));
        Lcd2.setCursor (10, 2);
        Lcd2.print (String(SimLEDBase::_led_byte[4], BIN));
        Lcd2.setCursor (10, 3);
        Lcd2.print (String(SimLEDBase::_led_byte[5], BIN));
    }

        //!Sw Check_Mode:
    if (_active_mode == 5){

            //!sw_byte Anzeige
        //String led_byte_D[6];

        //for (int i = 0; i < 6; i++){
        _gpsD = String(_source , BIN);

        while (_gpsD.length() < 8){_gpsD = "0" + _gpsD;}


        //Lcd2.setCursor (_pos, _row);
        //Lcd2.print (_gpsD);

        Lcd2.setCursor (0, 1);
        Lcd2.print (String(HardSwitch::sw_byte[0], BIN));
        Lcd2.setCursor (0, 2);
        Lcd2.print (String(HardSwitch::sw_byte[1], BIN));
        Lcd2.setCursor (0, 3);
        Lcd2.print (String(HardSwitch::sw_byte[2], BIN));
        Lcd2.setCursor (10, 1);
        Lcd2.print (String(HardSwitch::sw_byte[3], BIN));
        Lcd2.setCursor (10, 2);
        Lcd2.print (String(HardSwitch::sw_byte[4], BIN));
    }

        //!SW Check_Mode2:
    if (_active_mode == 6){

            //!Sw_byte Anzeige
        //String led_byte_D[6];

        //for (int i = 0; i < 6; i++){
        _gpsD = String(_source , BIN);

        while (_gpsD.length() < 8){_gpsD = "0" + _gpsD;}


        //Lcd2.setCursor (_pos, _row);
        //Lcd2.print (_gpsD);

        Lcd2.setCursor (0, 1);
        Lcd2.print (String(HardSwitch::sw_byte[5], BIN));
        Lcd2.setCursor (0, 2);
        Lcd2.print (String(HardSwitch::sw_byte[6], BIN));
        Lcd2.setCursor (0, 3);
        Lcd2.print (String(HardSwitch::sw_byte[7], BIN));
        Lcd2.setCursor (10, 1);
        Lcd2.print (String(HardSwitch::sw_byte[8], BIN));
        Lcd2.setCursor (10, 2);
        Lcd2.print (String(HardSwitch::sw_byte[9], BIN));
    }
}



void SimGpsLocal::_updateActive(){}

SimGpsBase *gpslocal_led[6] = {
    new SimGpsLocal(&SimLEDBase::_led_byte[0], 7, 1, 0),
    new SimGpsLocal(&SimLEDBase::_led_byte[1], 7, 2, 0),
    new SimGpsLocal(&SimLEDBase::_led_byte[2], 7, 3, 0),
    new SimGpsLocal(&SimLEDBase::_led_byte[3], 7, 1, 12),
    new SimGpsLocal(&SimLEDBase::_led_byte[4], 7, 2, 12),
    new SimGpsLocal(&SimLEDBase::_led_byte[5], 7, 3, 12),
};

#endif // SIMGPSLOCAL_H
