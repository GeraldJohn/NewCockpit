#include <Bounce.h>
#include <Encoder.h>
#include <LiquidCrystal_SR.h>
#include <Arduino.h>

///Kommentar

#include "blink.h"
#include "HardEnc.h"
#include "HardSwitch.h"
#include "HardLcd.h"
#include "HardLed.h"
#include "SimObject.h"
#include "SimSwitch.h"
#include "SystemAnnc.h"
#include "SimGpsLocal.h"
#include "AssignGpsInt.h"
#include "AssignSwitch.h"


#include "SimLcd.h"
#include "SimData.h"
#include "SimDivData.h"
#include "SimApData.h" "
#include "SimRadioData.h"


void setup() {
    HardEncSw::_setup();
    HardLcd::_setup();
    HardLed::_setup();
    HardSwitch::_setup();
    SimObject::setup();

    pinMode(13, OUTPUT);
}

void loop() {
    FlightSim.update();

    //delay(500);

    SimObject::update();
    HardEnc::_update();
    HardEncSw::_update();
    HardLed::_update();
    HardSwitch::_update();
    HardLcd::_update();
    contrast_brightn::_update();
    blink::_doBlink();





    /*
  Lcd2.setCursor (0, 0);
  Lcd2.print("_autopD: ");
  Lcd2.print(SimApData::_autopD);
  Lcd2.setCursor (0, 1);
  Lcd2.print("_autopD_old ");
  Lcd2.print(SimApData::_autopD_old);
  Lcd2.setCursor (0, 2);
  Lcd2.print("bus_volts: ");
  Lcd2.print(bus_volts._drFloat);
  Lcd2.setCursor (0, 3);
  Lcd2.print("crt: ");
  Lcd2.print("");
  Lcd2.print(" brt: ");
  Lcd2.print("");
 */


    // Reset all SystemAnncs belonging to masterCaution
    //if (reset.fallingEdge()) masterCaution.reset();

    // set/remove Recall mode on all SystemAnncs belonging to MasterCaution
    //masterCaution.setRecall(!recall.read());

}
