#ifndef SHAREDSTRUCTS_H
#define SHAREDSTRUCTS_H

#include <stdint.h>
#include <vector>
#include <windows.h>
#include <windef.h>
#include "C:/MSFS SDK/SimConnect SDK/include/SimConnect.h"

struct dataDef
{
    const char* DatumName;
    const char* UnitsName;
    SIMCONNECT_DATATYPE DatumType;
    float fEpsilon;
};

#endif // SHAREDSTRUCTS_H