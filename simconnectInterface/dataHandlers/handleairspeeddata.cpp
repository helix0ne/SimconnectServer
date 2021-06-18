#include "../simconnectthread.ih"

void SimconnectThread::handleAirspeedData(const PfdAirspeedStruct &newData)
{
    DataIdentifiers id = DataIdentifiers::AIRSPEED;
    QByteArray dataToSend(reinterpret_cast<char *>(&id), sizeof(id));

    d_lastAirspeedData.airspeed = newData.airspeed;
    dataToSend.append(reinterpret_cast<const char *>(&newData.airspeed), sizeof(d_lastAirspeedData.airspeed));

    if (fabs(d_lastAirspeedData.max_speed - newData.max_speed) >= 0.09)
    {
        d_lastAirspeedData.max_speed = newData.max_speed;
        id = DataIdentifiers::MAX_SPEED;
        dataToSend.append(reinterpret_cast<const char *>(&id), sizeof(id));
        dataToSend.append(reinterpret_cast<const char *>(&newData.max_speed), sizeof(newData.max_speed));
    }

    if (d_lastAirspeedData.true_airspeed != newData.true_airspeed)
    {
        d_lastAirspeedData.true_airspeed = newData.true_airspeed;
        id = DataIdentifiers::TRUE_AIRSPEED;
        dataToSend.append(reinterpret_cast<const char *>(&id), sizeof(id));
        dataToSend.append(reinterpret_cast<const char *>(&newData.true_airspeed), sizeof(newData.true_airspeed));
    }

    if (d_lastAirspeedData.ref_speed != newData.ref_speed)
    {
        d_lastAirspeedData.ref_speed = newData.ref_speed;
        id = DataIdentifiers::REF_SPEED;
        dataToSend.append(reinterpret_cast<const char *>(&id), sizeof(id));
        dataToSend.append(reinterpret_cast<const char *>(&newData.ref_speed), sizeof(newData.ref_speed));
        d_updateApInfo = true;
    }

    emit sendData(dataToSend);
}
