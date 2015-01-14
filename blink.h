#ifndef BLINK_H
#define BLINK_H

//! Deklaration
class blink {
    public:
        blink();
        static bool _blink;
        static elapsedMillis ms;
        static int dauer;
        static int pause;
        static void _doBlink(); };

//! Definition
blink::blink() {}

//! Object
bool blink::_blink = false;
int blink::dauer = 100;
int blink::pause = 2;
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
