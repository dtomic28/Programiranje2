//
// Created by danijel on 5/25/2024.
//

#include "TemperatureSensor.h"
#include <sstream>
#include <random>

std::string TemperatureSensor::toString() const
{
    std::stringstream ss;
    ss << "Sensor - ID: " << id << "Is active: " << (active ? "True" : "False") << " " << "Unit: " << TemperatureUnitToString(unit) << "\n";
    return ss.str();
}
float TemperatureSensor::readValue() const
{
    return static_cast<float>(rand() % 101);
}
std::string TemperatureSensor::TemperatureUnitToString(TemperatureUnit t)
{
    switch (t)
    {
        case TemperatureUnit::Celsius:
            return "Celsius";
        case TemperatureUnit::Fahrenheit:
            return "Fahrenheit";
        case TemperatureUnit::Kelvin:
            return "Kelvin";
    }
}

std::string TemperatureSensor::serialize() const
{
    std::stringstream ss;
    ss << id << ";" << active << ";" << static_cast<int>(unit);
    return ss.str();
}
