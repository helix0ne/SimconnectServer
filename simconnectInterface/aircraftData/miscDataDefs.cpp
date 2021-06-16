#include "miscDataDefs.h"
using namespace std;

const vector<dataDef> slowDatadefVector = {
    { "FUEL WEIGHT PER GALLON", "kilograms", SIMCONNECT_DATATYPE_FLOAT64, 0 },
    { "FUEL TOTAL QUANTITY", "gallons", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "ENG FUEL FLOW GPH:1", "gallons per hour", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "ENG FUEL FLOW GPH:2", "gallons per hour", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "ENG FUEL FLOW GPH:3", "gallons per hour", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "ENG FUEL FLOW GPH:4", "gallons per hour", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "GPS GROUND SPEED", "knots", SIMCONNECT_DATATYPE_FLOAT32, 0 },
    { "AUTOPILOT AVAILABLE", "Bool", SIMCONNECT_DATATYPE_INT32, 0 },
    { "COM STATUS:1", "Enum", SIMCONNECT_DATATYPE_INT32, 0 },
    { "COM STATUS:2", "Enum", SIMCONNECT_DATATYPE_INT32, 0 },
    { "NAV AVAILABLE:1", "Bool", SIMCONNECT_DATATYPE_INT32, 0 },
    { "NAV AVAILABLE:2", "Bool", SIMCONNECT_DATATYPE_INT32, 0 }
};

const vector<dataDef> stringsDatadefVector = {
    { "GPS WP NEXT ID", "", SIMCONNECT_DATATYPE_STRING256, 0 },
    { "NAV IDENT:1", "", SIMCONNECT_DATATYPE_STRING256, 0 },
    { "NAV IDENT:2", "", SIMCONNECT_DATATYPE_STRING256, 0 },
    { "GPS WP PREV ID", "", SIMCONNECT_DATATYPE_STRING256, 0 }
};




