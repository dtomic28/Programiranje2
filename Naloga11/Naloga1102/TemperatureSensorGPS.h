//
// Created by danijel on 5/25/2024.
//

#ifndef PROGRAMIRANJE2_TEMPERATURESENSORGPS_H
#define PROGRAMIRANJE2_TEMPERATURESENSORGPS_H

#include "TemperatureSensor.h"

class TemperatureSensorGPS final : public TemperatureSensor
{
private:
    float latitude;
    float longitude;

public:
    TemperatureSensorGPS(int id, bool active, TemperatureUnit unit, float latitude, float longitude)
        : TemperatureSensor(id, active, unit)
        , latitude(latitude)
        , longitude(longitude)
    {
    }

    TemperatureSensorGPS() = delete;

    std::string toString() const override;

    std::string serialize() const override;
};

#endif  // PROGRAMIRANJE2_TEMPERATURESENSORGPS_H
