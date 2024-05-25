//
// Created by danijel on 5/25/2024.
//

#ifndef PROGRAMIRANJE2_SENSOR_H
#define PROGRAMIRANJE2_SENSOR_H

#include <string>

class Sensor
{
protected:
    int id;
    bool active;

public:
    Sensor(int id, bool active);
    virtual ~Sensor() = default;

    int getId() const;
    bool isActive() const;
    virtual std::string toString() const;
    virtual float readValue() const = 0;
    virtual std::string serialize() const = 0;
};

#endif  // PROGRAMIRANJE2_SENSOR_H
