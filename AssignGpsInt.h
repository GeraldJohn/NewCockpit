#ifndef ASSIGNGPSINT_H
#define ASSIGNGPSINT_H

#include "SimGpsInt.h"

DataRefIdent gpsIdIdent[][58] = {
    "sim/cockpit/gps/destination_type"
};

//SimGpsIntData(ident, Page, Row, Pos, CModeMax, Low, Up, Faktor, Jump, NKSt = 0, *hasPowerFlag
SimGpsBase *gpsIdData[] = {
    new SimGpsIntData(gpsIdIdent[0], 0, 0, 0)
};



DataRefIdent efisIdent[][58] = {
    "sim/cockpit2/EFIS/map_range", //Map range, 6, where 6 is the longest range.
    "sim/cockpit2/EFIS/map_mode", //Map mode. 0=approach, 1=vor,2=map,3=nav,4=plan
    "sim/cockpit2/EFIS/EFIS_airport_on", //On the moving map, show the airports or not.
    "sim/cockpit2/EFIS/EFIS_fix_on", //On the moving map, show the fixes or not.
    "sim/cockpit2/EFIS/EFIS_vor_on", //On the moving map, show the VORs or not.
    "sim/cockpit2/EFIS/EFIS_ndb_on", //On the moving map, show the NDBs or not.
    "sim/cockpit2/EFIS/EFIS_tcas_on", //On the moving map, show the TCAS or not.
    "sim/cockpit2/EFIS/EFIS_weather_on", //On the moving map, show the weather or not.
};


//SimGpsIntData(ident, Page, Row, Pos, CModeMax, Low, Up, Faktor, Jump, NKSt = 0, *hasPowerFlag
SimGpsBase *gpsEfisData[] = {
    new SimGpsIntData(efisIdent[0], 1, 0, 9, 1, 0, 6, 1, false),
    new SimGpsIntData(efisIdent[1], 1, 1, 9, 1, 0, 4, 1, false),
    new SimGpsIntData(efisIdent[2], 1, 3, 9),
    new SimGpsIntData(efisIdent[3], 1, 3, 11),
    new SimGpsIntData(efisIdent[4], 1, 3, 13),
    new SimGpsIntData(efisIdent[5], 1, 3, 15),
    new SimGpsIntData(efisIdent[6], 1, 3, 17),
    new SimGpsIntData(efisIdent[7], 1, 3, 19)
};



#endif // ASSIGNGPSINT_H


/*,
"sim/cockpit2/radios/indicators/gps_nav_id[0]",    //alle Modes 1 - 4
"sim/cockpit2/radios/indicators/gps_nav_id[1]",
"sim/cockpit2/radios/indicators/gps_nav_id[2]",
"sim/cockpit2/radios/indicators/gps_nav_id[3]"
    new SimGpsIntData(gpsIdIdent[1], 0, 0, 9),
    new SimGpsIntData(gpsIdIdent[2], 0, 0, 10),
    new SimGpsIntData(gpsIdIdent[3], 0, 0, 11),
    new SimGpsIntData(gpsIdIdent[4], 0, 0, 12)


// new SimGpsIntData(gpsIdIdent[1], 0, 1), //! Efis Anzeige_elemente
// new SimGpsIntData(gpsIdIdent[2], 0, 2),
// new SimGpsIntData(gpsIdIdent[3], 0, 3),
// new SimGpsIntData(gpsIdIdent[3], 0, 3)

 "sim/cockpit2/EFIS/map_mode_is_HSI", //Map is in HSI mode, 0 or 1. CTR on HSI2
 "sim/cockpit2/EFIS/argus_mode", //Argus mode, 7=departure,8=enroute,9=approach,10=radar_on
 "sim/cockpit2/EFIS/ecam_mode", //ECAM mode, 0=engine,1=fuel,2=controls,3=hydraulics,4=failures
 "sim/cockpit2/EFIS/EFIS_1_selection_pilot", //EFIS waypoint 1 is showing: 0=ADF1, 1=OFF, or 2=VOR1 -- Pilot
 "sim/cockpit2/EFIS/EFIS_1_selection_copilot", //EFIS waypoint 2 is showing: 0=ADF1, 1=OFF, or 2=VOR1 -- Copilot
 "sim/cockpit2/EFIS/EFIS_2_selection_pilot", //EFIS waypoint 1 is showing: 0=ADF2, 1=OFF, or 2=VOR2 -- Pilot
 "sim/cockpit2/EFIS/EFIS_2_selection_copilot", //EFIS waypoint 2 is showing: 0=ADF2, 1=OFF, or 2=VOR2 -- Copilot
 "sim/cockpit2/EFIS/EFIS_page[0]", //An array of EFIS page switches for selecting which EFIS page is visible.
 "sim/cockpit2/EFIS/EFIS_page[1]", //An array of EFIS page switches for selecting which EFIS page is visible.
  "sim/cockpit2/EFIS/EFIS_page[2]", //An array of EFIS page switches for selecting which EFIS page is visible.
  "sim/cockpit2/EFIS/EFIS_page[3]", //An array of EFIS page switches for selecting which EFIS page is visible.
  "sim/cockpit2/EFIS/EFIS_page[4]", //An array of EFIS page switches for selecting which EFIS page is visible.
  "sim/cockpit2/EFIS/EFIS_page[5]" //An array of EFIS page switches for selecting which EFIS page is visible.
   new SimGpsIntData(efisIdent[8], 1),
// new SimGpsIntData(efisIdent[9], 1),
// new SimGpsIntData(efisIdent[10], 1),
// new SimGpsIntData(efisIdent[11], 1),
// new SimGpsIntData(efisIdent[12], 1),
// new SimGpsIntData(efisIdent[13], 1),
// new SimGpsIntData(efisIdent[14], 1),
// new SimGpsIntData(efisIdent[15], 1),
// new SimGpsIntData(efisIdent[16], 1),
// new SimGpsIntData(efisIdent[17], 1),
// new SimGpsIntData(efisIdent[18], 1),
// new SimGpsIntData(efisIdent[19], 1),
// new SimGpsIntData(efisIdent[20], 4)
*/
