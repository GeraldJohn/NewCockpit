#ifndef SIMGPSCOM_H
#define SIMGPSCOM_H

#include "SimGpsBase.h"
//#include "HardEnc.h"

//! Deklaration class SimGpsComData
class SimGpsComData : public SimGpsBase {

public:
    //!Constructor
    /*! \param ident DataRefIdent phrase
     *  \param Page associated Page
     *  \param EncNr number of Gps Encoder 0 = left/inner 1 = right/outer Gps Encoder
     *  \param CModeMax  max change Positions
     *  \param LowLimit  lower limit of value
     *  \param UpLimit   upper limit of value
     *  \param Faktor    multiplicator
     *  \param Jump      jump from limit to limit or stay at limit
     *  \param NKSt      number of digit after point
     *  \param hasPowerFlag inherited from SimObject
     */
    SimGpsComData(const char  *ident,
                  const int   &Page = 0,
                  const int   &EncNr = 0,
                  const bool  &EncSw = false,
                  const bool  &DownResp = false,
                  const bool  &UpResp = false,
                  const int   &NKSt = 0,
                  const bool *hasPowerFlag = &SimObject::hasPower);

    FlightSimCommand _drCom;

protected:
    String _gpsD;
private:
    int  i, _page, _encnr, _encsw, _down, _up;
    float _faktor;
    void _update(bool updateOutput);
    void _updateActive(); };

//! Definition class SimGpsComData
SimGpsComData::SimGpsComData(const char  *ident,
                             const int   &Page,
                             const int   &EncNr,
                             const bool  &EncSw,
                             const bool  &DownResp,
                             const bool  &UpResp,
                             const int   &NKSt,
                             const bool *hasPowerFlag
                            ) : SimGpsBase(NKSt, hasPowerFlag),
    _page(Page),
    _encnr(EncNr),
    _encsw(EncSw),
    _down(DownResp),
    _up(UpResp)
{
    _drCom.assign((const _XpRefStr_ *)ident);
}

//! Definition Methode _update
void SimGpsComData::_update(bool updateOutput) {
    //! Ist die zugeordnete Page gleich der aktuellen Page
    /*! _drCom werden ggf. durch EncSw.fallingEdge oder Enc.diff ausgelöst
     */
    if (_page == _active_page){

        if (_encsw){ _drCom = myGpsEncSw[_encnr].fallingEdge();}
        else if(_up){ _drCom = myGpsEnc[_encnr]._diff;}
        else if (_down){_drCom = myGpsEnc[_encnr]._diff * -1;}

    } //end if _page == _pageSet
} //end void



//! Definition Methode _updateActive
void SimGpsComData::_updateActive() {}

#endif // SIMGPSCOM_H

