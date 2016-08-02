#ifndef SIMGPSBASE_H
#define SIMGPSBASE_H

#include "SimData.h"

//! Deklaration class SimGpsBase
class SimGpsBase : public SimData {

public:
    SimGpsBase(
            const int &NKSt = 0,
            const bool *hasPowerFlag = &SimObject::hasPower);

    static int _active_page;         //aktuell gewählter Modus
//    static bool _print;
    static const String gpsH[32];

private:
    void _update(bool updateOutput);
    void change_Date();
    void print_Lcd();
};


//!Initialisierung static
int SimGpsBase::_active_page = 0;
//bool SimGpsBase::_print = true;

/// Definition String Array gpsH[32]
const String SimGpsBase::gpsH[32] = {
    "                    ",
    "Direct:             ",
    "Dist:               ",
    "Time:               ",

    "Range:              ",
    "Mode:               ",
    "Symbols: A W V N T w",
    "active:             ",

    " 3 :                ",
    " :                  ",
    " :                  ",
    " :                  ",

    " 4 :                ",
    " :                  ",
    " :                  ",
    " :                  ",

    " 5 :                ",
    " :                  ",
    " :                  ",
    " :                  ",

    "0 1 2 sw_reg 3 4 5  ",
    "                    ",
    "                    ",
    "                    ",

    "4 5 6 sw_reg 7 8 9  ",
    "                    ",
    "                    ",
    "                    ",

    "0 1 2 led_reg 3 4 5 ",
    "                    ",
    "                    ",
    "                    " };

//! Definition class SimGpsBase
SimGpsBase::SimGpsBase(
        const int &NKSt,
        const bool *hasPowerFlag
        ) : SimData(NKSt, hasPowerFlag)
{}

//! Definition Methode _update
void SimGpsBase::_update(bool updateOutput){}//end void


#endif // SIMGPSBASE_H
