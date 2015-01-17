#ifndef ASSIGNLED_H
#define ASSIGNLED_H

#include "SimLed.h"
#include "SystemAnnc.h"

/// Rote Warnleuchten
/// erste LED von links
DataRefIdent r1Ident[][58] = {
    "sim/cockpit2/annunciators/low_voltage",
    "sim/cockpit2/annunciators/generator_off[0]",
    "sim/cockpit2/annunciators/generator_off[1]"
};

SimLEDBase *r1Anncs[] = {
    new SimLEDIntDR(-1, -1, r1Ident[0], 1, 1, false, false), // on if voltage low
    new SimLEDIntDR(-1, -1, r1Ident[1], 1, 1, false, false),
    new SimLEDIntDR(-1, -1, r1Ident[2], 1, 1, false, false)
};

/// zweite LED von links
DataRefIdent r2Ident[][58] = {
    "sim/cockpit2/annunciators/fuel_pressure"
};

SimLEDBase *r2Anncs[] = {
    new SimLEDIntDR(-1, -1, r2Ident[0], 1, 1, false, false)
};

/// dritte LED
DataRefIdent r3Ident[][58] = {
    "sim/cockpit2/annunciators/oil_pressure_low[0]",
    "sim/cockpit2/annunciators/oil_pressure_low[1]"
};
SimLEDBase *r3Anncs[] = {
    new SimLEDIntDR(-1, -1, r3Ident[0]),
    new SimLEDIntDR(-1, -1, r3Ident[1])
};

/// vierte LED
DataRefIdent r4Ident[][58] = {
    "sim/cockpit2/annunciators/inverter_off[0]",
    "sim/cockpit2/annunciators/inverter_off[1]"
};
SimLEDBase *r4Anncs[] = {
    new SimLEDIntDR(-1, -1, r4Ident[0]),
    new SimLEDIntDR(-1, -1, r4Ident[1]),
    new SimLEDIntDR(-1, -1, r4Ident[2]),
    new SimLEDIntDR(-1, -1, r4Ident[3])
};

/// fünfte Led
DataRefIdent r5Ident[][58] = {
    "sim/cockpit2/electrical/APU_generator_on",
    "sim/operation/failures/rel_APU_press"
};
SimLEDBase *r5Anncs[] = {
    new SimLEDIntDR(-1, -1, r5Ident[0]),
    new SimLEDIntDR(-1, -1, r5Ident[1])
};

/// sechste Led
DataRefIdent r6Ident[][58] = {
    "sim/cockpit2/annunciators/stall_warning"
};
SimLEDBase *r6Anncs[] = {
    new SimLEDIntDR(-1, -1, r6Ident[0])
};

/*
//! 6 Cautions LEDs rot vlnr + 1 Master caution
/// FlightSimInteger caution[7];

 DataRefIdent cautionIdent[][58] = {
    "sim/cockpit/electrical/gpu_on",
    "sim/cockpit2/annunciators/oil_pressure",
    "sim/cockpit2/annunciators/oil_temperature",
    "sim/cockpit2/annunciators/master_caution"
};

//                     ledNr, regNr, *ident,low, high, invert, enableTest, *hasPowerFlag
SimLEDBase *caution[] = {
    new SimLEDIntDR(0, 2, cautionIdent[0]),
      new SimLEDIntDR(1, 2, cautionIdent[1]),
      new SimLEDIntDR(2, 2, cautionIdent[2]),
      new SimLEDIntDR(3, 2, cautionIdent[3]),
      new SimLEDIntDR(4, 2, cautionIdent[4]),
      new SimLEDIntDR(5, 2, cautionIdent[5]),
      new SimLEDIntDR(6, 0, cautionIdent[6]),//master caution
};
*/

//! 6 Warnungs LEDs gelb vlnr
//FlightSimInteger warning[6];
DataRefIdent warningIdent[][58] = {
/// "sim/567890123456789012345678901234567890123456789012345678"
    "sim/cockpit2/annunciators/gear_warning",
    "sim/cockpit/warnings/annunciators/generator_off[0]",
    "sim/cockpit/warnings/annunciators/generator_off[1]",
    "sim/cockpit2/electrical/APU_running",
    "sim/cockpit2/annunciators/reverser_deployed",
    "sim/cockpit2/annunciators/inverter",
    "sim/cockpit2/annunciators/pitot_heat"
};
SimLEDBase *warning[] = {

    // ledNr, regNr, *ident, low, high, invert, enableTest, *hasPowerFlag
    new SimLEDIntDR(6, 2, warningIdent[0]),
    new SimLEDIntDR(7, 2, warningIdent[1]),
    new SimLEDIntDR(0, 1, warningIdent[2]),
    new SimLEDIntDR(1, 1, warningIdent[3]),
    new SimLEDIntDR(2, 1, warningIdent[4]),
    new SimLEDIntDR(3, 1, warningIdent[5])
};

//! 6 Radio LEDs Select vlnr ggbbrr
//FlightSimInteger radio_active[6];
DataRefIdent radio_actIdent[][58] = {
    "sim/cockpit2/radios/actuators/audio_selection_com1",
    "sim/cockpit2/radios/actuators/audio_selection_com2",
    "sim/cockpit2/radios/actuators/audio_selection_nav1",
    "sim/cockpit2/radios/actuators/audio_selection_nav2",
    "sim/cockpit2/radios/actuators/audio_selection_adf1",
    "sim/cockpit2/radios/actuators/audio_selection_adf2"
};
SimLEDBase *radio_act[] = {
    new SimLEDIntDR(0, 5, radio_actIdent[0]),
    new SimLEDIntDR(1, 5, radio_actIdent[1]),
    new SimLEDIntDR(2, 5, radio_actIdent[2]),
    new SimLEDIntDR(3, 5, radio_actIdent[3]),
    new SimLEDIntDR(4, 5, radio_actIdent[4]),
    new SimLEDIntDR(5, 5, radio_actIdent[5])
};

//! 6 + 2 AutoPilot LEDs d2u vlnr grbgrb gg
//FlightSimInteger ap_active[7];
DataRefIdent auto_actIdent[][58] = {
    "sim/cockpit2/autopilot/altitude_hold_status",
    "sim/cockpit2/autopilot/vvi_status",
    "sim/cockpit2/autopilot/heading_status",
    "sim/cockpit2/autopilot/nav_status",
    "sim/cockpit2/autopilot/approach_status",
    "sim/cockpit2/autopilot/backcourse_status",
    "sim/cockpit2/autopilot/flight_director_mode"
};
SimLEDBase *auto_act[] = {
    new SimLEDIntDR(0, 4, auto_actIdent[0]),
    new SimLEDIntDR(1, 4, auto_actIdent[1]),
    new SimLEDIntDR(2, 4, auto_actIdent[2]),
    new SimLEDIntDR(3, 4, auto_actIdent[3]),
    new SimLEDIntDR(5, 4, auto_actIdent[4]),
    new SimLEDIntDR(6, 4, auto_actIdent[5]),
    new SimLEDIntDR(4, 4, auto_actIdent[6], 2, 2),
    new SimLEDIntDR(7, 4, auto_actIdent[6], 4, 4)
};


//! 4 Klappen LEDs gelb up2down     [0]
DataRefIdent led_flapsIdent[][58] = {
    "sim/flightmodel/controls/flaprat"
};
SimLEDBase *led_flaps[] = {
    new SimLEDFloatDR(4, 1, led_flapsIdent[0], 0.10, 1),
    new SimLEDFloatDR(5, 1, led_flapsIdent[0], 0.33, 1),
    new SimLEDFloatDR(6, 1, led_flapsIdent[0], 0.67, 1),
    new SimLEDFloatDR(7, 1, led_flapsIdent[0], 1.00, 1),
};

//! 1 Bremsen LED rot                [1]
DataRefIdent led_brakeIdent[][58] = {
    "sim/cockpit2/controls/parking_brake_ratio"
};
SimLEDBase *led_brake = {
    new SimLEDFloatDR(0, 0, led_brakeIdent[0], 0.50, 1)
};


//! 6 Fahrwerk LEDs rot und grün    [2-4]
DataRefIdent led_gearIdent[][58] = {
    "sim/aircraft/parts/acf_gear_deploy[0]",
    "sim/aircraft/parts/acf_gear_deploy[1]",
    "sim/aircraft/parts/acf_gear_deploy[2]",
    "sim/cockpit2/annunciators/gear_warning"
};
SimLEDBase *led_gear[] = {
    new SimLEDFloatDR(1, 0, led_gearIdent[2], 0.01, 1),//grün rechts
    new SimLEDFloatDR(2, 0, led_gearIdent[1], 0.01, 1),//grün mitte
    new SimLEDFloatDR(3, 0, led_gearIdent[0], 0.01, 1),//grün links
    new SimLEDFloatDR(4, 0, led_gearIdent[2], 0.01, 0.99),//rot links
    new SimLEDFloatDR(5, 0, led_gearIdent[1], 0.01, 0.99),//rot mitte
    new SimLEDFloatDR(6, 0, led_gearIdent[0], 0.01, 0.99),//rot rechts
    new SimLEDIntDR (4, 0, led_gearIdent[3]),
    new SimLEDIntDR (5, 0, led_gearIdent[3]),
    new SimLEDIntDR (6, 0, led_gearIdent[3])
};

//! 2 Engines LEDs l2r grün         [5-6]
DataRefIdent led_engineIdent[][58] = {
    "sim/flightmodel2/engines/engine_is_burning_fuel[0]",
    "sim/flightmodel2/engines/engine_is_burning_fuel[1]"
};
SimLEDBase *led_engine[] = {
    new SimLEDIntDR(7, 5, led_engineIdent[0]),
    new SimLEDIntDR(6, 5, led_engineIdent[1])
};


SimLEDBase *led_enc[] = {
    new SimLEDLocal(0, 3), //Efis_Led rot
    new SimLEDLocal(1, 3), //Efis_Led grün
    new SimLEDLocal(2, 3), //Gps_Led rot
    new SimLEDLocal(3, 3), //Gps_Led grün
    new SimLEDLocal(4, 3), //Radio_Led rot
    new SimLEDLocal(5, 3), //Radio_Led grün
    new SimLEDLocal(6, 3), //Ap_Led rot
    new SimLEDLocal(7, 3), //Ap_Led grün
};

b737::SystemAnnc *systemAnncs[] = {
    new b737::SystemAnnc(0, 2, r1Anncs, sizeof(r1Anncs)),
    new b737::SystemAnnc(1, 2, r2Anncs, sizeof(r2Anncs)),
    new b737::SystemAnnc(2, 2, r3Anncs, sizeof(r3Anncs)),
    new b737::SystemAnnc(3, 2, r4Anncs, sizeof(r4Anncs)),
    new b737::SystemAnnc(4, 2, r5Anncs, sizeof(r5Anncs)),
    new b737::SystemAnnc(5, 2, r6Anncs, sizeof(r6Anncs))
};

b737::MasterCaution masterCaution (7, 0, systemAnncs, sizeof(systemAnncs));

#endif // ASSIGNLED_H
