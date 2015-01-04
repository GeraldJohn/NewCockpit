#ifndef SIMGPSBASE_H
#define SIMGPSBASE_H

#include "SimData.h"

class SimGpsBase : public SimData {

public:
    SimGpsBase(
            const int &NKSt = 0,
            const bool *hasPowerFlag = &SimObject::hasPower);

    static int _active_mode; //aktuell gewählter Modus
    static bool _print;
    static const String gpsH[32];
private:
    void _update(bool updateOutput);
    void print_Lcd();
    void change_Date();
};


int SimGpsBase::_active_mode = 0;
bool SimGpsBase::_print = true;

const String SimGpsBase::gpsH[32] = {
    " ", //1
    "Direct: ",
    "Dist: ",
    "Time: ",

    "Range: ", //2
    "Mode: ",
    "Symbols: A W V N T w",
    " : ",

    "Baro: ", //3
    " : ",
    " : ",
    " : ",

    " 4 : ", //4
    " : ",
    " : ",
    " : ",

    " 5 : ", //5
    " : ",
    " : ",
    " : ",

    "0 1 2 sw_reg 3 4 ", //6
    " ",
    " ",
    " ",

    "5 6 7 sw_reg 8 9 ", //7
    " ",
    " ",
    " ",

    "0 1 2 led_reg 3 4 5", //8
    " ",
    " ",
    " " };

SimGpsBase::SimGpsBase(
        const int &NKSt,
        const bool *hasPowerFlag
        ) : SimData(NKSt, hasPowerFlag)
{}

void SimGpsBase::_update(bool updateOutput){}//end void


#endif // SIMGPSBASE_H
