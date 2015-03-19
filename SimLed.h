#ifndef SIMLED_H
#define SIMLED_H

#include "SimObject.h"
#include "HardEnc.h"
#include "SimDivData.h"

/*! High-level dataref-to-LED linking class*/
/*! Incorporating bulb-test and power-available features.*/
//! Deklaration class SimLEDBase als abgeleitete von SimObject
class SimLEDBase : public SimObject {
public:
    //! Deklaration und Definition der Methoden isActive, isLit, lightTest und enableTest
    //! Setzen der: protected bool _active, private: bool _lit, static bool _testAll, bool _allowTest
    /// True if input conditions would cause this LED to light
    bool isActive(void) {return _active;}

    /// True if this LED should light, applying filters (power, test etc)
    bool isLit(void) {return _lit;}

    /// Enable/disable this SimLED's participation in lightTests
    void enableTest (bool allowTest) {_allowTest = allowTest;}

    /// Methode Enable bulb test mode
    static void lightTest(bool lightAll) {_testAll = lightAll;}

    static byte _led_byte[6];
    static String led_byte_D[6];
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

//! Initialise static data members = Definition
bool SimLEDBase::_testAll = false;
byte SimLEDBase::_led_byte[6];
String SimLEDBase::led_byte_D[6];

//! Definition class SimLEDBase
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

//! Definition Methode _update
/// Determine whether this SimLED should be lit
void SimLEDBase::_update(bool updateOutput) {

    //!Überprüfung der _active Voraussetzungen
    _updateActive();

    _lit = _active;

    /// we are lit if bulb-test is active
    if( (_allowTest == true) && (_testAll == true) ){
        _lit = true;
    }

    /// we are not lit if the sim isn't running or no simulated power
    if( !FlightSim.isEnabled() || !SimDivData::_power_is_on) {
        _lit = false;
    }

    /// unless ordered otherwise, light or extinguish LED based on our lighting state
    if (updateOutput){
        SimLEDBase::_led_byte[_reg_nr] += (_lit << _led_nr);
    }
} //end Definition


//---------------------------------------------------------------------------------------------
//! Deklaration class SimLEDIntDR
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


//! Definition class SimLEDIntDR
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

//! Definition Methode _updateActive
void SimLEDIntDR::_updateActive() {
    _active = (_lowLimitInt <= _drInt && _drInt <= _highLimitInt);
    if (_inverse == true) {
        _active = _active ? false : true;
    }

} //end Methode

//--------------------------------------------------------------------------------------------
//! Deklaration class SimLEDFloatDR
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


//! Definition class SimLEDFloatDR
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

//! Definition Methode _updateActive
void SimLEDFloatDR::_updateActive() {
    _active = (_lowLimitFloat <= _drFloat && _drFloat <= _highLimitFloat);
    if (_inverse == true) {
        _active = _active ? false : true;
    }
} //end Methode

//----------------------------------------------------------------------------------------------
//! Deklaration class SimLEDLocal
class SimLEDLocal : public SimLEDBase {
public:
    SimLEDLocal(const int &ledNr,
                const int &regNr,
                const bool &enableTest = true,
                const bool *hasPowerFlag = &SimObject::hasPower);

    void setActive(bool active) { _active = active; }

private:
    //! Methode _updateActive
    void _updateActive();
}; //end Deklaration

/// Definition class
SimLEDLocal::SimLEDLocal(
        const int &ledNr,
        const int &regNr,
        const bool &enableTest,
        const bool *hasPowerFlag)
    : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)

{ _active = false; }

//! Definition Methode _updateActive
void SimLEDLocal::_updateActive() {
    switch (_led_nr) {
    case 0:
        /// GpsEnc[0] Enc Led rot
        myGpsEncSw[0]._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 1:
        /// GpsEnc[0] Led gruen
        myGpsEncSw[0]._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 2:
        /// GpsEnc[1] Led rot
        myGpsEncSw[1]._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 3:
        /// GGpsEnc[1] Led gruen
        myGpsEncSw[1]._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 4:
        /// Radio Enc Led rot
        myRadioEncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 5:
        /// Radio Enc Led gruen
        myRadioEncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    case 6:
        /// Autopilot Enc Led rot
        myApEncSw._Cmode_set != 1 ? setActive(1) : setActive(0);
        break;
    case 7:
        /// Autopilot Enc Led gruen
        myApEncSw._Cmode_set <= 1 ? setActive(1) : setActive(0);
        break;
    default:
        break;
    }//end switch

} //end Methode

#endif // SIMLED_H
