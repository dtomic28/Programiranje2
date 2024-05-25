//
// Created by danijel on 5/25/2024.
//

#ifndef PROGRAMIRANJE2_SENSORHUB_H
#define PROGRAMIRANJE2_SENSORHUB_H

#include "TemperatureSensorGPS.h"
#include <vector>
#include <memory>

using SensorPtr = std::shared_ptr<Sensor>;

class SensorHub
{
private:
    std::vector<SensorPtr> sensors;

public:
    SensorHub() = default;

    void addSensor(SensorPtr sensor);
    void readValues() const;
    void writeSensorsToFile(const std::string& filename) const;
    void readSensorsFromFile(const std::string& filename);
    void clear();
};

#endif  // PROGRAMIRANJE2_SENSORHUB_H
