#ifndef HARDLED_H
#define HARDLED_H

#include "SimLed.h"

class HardLed {
public:
    HardLed();
    static void _setup();

    static void _update();

    static void _shiftOut(byte myreg_byte);

private:
    static const byte dataPin;
    static const byte latchPin;
    static const byte clockPin;
};

HardLed::HardLed() {}

const byte HardLed::dataPin = 16;
const byte HardLed::latchPin = 17;
const byte HardLed::clockPin = 18;

//Object Initialisierung
HardLed Led;

void HardLed::_setup(){
    pinMode(HardLed::latchPin, OUTPUT);
    pinMode(HardLed::clockPin, OUTPUT);
    pinMode(HardLed::dataPin, OUTPUT);
}

void HardLed::_update(){
    digitalWrite(latchPin, 0);

    for(int i = 5; i >= 0; i--){
        _shiftOut(SimLEDBase::_led_byte[i]);
        SimLEDBase::_led_byte[i] = 0;
    }

    digitalWrite(latchPin, 1);
}// end prepare_shift();

void HardLed::_shiftOut(byte myreg_byte) {

    int i;
    int pinState;

    digitalWrite(dataPin, 0);
    digitalWrite(clockPin, 0);
    for (i = 7; i >= 0; i--) {
        digitalWrite(clockPin, 0);
        (myreg_byte & (1 << i)) ? pinState = 1 : pinState = 0;
        digitalWrite(dataPin, pinState);
        digitalWrite(clockPin, 1);
        digitalWrite(dataPin, 0);
    }
    digitalWrite(clockPin, 0);

}

#endif // HARDLED_H
