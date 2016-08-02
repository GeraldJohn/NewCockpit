#ifndef SIMOBJECT_H
#define SIMOBJECT_H

//! Aid for recording the dataref identifier
#define DataRefIdent const char

//! Deklaration class SimObject
class SimObject {


protected:
    SimObject(const bool *powerSource) { setPowerSource(powerSource); }

    virtual void _addToLinkedList(void);
    virtual void _setup(void) = 0;
    virtual void _update(bool updateOutput = true) = 0;

        //! Specifies if this object needs simulated power available to operate.
    bool _needsPower;

        //! Pointer to power source.
        /*! If _needsPower is set, this will be checked during update.*/
    const bool *_powerSource;


public:
        //! \param powerSource Pointer to bool which defines whether simulated
        //!        power is available to this SimObject
        //!  Definition der öffentlichen Funktion setPowerSource
        //!  Setzen der Variablen _powerSource und _needsPower

    void setPowerSource(const bool *powerSource) {
        _powerSource = powerSource;

        if (powerSource == 0)
            _needsPower = false;
        else
            _needsPower = true; }

        //! Deklaration der statischen Methoden setup und update
        //! Variable updateOutput auf true voreingestellt
    static void setup(void);
    static void update(bool updateOutput = true);

        //! Default simulated power source
    static bool hasPower;

private:
    static SimObject *_first;
    SimObject *_next;

};

//! Initialisierung static Variablen
bool SimObject::hasPower = false;
SimObject *SimObject::_first = 0;


//! Definition
void SimObject::setup() {
    if (_first != 0) { // if at least one SimObject is instantiated
        SimObject *buf = _first;

        while (buf != 0) {
            buf->_setup();
            buf = buf->_next; } } }



void SimObject::update(bool updateOutput) {
    if (_first != 0) { // if at least one SimObject is instantiated
        SimObject *buf = _first;

        while (buf != 0) {
            buf->_update(updateOutput);
            buf = buf->_next; } } }



void SimObject::_addToLinkedList(void) {
    _next = 0;

    if (_first == 0) { // then this must be the first object
        _first = this; }
    else {
        // Go through linked list and make last existing element point to us
        SimObject *a = _first;

        while (a->_next)
            a = a->_next;

        a->_next = this; } }

#endif // SIMOBJECT_H
