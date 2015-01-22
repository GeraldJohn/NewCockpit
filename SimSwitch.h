#ifndef SIMSWITCH_H
#define SIMSWITCH_H

#include "SimObject.h"
#include "HardSwitch.h"
#include "SimRadioData.h"
#include "SimApData.h"
#include "SimGpsInt.h"
#include "SimGpsFlt.h"
#include "SimGpsCom.h"
#include "SimGpsLocal.h"
#include "SystemAnnc.h"
#include "AssignLed.h"
#include "HardEnc.h"


//!Deklaration class SimSwitchBase
class SimSwitchBase : public SimObject {
protected:
    SimSwitchBase(const bool *hasPowerFlag
                  );

    void _setup (void) {}

};//end Deklaration class SimSwitchBase

//! Statics

//!Definition class SimSwitchBase
SimSwitchBase::SimSwitchBase(const bool *hasPowerFlag
                             ) : SimObject(hasPowerFlag)
{
    _addToLinkedList();
}//end constructor

//----------------------------------------------------------

//! Deklaration class SimSwitchInt
class SimSwitchInt : public SimSwitchBase {
public:
    SimSwitchInt(const int  &swNr,
                 const int  &regNr,
                 const char *ident,
                 const bool &taster    = false,
                 const int  &if_true   = 1,
                 const int  &if_false  = 0,
                 const bool  *hasPowerFlag = &SimObject::hasPower
            );
    int _sw_nr;
    int _reg_nr;
    bool _taster;
    int _if_true;
    int _if_false;

    void _update(bool updateOutput = true);

    FlightSimInteger _drInt;
private:

};//end deklaration

//! Definition class SimSwitchInt
SimSwitchInt::SimSwitchInt(const int  &swNr,
                           const int  &regNr,
                           const char *ident,
                           const bool &taster,
                           const int  &if_true,
                           const int  &if_false,
                           const bool *hasPowerFlag
                           ) : SimSwitchBase(hasPowerFlag),
    _sw_nr(swNr),
    _reg_nr(regNr),
    _taster(taster),
    _if_true(if_true),
    _if_false(if_false)

{
    _drInt.assign((const _XpRefStr_ *) ident);
}//end constructor

//! Definition Methode _update(bool updateOutput)
void SimSwitchInt::_update(bool updateOutput) {
    if (updateOutput){
        if (HardSwitch::changedBit[_reg_nr] & (1 << _sw_nr)){
            ((HardSwitch::sw_byte[_reg_nr] & (1 << _sw_nr)) == (1 << _sw_nr)) ? _drInt = _if_true : _drInt = _if_false;
        }
    }//end if
}

//-----------------------------------------------------------------------------------------------
//! Deklaration class SimSwitchCom
class SimSwitchCom : public SimSwitchBase {
public:
    SimSwitchCom(const int  &swNr,
                 const int  &regNr,
                 const char *ident,
                 const bool &taster          = false,
                 const int  &if_true         = 1,
                 const int  &if_false        = 0,
                 const bool *hasPowerFlag    = &SimObject::hasPower
            );
    int _sw_nr;
    int _reg_nr;
    bool _taster;
    int _if_true;
    int _if_false;

    void _update(bool updateOutput = true);
private:
    FlightSimCommand _drCom;
};

//! Definition class SimSwitchCom
SimSwitchCom::SimSwitchCom(const int  &swNr,
                           const int  &regNr,
                           const char *ident,
                           const bool &taster,     //Tasterfunktion
                           const int  &if_true,    //Wert bei 1
                           const int  &if_false,
                           const bool *hasPowerFlag
                           ) : SimSwitchBase(hasPowerFlag),
    _sw_nr(swNr),
    _reg_nr(regNr),
    _taster(taster),
    _if_true(if_true),
    _if_false(if_false)
{
    _drCom.assign((const _XpRefStr_ *) ident);
} //end constructor

//! Definition Methode _update
void SimSwitchCom::_update(bool updateOutput) {
    if (updateOutput){
        if (HardSwitch::changedBit[_reg_nr] & (1 << _sw_nr)){
            ((HardSwitch::sw_byte[_reg_nr] & (1 << _sw_nr)) == (1 << _sw_nr)) ? _drCom = _if_true : _drCom = _if_false;
        }
    }//end if
}//end void

//------------------------------------------------------------------------------------------------
//!Deklaration class SimSwitchLocal
class SimSwitchLocal : public SimSwitchBase {
public:
    SimSwitchLocal(const int  &swNr,
                   const int  &regNr,
                   const int  &if_true     = 1,
                   const int  &if_false    = 0,
                   const bool *hasPowerFlag = &SimObject::hasPower
            );
    int _sw_nr;
    int _reg_nr;
    int _if_true;
    int _if_false;
    void _update(bool updateOutput = true);

private:
    int _switched = 0;
    int _switched_old = 0;

};

//! Definition class SimSwitchLocal
SimSwitchLocal::SimSwitchLocal(const int  &swNr,
                               const int  &regNr,
                               const int  &if_true,      //Page-number
                               const int  &if_false,
                               const bool *hasPowerFlag
                               ): SimSwitchBase(hasPowerFlag),
    _sw_nr(swNr),
    _reg_nr(regNr),
    _if_true(if_true),
    _if_false(if_false)
{}

//! Definition Methode _update
void SimSwitchLocal::_update(bool updateOutput) {
    if (updateOutput){

        /// Existiert für das Object(sw_nr, reg_nr) ein changedBit, dh. Taster/Schalter betätigt
        if (HardSwitch::changedBit[_reg_nr] & (1 << _sw_nr)){

            /// recall Taster wurde geändert
            if(HardSwitch::sw_byte[_reg_nr] & (1 << _sw_nr) == (1 << _sw_nr)){
                masterCaution.setMasterRecall(true);
                blink::_blink = true;
            }
            else {
                masterCaution.setMasterRecall(false);
                blink::_blink = true;
            }



            /// Ist für das Object(sw_nr, reg_nr) die _sw_nr des sw_byte true, dh. Taster/Schalter auf on
            if ((HardSwitch::sw_byte[_reg_nr] & (1 << _sw_nr)) == (1 << _sw_nr)){

                ///  Ist die _reg_nr des Objects == 3: => Radio Rotary Switch wurde betätigt
                /// _mode auf Wert von _if_true gesetzt
                if (_reg_nr == 3){

                    /// Setze die jeweilige Frequenz und StanbyFrequenz auf active
                    SimRadioData::_modeSet = _if_true;
                    SimStbyRadioData::_modeSet = _if_true;

                    /// Setze _CMode_set auf -1 => CMode_set = CModeMax
                    myRadioEncSw._Cmode_set = -1;

                    /// Setze Flag für Lcd print
                    SimRadioData::_print = true;
                    SimStbyRadioData::_print = true;

                    /// RadioLcd erste Zeile
                    Lcd0.setCursor (0, 0);
                    Lcd0.print(SimRadioData::radioH[SimStbyRadioData::_modeSet]);   //"Com1" etc
                    /// RadioLcd zweite Zeile
                    Lcd0.setCursor (0, 1);
                    Lcd0.print(SimRadioData::radioH[8]);    //"Standby  .  "
                }//endif reg_nr == 3


                /// _reg_nr == 9: Autopilot Rotary Switch
                /// _mode auf Wert von _if_true gesetzt
                if (_reg_nr == 9) {

                    /// Setze die eingestellte Frequenz und StanbyFrequenz auf active
                    SimApData::_active_page = _if_true;

                    /// Setze _CMode_set auf -1 => CMode_set = CModeMax
                    myApEncSw._Cmode_set = -1;


                    /// -> Lcd
                    Lcd1.setCursor (0, 0);
                    Lcd1.print(SimApData::autopH[SimApData::_active_page * 2]);   //"Alt " etc
                    Lcd1.setCursor (0, 1);
                    Lcd1.print(SimApData::autopH[SimApData::_active_page * 2 + 1]);    //"Standby  .  "

                    /// Setze Flag für Lcd print
                    SimApData::_print = true;
                } //endif reg_nr == 9

                /// _reg_nr == 4: GPS Rotary Switch
                /// _mode auf Wert von _if_true gesetzt
                if (_reg_nr == 4) {

                    /// Setze die jeweilige Einheit auf active
                    SimGpsIntData::_active_page = _if_true;
                    SimGpsFltData::_active_page = _if_true;
                    SimGpsComData::_active_page = _if_true;
                    SimGpsLocal::  _active_page = _if_true;

                    /// Setze _CMode_set auf -1 => CMode_set = CModeMax
                    myGps1EncSw._Cmode_set = -1;


                    /// -> Lcd
                    Lcd2.setCursor (0, 0);
                    Lcd2.print(SimGpsBase::gpsH[SimGpsIntData::_active_page * 4]);   //"Airport " etc
                    Lcd2.setCursor (0, 1);
                    Lcd2.print(SimGpsBase::gpsH[SimGpsIntData::_active_page * 4 + 1]);    //"Direct:"
                    Lcd2.setCursor (0, 2);
                    Lcd2.print(SimGpsBase::gpsH[SimGpsIntData::_active_page * 4 + 2]);   //"Dist: " etc
                    Lcd2.setCursor (0, 3);
                    Lcd2.print(SimGpsBase::gpsH[SimGpsIntData::_active_page * 4 + 3]);    //"Time:  .  "

                    /// Setze Flag für Lcd print
                    SimGpsIntData::_print = true;
                }//endif reg_nr == 4



                /// Swap Taster wurde geändert und true
                if (_reg_nr == 2 && _sw_nr == 5){
                    if(SimRadioData::_modeSet < 6){
                        SimStbyRadioData::_swap = true;
                        blink::_blink = true;

                        /// Setze _CMode_set auf -1 => CMode_set = CModeMax
                        myRadioEncSw._Cmode_set = -1;

                    }//endif modeset
                    //! im ATC Modus soll der Swap Taster die Transponder id starten
                    else if (SimRadioData::_modeSet == 6){
                       // SimSwitchCom::sw_radio[0]._drCom = 1;
                    }
                }//endif reg 2 sw 5

                /// reset Taster wurde geändert und true
                if (_reg_nr == 2 && _sw_nr == 7) {
                    //if (HardSwitch::sw_byte[_reg_nr] & (1 << _sw_nr) == (1 << _sw_nr)){
                    masterCaution.reset();
                    blink::_blink = true;
                    //}
                }//endif re 2 sw 7

            }//endif sw_byte
        }// end if changedBit
    }//end if updateOutput
}//end void



    //End Switches

#endif // SIMSWITCH_H
