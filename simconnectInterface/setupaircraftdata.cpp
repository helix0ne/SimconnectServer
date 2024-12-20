#include "simconnectthread.ih"


void SimconnectThread::setupAircraftData()
{
    if (d_currentAirplaneSettings.type == 0)
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:1",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:2",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:3",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:4",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);

        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N2:1",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n2Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N2:2",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n2Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N2:3",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n2Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N2:4",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n2Epsilon);

        if (d_currentAirplaneSettings.egtReplacesItt)
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "ENG EXHAUST GAS TEMPERATURE:1",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "ENG EXHAUST GAS TEMPERATURE:2",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "ENG EXHAUST GAS TEMPERATURE:3",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "ENG EXHAUST GAS TEMPERATURE:4",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
        }
        else
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG ITT:1",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG ITT:2",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG ITT:3",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG ITT:4",
                                           "celsius",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.ittEpsilon);
        }


        if (d_currentAirplaneSettings.numEngines == 4)
            d_aircraftHandler = &SimconnectThread::handleJetQuadEngdata;
        else if (d_currentAirplaneSettings.numEngines == 2)
            d_aircraftHandler = &SimconnectThread::handleJetTwinEngdata;
        else
            d_aircraftHandler = &SimconnectThread::handleJetSingleEngdata;
    }
    else if (d_currentAirplaneSettings.type == 1)
    {
        if (d_currentAirplaneSettings.usePropRpm)
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "PROP RPM:1",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "PROP RPM:2",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
        }
        else
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "GENERAL ENG RPM:1",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "GENERAL ENG RPM:2",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
        }

        if (d_currentAirplaneSettings.secondIsLoad)
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "RECIP ENG BRAKE POWER:1",
                                           "ft lb per second",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.secondEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "RECIP ENG BRAKE POWER:2",
                                           "ft lb per second",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.secondEpsilon);
        }
        else
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "RECIP ENG MANIFOLD PRESSURE:1",
                                           "kpa",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.secondEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "RECIP ENG MANIFOLD PRESSURE:2",
                                           "kpa",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.secondEpsilon);
        }

        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "GENERAL ENG EXHAUST GAS TEMPERATURE:1",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.egtEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "GENERAL ENG EXHAUST GAS TEMPERATURE:2",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.egtEpsilon);

        if (d_currentAirplaneSettings.numEngines == 2)
            d_aircraftHandler = &SimconnectThread::handlePropTwinEngdata;
        else
            d_aircraftHandler = &SimconnectThread::handlePropSingleEngdata;
    }
    else
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:1",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG N1:2",
                                       "percent",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.n1Epsilon);

        if (d_currentAirplaneSettings.torqueAsPct)
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG MAX TORQUE PERCENT:1",
                                           "percent",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.trqEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG MAX TORQUE PERCENT:2",
                                           "percent",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.trqEpsilon);
        }
        else
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG FREE TURBINE TORQUE:1",
                                           "Newton meter",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.trqEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "TURB ENG FREE TURBINE TORQUE:2",
                                           "Newton meter",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.trqEpsilon);
        }

        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG ITT:1",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.ittEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "TURB ENG ITT:2",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.ittEpsilon);

        if (d_currentAirplaneSettings.usePropRpm)
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "PROP RPM:1",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "PROP RPM:2",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
        }
        else
        {
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "GENERAL ENG RPM:1",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
            SimConnect_AddToDataDefinition(d_simConnectHandle,
                                           ENGINE_DEFINITION,
                                           "GENERAL ENG RPM:2",
                                           "rpm",
                                           SIMCONNECT_DATATYPE_FLOAT64,
                                           d_currentAirplaneSettings.rpmEpsilon);
        }

        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "GENERAL ENG EXHAUST GAS TEMPERATURE:1",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.egtEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "GENERAL ENG EXHAUST GAS TEMPERATURE:2",
                                       "celsius",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.egtEpsilon);

        if (d_currentAirplaneSettings.numEngines == 2)
            d_aircraftHandler = &SimconnectThread::handleTurbopropTwinEngdata;
        else
            d_aircraftHandler = &SimconnectThread::handleTurbopropSingleEngdata;
    }


    if (d_currentAirplaneSettings.fuelQtyByVolume)
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL LEFT QUANTITY",
                                       "liter",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL RIGHT QUANTITY",
                                       "liter",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL TOTAL QUANTITY",
                                       "liter",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
    }
    else
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL LEFT QUANTITY",
                                       "gallons",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL RIGHT QUANTITY",
                                       "gallons",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "FUEL TOTAL QUANTITY",
                                       "gallons",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelQtyEpsilon);
    }

    if (d_currentAirplaneSettings.fuelFlowByVolume)
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW GPH:1",
                                       "gallon per hour",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW GPH:2",
                                       "gallon per hour",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW GPH:3",
                                       "gallon per hour",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW GPH:4",
                                       "gallon per hour",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
    }
    else
    {
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW PPH:1",
                                       "kilograms per second",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW PPH:2",
                                       "kilograms per second",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW PPH:3",
                                       "kilograms per second",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
        SimConnect_AddToDataDefinition(d_simConnectHandle,
                                       ENGINE_DEFINITION,
                                       "ENG FUEL FLOW PPH:4",
                                       "kilograms per second",
                                       SIMCONNECT_DATATYPE_FLOAT64,
                                       d_currentAirplaneSettings.fuelFlowEpsilon);
    }

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL TEMPERATURE:1",
                                   "celsius",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilTempEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL TEMPERATURE:2",
                                   "celsius",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilTempEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL TEMPERATURE:3",
                                   "celsius",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilTempEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL TEMPERATURE:4",
                                   "celsius",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilTempEpsilon);

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL PRESSURE:1",
                                   "kpa",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilPressEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL PRESSURE:2",
                                   "kpa",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilPressEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL PRESSURE:3",
                                   "kpa",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilPressEpsilon);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "GENERAL ENG OIL PRESSURE:4",
                                   "kpa",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   d_currentAirplaneSettings.oilPressEpsilon);

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "APU PCT RPM",
                                   "percent",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.5f);

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "TRAILING EDGE FLAPS LEFT ANGLE",
                                   "degrees",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.5f);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "TRAILING EDGE FLAPS RIGHT ANGLE",
                                   "degrees",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.5f);

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "SPOILERS LEFT POSITION",
                                   "percent",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.5f);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "SPOILERS RIGHT POSITION",
                                   "percent",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.5f);

    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "ELEVATOR TRIM PCT",
                                   "percent Over 100",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.002f);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "RUDDER TRIM PCT",
                                   "percent Over 100",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.002f);
    SimConnect_AddToDataDefinition(d_simConnectHandle,
                                   ENGINE_DEFINITION,
                                   "AILERON TRIM PCT",
                                   "percent Over 100",
                                   SIMCONNECT_DATATYPE_FLOAT64,
                                   0.002f);
}
