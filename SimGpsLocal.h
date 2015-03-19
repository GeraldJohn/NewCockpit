#ifndef SIMGPSLOCAL_H
#define SIMGPSLOCAL_H

#include "SimGpsBase.h"
#include "HardLcd.h"
#include "SimLed.h"
#include "HardSwitch.h"
#include "blink.h"

class SimGpsLocal : public SimGpsBase {

public:
    SimGpsLocal (byte &source,
                 const int &Page = 0, //Zugehörigkeits Modus
                 const int &Row = 0,
                 const int &Pos = 9,
                 const int &NKSt = 0,
                 const bool *hasPowerFlag = &SimObject::hasPower);

protected:
    String _gpsD = "", _gpsD_old = "";
    byte _source;
private:
    int _page, _row, _pos;
    static short _active_row;



    void _setup(void);
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd(); };

SimGpsLocal::SimGpsLocal (byte &source,
                          const int &Page, //Zugehörigkeits Modus
                          const int &Row,
                          const int &Pos,
                          const int &NKSt,
                          const bool *hasPowerFlag
                          ) : SimGpsBase(NKSt, hasPowerFlag),
    _source(source),
    _page(Page),
    _row(Row),
    _pos(Pos)

{ }

void SimGpsLocal::_setup(void) {}

void SimGpsLocal::_update(bool updateOutput){

    if (_page == _active_page){
        _gpsD_old = _gpsD;
        _gpsD = String(_source, BIN);

        //for (int i = 0; i < 6; i++){
        //led_byte_D[i] = String(SimLEDBase::_led_byte[i] , BIN);

        while (_gpsD.length() < 8){_gpsD = "0" + _gpsD;}
        //}

        if (_gpsD_old != _gpsD) {
            Lcd2.setCursor (_pos, _row);
            Lcd2.print (_gpsD);
            blink::_blink = true;
        }
    }

/*   Vorsicht funktioniert!!
    if (_active_page == 5 || _active_page == 6){
        ///Definition String array sw_byte_D
        String sw_byte_D[10];

        ///_sw_byte to String
        for (int i = 0; i < 10; i++){
            sw_byte_D[i] = String(HardSwitch::sw_byte[i], BIN);

            ///Erhöhung auf acht Stellen
            while (sw_byte_D[i].length() < 8){sw_byte_D[i] = "0" + sw_byte_D[i];}
        }

        if (_active_page == 5) {
            Lcd2.setCursor (0, 1);
            Lcd2.print (sw_byte_D[0]);
            Lcd2.setCursor (0, 2);
            Lcd2.print (sw_byte_D[1]);
            Lcd2.setCursor (0, 3);
            Lcd2.print (sw_byte_D[2]);
            Lcd2.setCursor (10, 1);
            Lcd2.print (sw_byte_D[3]);
            Lcd2.setCursor (10, 2);
            Lcd2.print (sw_byte_D[4]);
            Lcd2.setCursor (10, 3);
            Lcd2.print (sw_byte_D[5]);
        }//end page 5

        if (_active_page == 6){
            Lcd2.setCursor (0, 1);
            Lcd2.print (sw_byte_D[4]);
            Lcd2.setCursor (0, 2);
            Lcd2.print (sw_byte_D[5]);
            Lcd2.setCursor (0, 3);
            Lcd2.print (sw_byte_D[6]);
            Lcd2.setCursor (10, 1);
            Lcd2.print (sw_byte_D[7]);
            Lcd2.setCursor (10, 2);
            Lcd2.print (sw_byte_D[8]);
            Lcd2.setCursor (10, 3);
            Lcd2.print (sw_byte_D[9]);
        }//end page 6
    }//end page 5||6

    if (_active_page == 7){
        Lcd2.setCursor (0, 1);
        Lcd2.print (SimLEDBase::led_byte_D[0]);
        Lcd2.setCursor (0, 2);
        Lcd2.print (SimLEDBase::led_byte_D[1]);
        Lcd2.setCursor (0, 3);
        Lcd2.print (SimLEDBase::led_byte_D[2]);
        Lcd2.setCursor (10, 1);
        Lcd2.print (SimLEDBase::led_byte_D[3]);
        Lcd2.setCursor (10, 2);
        Lcd2.print (SimLEDBase::led_byte_D[4]);
        Lcd2.setCursor (10, 3);
        Lcd2.print (SimLEDBase::led_byte_D[5]);
    }//end mode7
    */
}//end void


void SimGpsLocal::_updateActive(){}

//SimGpsBase *controll = new SimGpsLocal();


SimGpsBase *gpslocal_led[6] = {
    new SimGpsLocal(SimLEDBase::_led_byte[0], 7, 1, 0),
    new SimGpsLocal(SimLEDBase::_led_byte[1], 7, 2, 0),
    new SimGpsLocal(SimLEDBase::_led_byte[2], 7, 3, 0),
    new SimGpsLocal(SimLEDBase::_led_byte[3], 7, 1, 10),
    new SimGpsLocal(SimLEDBase::_led_byte[4], 7, 2, 10),
    new SimGpsLocal(SimLEDBase::_led_byte[5], 7, 3, 10),
};


#endif // SIMGPSLOCAL_H
