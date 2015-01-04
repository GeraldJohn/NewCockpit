#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#define DataRefIdent const char

class SimObject {
public:

    void setPowerSource(const bool *powerSource) {
        _powerSource = powerSource;

        if (powerSource == 0)
            _needsPower = false;
        else
            _needsPower = true; }

    static void setup(void);
    static void update(bool updateOutput = true);

    static bool hasPower;

protected:
    SimObject(const bool *powerSource) {
        setPowerSource(powerSource); }

    virtual void _addToLinkedList(void);
    virtual void _setup(void) = 0;
    virtual void _update(bool updateOutput = true) = 0;

    bool _needsPower;


    const bool *_powerSource;

private:
    static SimObject *_first;
    SimObject *_next;

};

bool SimObject::hasPower = false;
SimObject *SimObject::_first = 0;


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
