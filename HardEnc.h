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
HardEnc myGpsEnc[2] = {
        HardEnc(10,  9),  //linker Enc
        HardEnc(12, 11)   //rechter Enc
};


//! Definition Methode _update
void HardEnc::_update() {
    myRadioEnc._diff = myRadioEnc.read() / 4;
    if(myRadioEnc._diff != 0) {myRadioEnc.write(0);} // => SimObjects(update)???

    myApEnc._diff    = myApEnc.read() / 4;
    if (myApEnc._diff != 0) {myApEnc.write(0);}

    myGpsEnc[0]._diff  = myGpsEnc[0].read() / 4;
    if (myGpsEnc[0]._diff != 0) {myGpsEnc[0].write(0);}

    myGpsEnc[1]._diff  = myGpsEnc[1].read() / 4;
    if (myGpsEnc[1]._diff != 0) {myGpsEnc[1].write(0);}
}


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
HardEncSw myRadioEncSw   = HardEncSw(30);
HardEncSw myApEncSw      = HardEncSw(29);
HardEncSw myGpsEncSw[2]  = {HardEncSw(32),
                            HardEncSw(31)};

void HardEncSw::_setup() {
    pinMode(myRadioEncSw._pinA,   INPUT_PULLUP);
    pinMode(myApEncSw._pinA,      INPUT_PULLUP);
    pinMode(myGpsEncSw[0]._pinA,  INPUT_PULLUP);
    pinMode(myGpsEncSw[1]. _pinA, INPUT_PULLUP);  }

void HardEncSw::_update() {
    myRadioEncSw.update();
    myApEncSw.update();
    myGpsEncSw[0].update();
    myGpsEncSw[1].update();
    myRadioEncSw.fallingEdge()  ? myRadioEncSw._Cmode_set--   : 0;
    myApEncSw.fallingEdge()     ? myApEncSw._Cmode_set--      : 0;
    myGpsEncSw[0].fallingEdge() ? myGpsEncSw[0]._Cmode_set--  : 0;
    myGpsEncSw[1].fallingEdge() ? myGpsEncSw[1]._Cmode_set--  : 0;   }


#endif // HARDENC_H
