#ifndef HARDLCD_H
#define HARDLCD_H

#include "SimDivData.h"

//! Deklaration class HardLcd
class HardLcd : public LiquidCrystal_SR{
public:
    HardLcd(const uint8_t &DataPin,
            const uint8_t &ClockPin,
            const uint8_t &LatchPin,
            const uint8_t &cols,
            const uint8_t &rows
            );

    /// Definiert PinModes
    static void _setup();
    static void _update(); //lcd.print???

private:
    /// Deklariert Ic Pins
    const uint8_t _dataPin;
    const uint8_t _clockPin;
    const uint8_t _latchPin;
    const uint8_t _rows;
    const uint8_t _cols;
};

//!Definition class HardLcd
HardLcd::HardLcd(const uint8_t &DataPin,
                 const uint8_t &ClockPin,
                 const uint8_t &LatchPin,
                 const uint8_t &cols,
                 const uint8_t &rows
                 ) : LiquidCrystal_SR(DataPin, ClockPin, LatchPin),
    _dataPin(DataPin),
    _clockPin(ClockPin),
    _latchPin(LatchPin),
    _rows(rows),
    _cols(cols)
{}

//! Statics
//! Object Initialisierung
HardLcd Lcd0(3, 5, 4 ,16, 2);
HardLcd Lcd1(6, 8, 7, 16, 2);
HardLcd Lcd2(0, 2, 1, 20, 4);

//! Definition Methode setup
void HardLcd::_setup(){
    Lcd0.begin(Lcd0._cols, Lcd0._rows);
    Lcd1.begin(Lcd1._cols, Lcd1._rows);
    Lcd2.begin(Lcd2._cols, Lcd2._rows);
    Lcd0.home();
    Lcd1.home();
    Lcd2.home();
    Lcd0.setCursor(0, 0);
    Lcd0.print(" Radio ");
    Lcd1.setCursor(0, 0);
    Lcd1.print(" Autopilot ");
    Lcd2.setCursor(0, 0);
    Lcd2.print(" GPS und Efis ");
}

//! Definition Methode _update
void HardLcd::_update(){













}

//___________________________________________________________________________________________
//! Deklaration class contrast_brightn
class contrast_brightn
{
public:
    contrast_brightn();
    static void _update();
private:
    static int brt;
    static int ctr;
    static const int brtInPin;
    static const int ctrInPin;
    static const int brtOutPin;
    static const int ctrOutPin;
};

//! Definition contrast_brightn
contrast_brightn::contrast_brightn(){}

//! Statics
int contrast_brightn::brt;
int contrast_brightn::ctr;
const int contrast_brightn::brtInPin = A12;
const int contrast_brightn::ctrInPin = A13;
const int contrast_brightn::brtOutPin = 22;
const int contrast_brightn::ctrOutPin = 23;


//! Object
contrast_brightn Contrast_Brightness;

//! Definition Methode _update
void contrast_brightn::_update(){
    //! Brightness und Contrast
    //! read the input on analog pins
    int brtValue = analogRead(brtInPin);
    int ctrValue = analogRead(ctrInPin);

    //! Map to LCD Backlight und Contrast
    brt = map(brtValue, 0, 1023, 0, 255);
    ctr = map(ctrValue, 0, 1023, 0, 255);

    /// we are not lit if the sim is running and no simulated power
    if( !FlightSim.isEnabled() || !SimDivFltData::_power_is_on || !SimDivIntData::_avionic_on) {
        analogWrite(brtOutPin, 0);}
    else {
        analogWrite(brtOutPin, brt);}

    analogWrite(ctrOutPin, ctr);
}


#endif // HARDLCD_H
