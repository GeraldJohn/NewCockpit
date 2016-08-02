
#include <Bounce.h>
#include <Encoder.h>
#include <LiquidCrystal_SR.h>
#include <Arduino.h>

//!Kommentar wird erneuert

#include "AssignLed.h"
#include "AssignApData.h"
#include "AssignRadioData.h"
#include "AssignSwitch.h"
//#include "AssignGpsInt.h"
//#include "AssignGpsCom.h"


//#include "HardSwitch.h"
//#include "SimObject.h"

//#include "SystemAnnc.h"
#include "SimGpsLocal.h"
//#include "SimSwitch.h"


//#include "SimLcd.h"
//#include "SimData.h"
//#include "SimDivData.h"
//#include "SimApData.h" "
//#include "SimRadioData.h"


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

    HardEnc::_update();
    HardEncSw::_update();
    HardLed::_update();
    contrast_brightn::_update();
    HardSwitch::_update();
    //HardLcd::_update();
    SimObject::update();
    blink::_doBlink();




    /*


  Lcd2.setCursor (1, 3);
  Lcd2.print("ledbyte ");
  Lcd2.print(HardLed::_led_byte[0]);

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
    //masterCaution.setMasterRecall(!recall.read());

}
