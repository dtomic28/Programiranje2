//
// Created by danijel on 5/25/2024.
//

#include "Sensor.h"
#include <sstream>
Sensor::Sensor(int id, bool active)
    : id(id)
    , active(active)
{
}
int Sensor::getId() const
{
    return id;
}
bool Sensor::isActive() const
{
    return active;
}
std::string Sensor::toString() const
{
    std::stringstream ss;
    ss << "Sensor - ID: " << id << " Is active: " << (active ? "True" : "False");
    return ss.str();
}
