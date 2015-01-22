#ifndef SIMGPSLOCAL_H
#define SIMGPSLOCAL_H

#include "SimGpsBase.h"
#include "HardLcd.h"
#include "SimLed.h"
#include "HardSwitch.h"

class SimGpsLocal : public SimGpsBase {

public:
    SimGpsLocal (//String    *source,
                 const int &Mode = 0, //Zugehörigkeits Modus
                 const int &Row = 0,
                 const int &Pos = 9,
                 const int &NKSt = 0,
                 const bool *hasPowerFlag = &SimObject::hasPower);

protected:
    String _gpsD = "", _gpsD_old = "";
private:
    int _mode, _row, _pos;
    static short _active_row;

    String _source;

    void _setup(void);
    void _update(bool updateOutput);
    void _updateActive();
    void print_Lcd(); };

SimGpsLocal::SimGpsLocal( //String    *source,
                          const int &Mode, //Zugehörigkeits Modus
                          const int &Row,
                          const int &Pos,
                          const int &NKSt,
                          const bool *hasPowerFlag
                          ) : SimGpsBase(NKSt, hasPowerFlag),
    _mode(Mode),
    _row(Row),
    _pos(Pos)
//    _source(source)
{ }

void SimGpsLocal::_setup(void) {}

void SimGpsLocal::_update(bool updateOutput){

    //if (_mode == _active_page){
    // _gpsD_old = _gpsD;


    if (_active_page == 5 || _active_page == 6){
        ///Definition String array sw_byte_D
        String sw_byte_D[9];

        ///_sw_byte to String
        for (int i = 0; i < 9; i++){
            sw_byte_D[i] = String(HardSwitch::sw_byte[i], BIN);

            ///Erhöhung auf acht Stellen
            while (sw_byte_D[i].length() < 8){sw_byte_D[i] = "0" + sw_byte_D[i];}
        }

        if (_active_page == 5) {
            //Lcd2.setCursor (_pos, _row);
            //Lcd2.print (_gpsD);

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
        }//end mode 5

        if (_active_page == 6){

            //Lcd2.setCursor (_pos, _row);
            //Lcd2.print (_gpsD);

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
        }//end mode 6
    }//end mode 5||6
    if (_active_page == 7){

        //_gpsD = _source;
        //for (int i = 0; i < 6; i++){
        //led_byte_D[i] = String(SimLEDBase::_led_byte[i] , BIN);

        //while (led_byte_D[i].length() < 8){led_byte_D[i] = "0" + led_byte_D[i];}
        //}


        //Lcd2.setCursor (_pos, _row);
        //Lcd2.print (_source);

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
}//end void


void SimGpsLocal::_updateActive(){}

SimGpsBase *controll = new SimGpsLocal();

/*
SimGpsBase *gpslocal_led[6] = {
    new SimGpsLocal(SimLEDBase::led_byte_D[0], 7, 1, 0),
    new SimGpsLocal(SimLEDBase::led_byte_D[1], 7, 2, 0),
    new SimGpsLocal(SimLEDBase::led_byte_D[2], 7, 3, 0),
    new SimGpsLocal(SimLEDBase::led_byte_D[3], 7, 1, 10),
    new SimGpsLocal(SimLEDBase::led_byte_D[4], 7, 2, 10),
    new SimGpsLocal(SimLEDBase::led_byte_D[5], 7, 3, 10),
};
*/

#endif // SIMGPSLOCAL_H
