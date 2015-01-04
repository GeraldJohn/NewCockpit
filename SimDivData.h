#ifndef SIMDIVDATA_H
#define SIMDIVDATA_H

#include "SimData.h"

//! Deklaration class SimDivData
class SimDivData : public SimData {
    
public:
    SimDivData (const char   *ident,
                const int    &mode = 0,
                const float  &lowLimit = 0,
                const float  &highLimit = 32000,
                const bool   &invertLimits = false,
                const int    &NKSt = 0,
                const bool   *hasPowerFlag = &SimObject::hasPower);

    FlightSimFloat _drFlt;
    bool _active = false;
    static bool _power_is_on;

protected:
private:
    int   _mode;
    float _lowLimitFloat;
    float _highLimitFloat;
    bool _inverse;
    void _setup (void) {}
    void _update(bool updateOutput);
    void _updateActive();
}; //end Deklaration


//!Initialisierung static
bool SimDivData::_power_is_on = false;


//! Definition class SimDivData
SimDivData::SimDivData(const char   *ident,
                       const int    &mode,
                       const float  &lowLimit,
                       const float  &highLimit,
                       const bool   &invertLimits,
                       const int    &NKSt,
                       const bool   *hasPowerFlag
                       ) : SimData(NKSt, hasPowerFlag),
  _mode(mode)
{
    _drFlt.assign((const _XpRefStr_ *) ident);
    if (lowLimit < highLimit) {
        _lowLimitFloat = lowLimit;
        _highLimitFloat = highLimit;
    } else {
        _lowLimitFloat = highLimit;
        _highLimitFloat = lowLimit;
    }
    _inverse = invertLimits;
}

//! Definition Methode _updateActive
void SimDivData::_updateActive() {
    _active = (_lowLimitFloat <= _drFlt && _drFlt <= _highLimitFloat);
    if (_inverse == true) {
        _active = _active ? false : true;
    }
}

//! Definition Methode _update
void SimDivData::_update(bool updateOutput) {
    _updateActive();
    if ((_mode == 0)  && (_active)) {_power_is_on = true;}
    else {_power_is_on = false;}

} //end Methode

//! Power auf Bus 0
DataRefIdent bus_volts_0Ident[58] = "sim/cockpit2/electrical/bus_volts[0]";

SimData *bus_volts0 =  new SimDivData(bus_volts_0Ident, 0, 5, 30);


#endif // SIMDIVDATA_H
