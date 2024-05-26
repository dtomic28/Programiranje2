//
// Created by danijel on 5/25/2024.
//

#ifndef PROGRAMIRANJE2_TEMPERATURESENSOR_H
#define PROGRAMIRANJE2_TEMPERATURESENSOR_H

#include "Sensor.h"

enum class TemperatureUnit
{
    Celsius,
    Fahrenheit,
    Kelvin
};

class TemperatureSensor : public Sensor
{
protected:
    TemperatureUnit unit;

public:
    TemperatureSensor(int id, bool active, TemperatureUnit unit)
        : Sensor(id, active)
        , unit(unit)
    {
    }

    TemperatureSensor() = delete;

    std::string toString() const override;

    float readValue() const override final;

    static std::string TemperatureUnitToString(TemperatureUnit t);

    std::string serialize() const override;
};

#endif  // PROGRAMIRANJE2_TEMPERATURESENSOR_H
