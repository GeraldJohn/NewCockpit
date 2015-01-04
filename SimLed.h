#ifndef SIMLED_H
#define SIMLED_H

#include "SimObject.h"
#include "HardEnc.h"
#include "SimDivData.h"

class SimLEDBase : public SimObject {
public:
    bool isActive(void) {return _active;}

    bool isLit(void) {return _lit;}

    void enableTest (bool allowTest) {_allowTest = allowTest;}

    static void lightTest(bool lightAll) {_testAll = lightAll;}

    static byte _led_byte[6];
    static bool _testAll; //vorher private:

protected:
    SimLEDBase(const int &ledNr,
               const int &regNr,
               const bool &enableTest,
               const bool *hasPowerFlag
               );

    bool _active = 1;
    int _led_nr;

private:
    int _reg_nr;
    bool _lit = 1;

    void _setup (void) {}
    void _update(bool updateOutput = true);

    virtual void _updateActive() = 0;

    bool _allowTest = 1;

}; //end Deklaration class SimLEDBase

bool SimLEDBase::_testAll = false;
byte SimLEDBase::_led_byte[6];

SimLEDBase::SimLEDBase(const int &ledNr,
                       const int &regNr,
                       const bool &enableTest,
                       const bool *hasPowerFlag
                       ) : SimObject(hasPowerFlag),
    _led_nr(ledNr),
    _reg_nr(regNr),
    _allowTest(enableTest)
{
    _addToLinkedList();
} //end constructor

void SimLEDBase::_update(bool updateOutput) {

    _updateActive();

    _lit = _active;

    if( (_allowTest == true) && (_testAll == true) ){
        _lit = true;
    }

    if( !FlightSim.isEnabled() || !SimDivData::_power_is_on) {
        _lit = false;
    }

    if (updateOutput){
        SimLEDBase::_led_byte[_reg_nr] += (_lit << _led_nr);
    }
} //end Definition


//---------------------------------------------------------------------------------------------
class SimLEDIntDR : public SimLEDBase {
public:
    SimLEDIntDR(const int &ledNr,
                const int &regNr,
                const char *ident,
                const int &lowLimit = 1,
                const int &highLimit = 32000,
                const bool &invertLimits = false,
                const bool &enableTest = true,
                const bool *hasPowerFlag = &SimObject::hasPower
            );

private:
    FlightSimInteger _drInt;
    int _lowLimitInt;
    int _highLimitInt;
    bool _inverse;

    void _updateActive();

}; //end Deklaration


SimLEDIntDR::SimLEDIntDR(const int &ledNr,
                         const int &regNr,
                         const char *ident,
                         const int &lowLimit,
                         const int &highLimit,
                         const bool &invertLimits,
                         const bool &enableTest,
                         const bool *hasPowerFlag
                         ) : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)
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

} //end constructor

void SimLEDIntDR::_updateActive() {
    _active = (_lowLimitInt <= _drInt && _drInt <= _highLimitInt);
    if (_inverse == true) {
        _active = _active ? false : true;
    }

} //end Methode

//--------------------------------------------------------------------------------------------
class SimLEDFloatDR : public SimLEDBase {
public:
    SimLEDFloatDR(const int &ledNr,
                  const int &regNr,
                  const char *ident,
                  const float &lowLimit,
                  const float &highLimit,
                  const bool &invertLimits = false,
                  const bool &enableTest = true,
                  const bool *hasPowerFlag = &SimObject::hasPower
            );

private:
    FlightSimFloat _drFloat;
    double _lowLimitFloat;
    double _highLimitFloat;
    bool _inverse;

    void _updateActive();
}; //end Deklaration


SimLEDFloatDR::SimLEDFloatDR(const int &ledNr,
                             const int &regNr,
                             const char *ident,
                             const float &lowLimit,
                             const float &highLimit,
                             const bool &invertLimits,
                             const bool &enableTest,
                             const bool *hasPowerFlag
                             ) : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)

{
    _drFloat.assign((const _XpRefStr_ *) ident);

    if (lowLimit < highLimit) {
        _lowLimitFloat = lowLimit;
        _highLimitFloat = highLimit; }

    else {
        _lowLimitFloat = highLimit;
        _highLimitFloat = lowLimit; }

    _inverse = invertLimits;
} // constructor

void SimLEDFloatDR::_updateActive() {
    _active = (_lowLimitFloat <= _drFloat && _drFloat <= _highLimitFloat);
    if (_inverse == true) {
        _active = _active ? false : true;
    }
} //end Methode

//----------------------------------------------------------------------------------------------
class SimLEDLocal : public SimLEDBase {
public:
    SimLEDLocal(const int &ledNr,
                const int &regNr,
                const bool &enableTest = true,
                const bool *hasPowerFlag = &SimObject::hasPower);

    void setActive(bool active) { _active = active; }

private:
    void _updateActive();
}; //end Deklaration

SimLEDLocal::SimLEDLocal(
        const int &ledNr,
        const int &regNr,
        const bool &enableTest,
        const bool *hasPowerFlag)
    : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)

{ _active = false; }

void SimLEDLocal::_updateActive() {
    switch (_led_nr) {
    case 0:
        myGpsOEncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 1:
        myGpsOEncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 2:
        myGps1EncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 3:
        myGps1EncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 4:
        myRadioEncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 5:
        myRadioEncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 6:
        myApEncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 7:
        myApEncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    default:
        break;
    }//end switch

} //end Methode

#endif // SIMLED_H
