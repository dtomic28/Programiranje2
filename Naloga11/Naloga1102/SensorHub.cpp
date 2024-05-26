//
// Created by danijel on 5/25/2024.
//

#include "SensorHub.h"
#include "DuplicatedSensorIdException.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

void SensorHub::addSensor(SensorPtr newSensor)
{
    for (auto& sensor : sensors)
    {
        if (sensor->getId() == newSensor->getId())
        {
            throw DuplicatedSensorIdException(sensor->getId());
        }
    }
    sensors.push_back(newSensor);
}
void SensorHub::readValues() const
{
    for (const auto& s : sensors)
    {
        if (s->isActive())
        {
            std::cout << s->toString() << ": " << s->readValue() << std::endl;
        }
    }
}
void SensorHub::writeSensorsToFile(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file)
    {
        throw std::runtime_error("Could not open file for writing.");
    }

    for (const auto& sensor : sensors)
    {
        auto isGps = dynamic_cast<TemperatureSensorGPS*>(sensor.get());
        if (isGps)
        {
            file << isGps->serialize() << "\n";
        }
        else
        {
            auto isntGps = dynamic_cast<TemperatureSensor*>(sensor.get());
            file << isntGps->serialize() << "\n";
        }
    }
}
void SensorHub::readSensorsFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        throw std::runtime_error("Could not open file for writing.");
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string idStr, activeStr, unitStr, latStr, lonStr;
        std::getline(ss, idStr, ';');
        std::getline(ss, activeStr, ';');
        std::getline(ss, unitStr, ';');

        int id = std::stoi(idStr);
        bool active = static_cast<bool>(std::stoi(activeStr));
        TemperatureUnit unit = static_cast<TemperatureUnit>(std::stoi(unitStr));

        if (std::count_if(line.begin(), line.end(), [](char c) { return c == ';'; }) == 4)
        {
            std::getline(ss, latStr, ';');
            std::getline(ss, lonStr, ';');
            float latitude = std::stof(latStr);
            float longitude = std::stof(lonStr);
            addSensor(std::make_shared<TemperatureSensorGPS>(id, active, unit, latitude, longitude));
        }
        else
        {
            addSensor(std::make_shared<TemperatureSensor>(id, active, unit));
        }
    }
}
void SensorHub::clear()
{
    sensors.clear();
}
