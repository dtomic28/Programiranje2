//
// Created by danijel on 5/25/2024.
//

#include "TemperatureSensorGPS.h"
#include <sstream>

std::string TemperatureSensorGPS::toString() const
{
    std::stringstream ss;
    ss << "TemperatureSensorGPS - ID: " << id << " Is active: " << (active ? "True" : "False") << " "
       << "Unit: " << TemperatureUnitToString(unit) << " Latitude:" << latitude << " Longitude: " << longitude << "\n";
    return ss.str();
}
std::string TemperatureSensorGPS::serialize() const
{
    std::stringstream ss;
    ss << TemperatureSensor::serialize() << ";" << latitude << ";" << longitude;
    return ss.str();
}
