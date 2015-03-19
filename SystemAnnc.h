#ifndef SYSTEMANNC_H
#define SYSTEMANNC_H

#include "SimObject.h"
#include "SimLed.h"

//! Deklaration des Namespace b737
namespace b737 {
const int MAX_ANNCS_PER_SA = 12;
const int MAX_SA_PER_MC = 12;

//! Deklaration class SystemAnnc dh. die 6 roten Led
/*! System Annunciator class z.B. für Boeing 737.
 *  Arbeitet zusammen mit der MasterCaution class.
 */
class SystemAnnc : public SimLEDBase {
public:

    //! Constructor
    /*! \param ledNr Anschluss Nummer auf LED Ic. Auf -1 setzen, wenn
     *         nicht automatisch auf eine LED gesetzt wird.
     *         (LED output kann immer noch mittels der
     *         .isLit() member function gestartet werden.)
     *
     *  \param regNr Nummer des LED Ic. Set to -1
     *         if not automatically outputting to an LED.
     *
     *  \param subAnncList Pointer auf Array von Sim Objekten je SystemAnnc Led
     *         Liste von SimLEDs (dataref-fed or local-logic-fed)
     *         die zu diesem System gehören und diesen System Annunciator ansteuern
     *         Sie müssen nicht mit realen Leds verknüft sein
     *         (Sie können eine led- und reg nummer von -1 haben.)
     *
     *  \param sizeof_subAnncList Anzahl der Objekte
     *         Diese MUSS mittels sizeof(subAnncList) festgestellt werden
     *         wenn der constructor aufgerufen wird!
     *
     *  \param enableTest Wenn diese SystemAnnc in algemeinen Led tests teilnehmen soll.
     *         Default ist 'false', da der Ledtest von MasterCaution.recallMode(true)
     *         zur Verfügung gestellt wird.
     *
     *  \param hasPowerFlag pointer to bool arbeitet als simulierte power supply für diesen SystemAnnc
     *  \todo  toDo Liste erstellen
     */

    SystemAnnc (const int    &ledNr,
                const int    &regNr,
                SimLEDBase   *subAnncList[],
                const size_t sizeof_subAnncList,
                const bool   &enableTest   = true,
                const bool   *hasPowerFlag = &SimObject::hasPower )
        : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)
    {
        _subAnncsList = subAnncList;
        _subAnncCount = sizeof_subAnncList / (sizeof(SimLEDBase*));
        if(_subAnncCount > MAX_ANNCS_PER_SA)
            _subAnncCount = MAX_ANNCS_PER_SA;
    } //end Constuctor

    //! benötigt, damit MasterCaution unsere _reset function aufrufen kann
    friend class MasterCaution;
    bool _recallMode;

private:
    //! Pointer to array of SimLED sub-annunciators
    SimLEDBase **_subAnncsList;

    //! Anzahl der Sub Announcer die diesen SysAnnc ansteuern
    unsigned short _subAnncCount;

    //! Record of which active subAnncs have been acknowledged as active
    //! Flag Array: ob aktive Sub Annuncs als aktiv vermerkt wurden
    //! Arraygröße wie voreingestellte Max Anncs per SA
    bool _subAck[MAX_ANNCS_PER_SA];

    //! Recall mode lights the output regardless of subannc state
    //! Flag des RecallModes, der Led anschaltet unabhängig ihres subannc Status
    // bool _recallMode;

    //! True if any subanncs are active, regardless of ack'd status
    //! True wenn ein Sub Annunc aktiv ist, unabhängig vom Acknowleged Status
    bool _hasActive;

    //! Deklaration und Definition Methode _updateActive
    void _updateActive() {

        //! Test auf Recall Mode, wenn true
        //! return: Beendigung der Methode ohne Berücksichtigung des Rests
        if (_recallMode) {
            _active = true;
            return;        }

        //! Tests der jeweiligen Sim Objekte und setzen des _hasActive Flags
        _hasActive = false;
        for (int i = 0; i < _subAnncCount; ++i) {
            if(_subAnncsList[i]->isActive() ) {  //return des _active Flags des Sim Objectes
                _hasActive = true;              //setzen des _hasActive Flags des SystemAnncs

                //!Wenn noch nicht acknowleged, dann system Annc._active
                //! und acknowleged setzen für das jeweilige Objekt.
                if(!_subAck[i]) {
                    _active = true;
                    _subAck[i] = true;
                }
            }
            else { //wenn isActive() false ergibt
                _subAck[i] = false;
            }//end else
        }//end for
    } //end _updateActive()

    //! Deactivates subAnnc. Called by MasterCaution.
    //! Deklaration und Definition Methode _reset
    void _reset() { _active = false; }

    //! Set recall mode on/off
    //! Deklaration und Definition Methode _setSubRecall
    void _setSubRecall(bool mode) {
        /// if we are starting recall mode
        if (mode && !_recallMode) {
            _recallMode = true;
        }

        /// if we are ending Recall mode
        if (!mode && _recallMode) {
            /// clear all acknowledgements
            for (int i = 0; i < _subAnncCount; ++i) {
                _subAck[i] = false;
            }
            _recallMode = false;
            _active = false;
        }
    }

}; //end class

//! Master Caution class for Boeing 737
//! Works in conjunction with SystemAnnc
//! Deklaration class MasterCaution
class MasterCaution : public SimLEDBase {
public:
    //! Constructor
    /*! \param ledNr Anschluss Nummer auf LED Ic. Set to -1
   *         if not automatically outputting to an LED. (LED output can
   *         still be done using the .isLit() member function.)
   *  \param regNr Nummer des LED Ic. Set to -1
   *         if not automatically outputting to an LED.
   *  \param sysAnncList list of SystemAnncs which feed this Master
   *         Caution light. They do not need to be linked to real LEDS
   *         (they can have a pin number of -1)
   *  \param sizeof_sysAnncList This MUST be specified using sizeof(
   *         sysAnncList) when the constructor is called!
   *  \param enableTest Sets participation in generic
   *         SimLED bulb tests. Defaults to 'true'.
   *  \param hasPowerFlag pointer to bool acting as simulated power
   *         supply
   */

    MasterCaution (const int    &ledNr,
                   const int    &regNr,
                   SystemAnnc   *sysAnncList[],  //Pointer auf SystemAnnc Array
                   const size_t sizeof_sysAnncList,
                   const bool   &enableTest   = true,
                   const bool   *hasPowerFlag = &SimObject::hasPower )
        : SimLEDBase(ledNr, regNr, enableTest, hasPowerFlag)
    {
        _sysAnncs = sysAnncList;
        _sysAnncCount = sizeof_sysAnncList / (sizeof(SystemAnnc*));
        if(_sysAnncCount > MAX_SA_PER_MC)
            _sysAnncCount = MAX_SA_PER_MC;
    }

    //! Reset all System Annunciators linked with this object
    void reset() {
        for (int i = 0; i < _sysAnncCount; ++i) {
            _sysAnncs[i]->_reset();
        }
        _active = false;
    }

    //! Set Recall mode for all System Annunciators linked with this object
    void setMasterRecall(bool mode) {
        for (int i = 0; i < _sysAnncCount; ++i) {
            _sysAnncs[i]->_setSubRecall(mode);
        }
    }


private:
    //! Pointer to array of SystemAnnc associated with this MasterCaution
    SystemAnnc **_sysAnncs;

    //! Number of SystemAnnc linked to this MasterCaution
    unsigned short _sysAnncCount;

    //! MasterCaution is active if any of the fault lights are on
    void _updateActive() {
        for (int i = 0; i < _sysAnncCount; ++i) {
            if(_sysAnncs[i]->_hasActive) {
                _active = true;
            }
        }
    } //_updateActive


}; //end class

} //end namespace b737SysAnnc
#endif // SYSTEMANNC_H
