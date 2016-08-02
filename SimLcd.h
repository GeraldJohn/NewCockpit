#ifndef SIMLCD_H
#define SIMLCD_H
/*
#include "SimObject.h"
#include "HardLcd.h"
#include "SimAutoPt.h"
#include "SimRadio.h"

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

    if (SimAutoPt::_print){
        SimAutoPt::_print = false;
        switch (SimAutoPt::_active) {
        case 0: //SimAutoPt::Ap_Mode._alt:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD.length(), 0);
            Lcd1.print(SimAutoPt::_autopD);
            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD.length(), 1);
            Lcd1.print(SimAutoPt::_autopD);
            break;

        case 1: //SimAutoPt::Ap_Mode._alt:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD[SimAutoPt::_active].length(), 0);
            Lcd1.print(SimAutoPt::_autopD[SimAutoPt::_active]);

            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD[SimAutoPt::_active + 1].length(), 1);
            Lcd1.print(SimAutoPt::_autopD[SimAutoPt::_active + 1]);


            break;
        default:
            /// -> Lcd
            Lcd1.setCursor (5, 0);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD[SimAutoPt::_active].length(), 0);
            Lcd1.print(SimAutoPt::_autopD[SimAutoPt::_active]);

            Lcd1.setCursor (5, 1);
            Lcd1.print("          ");
            Lcd1.setCursor (14 - SimAutoPt::_autopD[SimAutoPt::_active + 1].length(), 1);
            Lcd1.print(SimAutoPt::_autopD[SimAutoPt::_active + 1]);

            break;
        }
     }*/



#endif // SIMLCD_H
