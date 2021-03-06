#ifndef HARDLED_H
#define HARDLED_H


//! Deklaration class HardLed
class HardLed {
public:
    HardLed();
    /// Definiert PinModes
    static void _setup();

    /// Schalte latchPin 0-1 und ruft shiftOut auf
    static void _update();

    /// Sendet Bits an DataPin mit Hilfe von clockPin
    static void _shiftOut(byte myreg_byte);

    /// Static byte-array and static string-array(control-string)
    static byte _led_byte[6];
    static String led_byte_D[6];

private:
    /// Deklariert Ic Pins
    static const byte dataPin;
    static const byte latchPin;
    static const byte clockPin;
};

//! Initialise static data members = Definition
byte HardLed::_led_byte[6];
String HardLed::led_byte_D[6];

//!Definition class HardLed
HardLed::HardLed() {}

//! Definition der static Vars
const byte HardLed::dataPin = 16;
const byte HardLed::latchPin = 17;
const byte HardLed::clockPin = 18;

//!Object Initialisierung
HardLed Led;

//! Definition Methode setup
void HardLed::_setup(){
    pinMode(HardLed::latchPin, OUTPUT);
    pinMode(HardLed::clockPin, OUTPUT);
    pinMode(HardLed::dataPin,  OUTPUT);
}

//! Definition Methode _update
//! Auslesen der led_byte[] und Aufruf der shiftOut Methode (led_byte[])
//! Danach nullen der led_byte[]
void HardLed::_update(){
    digitalWrite(latchPin, 0);

    for(int i = 5; i >= 0; i--){
        _shiftOut(_led_byte[i]);

        ///Led_Data String wird gesetzt zur Kontrollanzeige im GpsLocal
        led_byte_D[i] = String(_led_byte[i] , BIN);
        while (led_byte_D[i].length() < 8){led_byte_D[i] = "0" + led_byte_D[i];}

        _led_byte[i] = 0;
    }

    digitalWrite(latchPin, 1);
}// end prepare_shift();

//! Definition Methode _shiftOut
//! Setzen der Led Pin gemäß Vorbereitung
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
