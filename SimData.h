#ifndef SIMDATA_H
#define SIMDATA_H

#include "SimObject.h"

//! Deklaration class SimData
class SimData: public SimObject{

public:
    SimData(const int  &NKSt,
             const bool *hasPowerFlag
             );

    static FlightSimInteger date1;
    static FlightSimInteger date2;
    void swap_Date(FlightSimInteger &date1, FlightSimInteger &date2);

private:
    void _setup (void) {}
    void _update(bool updateOutput = true);
    virtual void _updateActive() = 0;

protected:
    int _nkst;

};

//! Definition class SimData-------------------------------------------------
//! Constructor
SimData::SimData(const int  &NKSt,
                   const bool *hasPowerFlag
                   ) : SimObject(hasPowerFlag),

  _nkst(NKSt)
{
    _addToLinkedList();
}//end Deklaration

FlightSimInteger SimData::date1;
FlightSimInteger SimData::date2;


void SimData::_update(bool updateOutput){

    _updateActive();

}


//! Definition Methode swap_Date
void SimData::swap_Date (FlightSimInteger &date1, FlightSimInteger &date2){

    date1 = date1 ^ date2;
    date2 = date1 ^ date2;
    date1 = date1 ^ date2;
}

#endif // SIMDATA_H
