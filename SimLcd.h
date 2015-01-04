#ifndef SIMLCD_H
#define SIMLCD_H
/*
#include "SimObject.h"
#include "HardLcd.h"
#include "SimApData.h"
#include "SimRadioData.h"

//! Deklaration class SimLcdBase
class SimLcdBase : public SimObject
{
public:
protected:
    SimLcdBase(
            const bool *hasPowerFlag);
private:
    void _setup(void) {}
    void _update(bool updateOutput = true);
};

//! Definition class SimLcdBase
SimLcdBase::SimLcdBase(const bool *hasPowerFlag
                       ) : SimObject(hasPowerFlag)

{
    _addToLinkedList();
} //end definition

SimLcdBase *RadioLcd();



//! Definition Methode _update
/// Determine whether this SimLcd should show up
void SimLcdBase::_update(bool updateOutput) {
} //end Definition


//! Deklaration SimLcdAutoPilot
class SimLcdAp : SimLcdBase {
public:
    SimLcdAp (const bool *hasPowerFlag = &SimObject::hasPower
            );
private:
}; //end Deklaration

//! Definition class SimLcdAp
SimLcdAp::SimLcdAp(const bool   *hasPowerFlag
                   ) : SimLcdBase(hasPowerFlag)
{} //end definition

    if (SimApData::_print){
        SimApData::_print = false;
        switch (SimApData::_active) {
        case 0: //SimApData::Ap_Mode._alt:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD.length(), 0);
            Lcd1.print(SimApData::_autopD);
            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD.length(), 1);
            Lcd1.print(SimApData::_autopD);
            break;

        case 1: //SimApData::Ap_Mode._alt:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD[SimApData::_active].length(), 0);
            Lcd1.print(SimApData::_autopD[SimApData::_active]);

            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD[SimApData::_active + 1].length(), 1);
            Lcd1.print(SimApData::_autopD[SimApData::_active + 1]);


            break;
        default:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD[SimApData::_active].length(), 0);
            Lcd1.print(SimApData::_autopD[SimApData::_active]);

            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimApData::_autopD[SimApData::_active + 1].length(), 1);
            Lcd1.print(SimApData::_autopD[SimApData::_active + 1]);

            break;
        }
     }*/



#endif // SIMLCD_H
