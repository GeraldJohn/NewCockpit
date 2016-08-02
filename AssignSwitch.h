#ifndef ASSIGNSWITCH_H
#define ASSIGNSWITCH_H

#include "SimSwitch.h"

//! Electrical Switches
DataRefIdent sw_elecIdent[][58] = {
    "sim/cockpit2/electrical/battery_on[0]",
    "sim/cockpit/electrical/gpu_on",
    "sim/cockpit2/electrical/APU_starter_switch",
    "sim/cockpit2/electrical/cross_tie",
    "sim/cockpit2/switches/avionics_power_on",
    "sim/cockpit2/electrical/generator_on[0]",
    "sim/cockpit2/electrical/generator_on[1]",
    "sim/cockpit2/electrical/APU_generator_on",
    "sim/cockpit2/electrical/inverter_on[0]",
    "sim/cockpit2/electrical/inverter_on[1]"
};
SimSwitchBase *sw_elec[] = {
    new SimSwitchInt(4, 7, sw_elecIdent[0]),
    new SimSwitchInt(7, 7, sw_elecIdent[1]),
    new SimSwitchInt(6, 0, sw_elecIdent[2], true, 2, 1),
    new SimSwitchInt(7, 0, sw_elecIdent[2], false, 0, 1),
    new SimSwitchInt(1, 7, sw_elecIdent[3]),
    new SimSwitchInt(0, 7, sw_elecIdent[4]),
    new SimSwitchInt(6, 7, sw_elecIdent[5]),
    new SimSwitchInt(5, 7, sw_elecIdent[6]),
    new SimSwitchInt(5, 0, sw_elecIdent[7]),
    new SimSwitchInt(3, 0, sw_elecIdent[8]),
    new SimSwitchInt(2, 0, sw_elecIdent[9]) };

//! Lights and other switches
DataRefIdent sw_sonstIdent[][58] = {
    "sim/cockpit2/switches/strobe_lights_on",
    "sim/cockpit2/switches/beacon_on",
    "sim/cockpit2/switches/navigation_lights_on",
    "sim/cockpit2/switches/taxi_light_on",
    "sim/cockpit2/switches/landing_lights_switch[0]",
    "sim/cockpit2/ice/ice_inlet_heat_on",
    "sim/cockpit2/ice/ice_prop_heat_on",
    "sim/cockpit2/ice/ice_pitot_heat_on_pilot",
    "sim/cockpit2/ice/ice_pitot_heat_on_copilot",
    "sim/cockpit2/engine/actuators/igniter_on[0]",
    "sim/cockpit2/engine/actuators/igniter_on[1]",
    "sim/cockpit2/switches/landing_lights_switch[1]"
};
SimSwitchBase *sw_sonst[] = {
    new SimSwitchInt(4, 0, sw_sonstIdent[0]),
    new SimSwitchInt(4, 6, sw_sonstIdent[1]),
    new SimSwitchInt(7, 6, sw_sonstIdent[2]),
    new SimSwitchInt(6, 6, sw_sonstIdent[3]),
    new SimSwitchInt(5, 6, sw_sonstIdent[4]),
    new SimSwitchInt(2, 6, sw_sonstIdent[5]),
    new SimSwitchInt(3, 6, sw_sonstIdent[6]),
    new SimSwitchInt(1, 6, sw_sonstIdent[7]),
    new SimSwitchInt(0, 6, sw_sonstIdent[8]),
    new SimSwitchInt(0, 5, sw_sonstIdent[9]),
    new SimSwitchInt(4, 5, sw_sonstIdent[10]),
    new SimSwitchInt(5, 6, sw_sonstIdent[11])
};

//! Special switches
DataRefIdent sw_spezIdent[][58] = {
    "sim/cockpit2/switches/fasten_seat_belts",
    "sim/cockpit2/switches/no_smoking",
    "sim/cockpit2/switches/rotor_brake",
    "sim/cockpit2/switches/clutch_engage",
    "sim/cockpit2/switches/canopy_open",
    "sim/cockpit2/pressurization/actuators/bleed_air_mode",
    "sim/cockpit2/engine/actuators/fuel_pump_on[0]",
    "sim/cockpit2/engine/actuators/fuel_pump_on[1]"
};
SimSwitchBase *sw_spez[] = {
    new SimSwitchInt(4, 2, sw_spezIdent[0]),
    new SimSwitchInt(1, 2, sw_spezIdent[1], false, 0, 1),
    new SimSwitchInt(1, 8, sw_spezIdent[2]),
    new SimSwitchInt(0, 8, sw_spezIdent[3], false, 0, 1),
    new SimSwitchInt(3, 2, sw_spezIdent[4], false, 0, 1),
    new SimSwitchInt(4, 1, sw_spezIdent[5], false, 4),
    new SimSwitchInt(0, 1, sw_spezIdent[5], false, 2),
    new SimSwitchInt(0, 2, sw_spezIdent[6]),
    new SimSwitchInt(2, 2, sw_spezIdent[7]) };

//! Two starter switches
DataRefIdent sw_startIdent[][58] = {
    "sim/starters/engage_starter_1",
    "sim/starters/engage_starter_2",
    "sim/cockpit2/engine/actuators/ignition_key[0]",
    "sim/cockpit2/engine/actuators/ignition_key[1]"
};
SimSwitchBase *sw_start[] = {
    new SimSwitchCom(2, 5, sw_startIdent[0], true),
    new SimSwitchCom(5, 5, sw_startIdent[1], true),
    new SimSwitchInt(1, 5, sw_startIdent[2], false, 0, 3),
    new SimSwitchInt(3, 5, sw_startIdent[3], false, 0, 3) };

//! Autopilot switches
DataRefIdent sw_apIdent[][58] = {
    "sim/cockpit2/radios/actuators/HSI_source_select_pilot",
    "sim/autopilot/fdir_servos_up_one",
    "sim/autopilot/fdir_servos_down_one",
    "sim/autopilot/altitude_hold",
    "sim/autopilot/vertical_speed",
    "sim/autopilot/heading",
    "sim/autopilot/NAV",
    "sim/autopilot/approach",
    "sim/autopilot/back_course"
};
SimSwitchBase *sw_ap[] = {
    new SimSwitchInt(2, 7, sw_apIdent[0], false, 2, 1),
    new SimSwitchInt(3, 7, sw_apIdent[0], false, 0, 1),
    new SimSwitchCom(1, 0, sw_apIdent[1], true),
    new SimSwitchCom(0, 0, sw_apIdent[2], true),
    new SimSwitchCom(4, 8, sw_apIdent[3], true),
    new SimSwitchCom(7, 8, sw_apIdent[4], true),
    new SimSwitchCom(6, 8, sw_apIdent[5], true),
    new SimSwitchCom(5, 8, sw_apIdent[6], true),
    new SimSwitchCom(3, 8, sw_apIdent[7], true),
    new SimSwitchCom(2, 8, sw_apIdent[8], true) };

//! Switches and Buttons for Radio
DataRefIdent sw_radioIdent[][58] = {
    "sim/transponder/transponder_ident",
    "sim/cockpit2/radios/actuators/transponder_mode",
    "sim/audio_panel/select_audio_com1",
    "sim/audio_panel/select_audio_com2",
    "sim/audio_panel/select_audio_nav1",
    "sim/audio_panel/select_audio_nav2",
    "sim/audio_panel/select_audio_adf1",
    "sim/audio_panel/select_audio_adf2"
};
SimSwitchBase *sw_radio[] = {
    new SimSwitchCom(5, 2, sw_radioIdent[0], true, 2),
    new SimSwitchInt(7, 5, sw_radioIdent[1], false, 2, 1),
    new SimSwitchInt(6, 5, sw_radioIdent[1], false, 0, 1),
    new SimSwitchCom(1, 1, sw_radioIdent[2], true),
    new SimSwitchCom(2, 1, sw_radioIdent[3], true),
    new SimSwitchCom(3, 1, sw_radioIdent[4], true),
    new SimSwitchCom(5, 1, sw_radioIdent[5], true),
    new SimSwitchCom(6, 1, sw_radioIdent[6], true),
    new SimSwitchCom(7, 1, sw_radioIdent[7], true) };

/*
//! GPS Command PushButtons
DataRefIdent gpsComPbIdent[][58] = {
    "sim/GPS/g430n1_cdi",
    "sim/GPS/g430n1_obs",
    "sim/GPS/g430n1_msg",
    "sim/GPS/g430n1_fpl",
    "sim/GPS/g430n1_vnav",
    "sim/GPS/g430n1_proc",
    "sim/GPS/g430n1_ent",
    "sim/GPS/g430n1_clr",
    "sim/GPS/g430n1_menu",
    "sim/GPS/g430n1_direct",
    "sim/GPS/g430n1_zoom_out",
    "sim/GPS/g430n1_zoom_in"
};
SimSwitchBase *sw_gpsCom[] = {
    new SimSwitchCom(4, 8, gpsComPbIdent[0], true, 1),
    new SimSwitchCom(7, 8, gpsComPbIdent[1], true, 1),
    new SimSwitchCom(6, 8, gpsComPbIdent[2], true, 1),
    new SimSwitchCom(5, 8, gpsComPbIdent[3], true, 1),
    new SimSwitchCom(3, 8, gpsComPbIdent[4], true, 1),
    new SimSwitchCom(2, 8, gpsComPbIdent[5], true, 1),
    new SimSwitchCom(1, 1, gpsComPbIdent[6], true, 1),
    new SimSwitchCom(2, 1, gpsComPbIdent[7], true, 1),
    new SimSwitchCom(3, 1, gpsComPbIdent[8], true, 1),
    new SimSwitchCom(5, 1, gpsComPbIdent[9], true, 1),
    new SimSwitchCom(6, 1, gpsComPbIdent[10], true, 1),
    new SimSwitchCom(7, 1, gpsComPbIdent[11], true, 1)
};

*/


//! Eight Positions of the Radio Rotary Switches
SimSwitchBase *sw_radio_mode[8] = {
    new SimSwitchLocal(4, 3, 0),
    new SimSwitchLocal(0, 3, 1),
    new SimSwitchLocal(1, 3, 2),
    new SimSwitchLocal(2, 3, 3),
    new SimSwitchLocal(7, 3, 4),
    new SimSwitchLocal(3, 3, 5),
    new SimSwitchLocal(5, 3, 6),
    new SimSwitchLocal(6, 3, 7) };

//! Eight Positions of the Autopilot Rotary Switches
SimSwitchBase *sw_ap_mode[8] = {
    new SimSwitchLocal(0, 9, 0),
    new SimSwitchLocal(1, 9, 1),
    new SimSwitchLocal(2, 9, 2),
    new SimSwitchLocal(3, 9, 3),
    new SimSwitchLocal(4, 9, 4),
    new SimSwitchLocal(5, 9, 5),
    new SimSwitchLocal(6, 9, 6),
    new SimSwitchLocal(7, 9, 7) };

//! Eight Positions of the GPS Rotary Switches
SimSwitchBase *sw_gps_mode[8] = {
    new SimSwitchLocal(4, 4, 0),
    new SimSwitchLocal(0, 4, 1),
    new SimSwitchLocal(1, 4, 2),
    new SimSwitchLocal(2, 4, 3),
    new SimSwitchLocal(7, 4, 4),
    new SimSwitchLocal(3, 4, 5),
    new SimSwitchLocal(5, 4, 6),
    new SimSwitchLocal(6, 4, 7) };

//! Swap, Reset and Recall Switch
SimSwitchBase *sw_local[3] = {
    new SimSwitchLocal(5, 2),
    new SimSwitchLocal(6, 2),
    new SimSwitchLocal(7, 2)
};

#endif // ASSIGNSWITCH_H




/*
 DataRefIdent sw_anncIdent[][58] = {
  "sim/annunciator/test_all_annunciators",
  "sim/annunciator/clear_master_warning"
 };

 SimSwitchBase *sw_annc[] = {
  new SimSwitchCom(7, 2, sw_anncIdent[0]),
  new SimSwitchCom(6, 2, sw_anncIdent[1]) };






 */
