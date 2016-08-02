#ifndef SimDivFltData_H
#define SimDivFltData_H

#include "SimData.h"

//! Deklaration class SimDivFltData
class SimDivFltData : public SimData {
    
public:
    SimDivFltData (const char   *ident,
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
bool SimDivFltData::_power_is_on = false;


//! Definition class SimDivFltData
SimDivFltData::SimDivFltData(const char   *ident,
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
void SimDivFltData::_updateActive() {
    _active = (_lowLimitFloat <= _drFlt && _drFlt <= _highLimitFloat);
    if (_inverse == true) {
        _active = _active ? false : true;
    }
}

//! Definition Methode _update
void SimDivFltData::_update(bool updateOutput) {
    _updateActive();
    if ((_mode == 0)  && (_active)) {_power_is_on = true;}
    else {_power_is_on = false;}

} //end Methode

//! Power auf Bus 0
DataRefIdent bus_volts_0Ident[58] = "sim/cockpit2/electrical/bus_volts[0]";
SimData *bus_volts0 =  new SimDivFltData(bus_volts_0Ident, 0, 5, 30);


//_____________________________________________________________________________________


//! Deklaration class SimDivIntData
class SimDivIntData : public SimData {

public:
    SimDivIntData  (const char   *ident,
                    const int    &mode = 0,
                    const int    &lowLimit = 0,
                    const int    &highLimit = 32000,
                    const bool   &invertLimits = false,
                    const int    &NKSt = 0,
                    const bool   *hasPowerFlag = &SimObject::hasPower);

    FlightSimInteger _drInt;
    bool _active = false;
    static bool _avionic_on;

protected:
private:
    int   _mode;
    int   _lowLimitInt;
    int   _highLimitInt;
    bool  _inverse;
    void  _setup (void) {}
    void  _update(bool updateOutput);
    void  _updateActive();
}; //end Deklaration


//!Initialisierung static
bool SimDivIntData::_avionic_on = false;


//! Definition class SimDivIntData
SimDivIntData::SimDivIntData(const char   *ident,
                             const int    &mode,
                             const int    &lowLimit,
                             const int    &highLimit,
                             const bool   &invertLimits,
                             const int    &NKSt,
                             const bool   *hasPowerFlag
                             ) : SimData(NKSt, hasPowerFlag),
  _mode(mode)
{
    _drInt.assign((const _XpRefStr_ *) ident);

    if (lowLimit < highLimit) {
        _lowLimitInt = lowLimit;
        _highLimitInt = highLimit;
    } else {
        _lowLimitInt = highLimit;
        _highLimitInt = lowLimit;
    }
    _inverse = invertLimits;
}



//! Definition Methode _updateActive
void SimDivIntData::_updateActive() {
    _active = (_lowLimitInt <= _drInt && _drInt <= _highLimitInt);
    if (_inverse == true) {
        _active = _active ? false : true;
    }
}


//! Definition Methode _update
void SimDivIntData::_update(bool updateOutput) {
    _updateActive();
    if ((_mode == 1)  && (_active)) {_avionic_on = true;}
    else {_avionic_on = false;}

} //end Methode


//! Avionic on
DataRefIdent avionics_onIdent[58] = "sim/cockpit2/switches/avionics_power_on";
SimData *avionics_on =  new SimDivIntData(avionics_onIdent, 1, 1, 2);


#endif // SimDivFltData_H
