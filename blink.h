#ifndef BLINK_H
#define BLINK_H

//! Deklaration \class blink
//! if boolean _blink == true, then onboard LED will blink once
class blink {
    public:
        blink();
        static bool _blink;
        static void _doBlink();

protected:
        static elapsedMillis ms;
        static int dauer;
 };

//! Definition
blink::blink() {}

//! Object
bool blink::_blink = false;
int blink::dauer = 100;
elapsedMillis blink::ms;

//! Construction
blink Blink;


//! Definition
void blink::_doBlink() {
    if (ms > dauer) {
        digitalWrite(13, LOW);      }

    if (_blink) {
        digitalWrite(13, HIGH);
        ms = 0;
        _blink = false; } }
#endif // BLINK_H
