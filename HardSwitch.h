#ifndef HARDSWITCH_H
#define HARDSWITCH_H

//! Deklaration class HardSwitch
class HardSwitch{
public:
    HardSwitch();

    static void _setup();
    static void _update();

    static byte sw_byte[];
    static byte changedBit[];


private:
    static const byte latchPin;
    static const byte clockPin;
    static const byte dataPin;

    static byte shiftIn(int myDataPin, int myClockPin);
protected:


};

//!Definition class HardSwitch
HardSwitch::HardSwitch() {}

byte HardSwitch::sw_byte[10];
byte HardSwitch::changedBit[10];

const byte HardSwitch::latchPin = 20;
const byte HardSwitch::clockPin = 21;
const byte HardSwitch::dataPin  = 19;

//Object
HardSwitch Switch;

//! Definition setup
void HardSwitch::_setup(){
    pinMode(HardSwitch::latchPin, OUTPUT);
    pinMode(HardSwitch::clockPin, OUTPUT);
    pinMode(HardSwitch::dataPin,  INPUT);
}

//!Definition Methode _update()
void HardSwitch::_update(){
    int n;
    byte reg_byte_old[10];

    digitalWrite(latchPin,1);
    delayMicroseconds(2);
    digitalWrite(latchPin,0);
    for (n = 0 ; n <= 9; n++){
        reg_byte_old[n] = sw_byte[n];
        sw_byte[n] = shiftIn(dataPin, clockPin);
        changedBit[n] = sw_byte[n] ^ reg_byte_old[n];
    }
}

byte HardSwitch::shiftIn(int myDataPin, int myClockPin) {
    int i;
    int temp = 0;
    int pinState;
    byte myDataIn = 0;



    for (i = 7; i >= 0; i--)  {
        digitalWrite(myClockPin, 0);
        delayMicroseconds(2);
        temp = digitalRead(myDataPin);

        if (temp) {
            pinState = 1;
            ///set the bit to 0 no matter what
            myDataIn = myDataIn | (1 << i);
        }
        else {
            ///turn it off -- only necessary for debuging
            ///print statement since myDataIn starts as 0
            pinState = 0;
        }
        digitalWrite(myClockPin, 1);

    }
    return myDataIn;
}

#endif // HARDSWITCH_H
