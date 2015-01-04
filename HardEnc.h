#ifndef HARDENC_H
#define HARDENC_H

//! Deklaration class HardEnc
class HardEnc : public Encoder {

public:
    HardEnc(const uint8_t PinA,
            const uint8_t PinB);
    //static void _setup();
    static void _update();
    short _diff;

private:
    const uint8_t _pinA;
    const uint8_t _pinB; };

//! Definition class Enc
HardEnc::HardEnc(const uint8_t PinA,
                 const uint8_t PinB) : Encoder(PinA, PinB),
    _pinA(PinA),
    _pinB(PinB),
    _diff() {} //end constructor

//! Object Initialisierung
HardEnc myRadioEnc(25, 26);
HardEnc myApEnc   (27, 28);
HardEnc myGps1Enc (10,  9);
HardEnc myGpsOEnc (12, 11);


//! Definition Methode _update
void HardEnc::_update() {
    myRadioEnc._diff = myRadioEnc.read() / 4;
    if (myRadioEnc._diff) {myRadioEnc.write(0);}; // => SimObjects(update)???

    myApEnc._diff    = myApEnc.read() / 4;
    if (myApEnc._diff) {myApEnc.write(0);};

    myGpsOEnc._diff  = myGpsOEnc.read() / 4;
    if (myGpsOEnc._diff) {myGpsOEnc.write(0);};

    myGps1Enc._diff   = myGps1Enc.read() / 4;
    if (myGps1Enc._diff) {myGps1Enc.write(0);};}


//! Deklaration class HardEncSw
class HardEncSw : public Bounce {

public:
    HardEncSw(const uint8_t PinA,
              unsigned long Milli = 5);

    static void _setup();
    static void _update();
    short _Cmode_set;
private:
    const uint8_t _pinA;
    unsigned long _milli; };

//! Definition class
HardEncSw::HardEncSw(const uint8_t PinA,
                     unsigned long Milli
                     ) : Bounce(PinA, Milli),
    _pinA(PinA),
    _milli(Milli),
    _Cmode_set(-1){}

//! Object Initialisierung
HardEncSw myRadioEncSw = HardEncSw(30);
HardEncSw myApEncSw    = HardEncSw(29);
HardEncSw myGps1EncSw  = HardEncSw(32);
HardEncSw myGpsOEncSw  = HardEncSw(31);

void HardEncSw::_setup() {
    pinMode(myRadioEncSw._pinA, INPUT_PULLUP);
    pinMode(myApEncSw._pinA,    INPUT_PULLUP);
    pinMode(myGps1EncSw._pinA,  INPUT_PULLUP);
    pinMode(myGpsOEncSw. _pinA, INPUT_PULLUP);  }

void HardEncSw::_update() {
    myRadioEncSw.update();
    myApEncSw.update();
    myGps1EncSw.update();
    myGpsOEncSw.update();
    myRadioEncSw.fallingEdge() ? myRadioEncSw._Cmode_set-- : 0;
    myApEncSw.fallingEdge()    ? myApEncSw._Cmode_set--    : 0;
    myGps1EncSw.fallingEdge()  ? myGps1EncSw._Cmode_set--  : 0;
    myGpsOEncSw.fallingEdge()  ? myGpsOEncSw._Cmode_set--  : 0;   }


#endif // HARDENC_H
