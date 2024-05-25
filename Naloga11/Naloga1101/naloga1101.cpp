//
// Created by danijel on 5/25/2024.
//
#include <iostream>
#include "SensorHub.h"
#include "TemperatureSensor.h"
#include "DuplicatedSensorIdException.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    SensorHub hub;
    try
    {
        hub.addSensor(std::make_shared<TemperatureSensor>(1, true, TemperatureUnit::Celsius));
        hub.addSensor(std::make_shared<TemperatureSensor>(2, false, TemperatureUnit::Fahrenheit));
        hub.addSensor(std::make_shared<TemperatureSensorGPS>(3, true, TemperatureUnit::Kelvin, 12.34, 56.78));
        hub.addSensor(std::make_shared<TemperatureSensorGPS>(4, true, TemperatureUnit::Celsius, 34.56, 78.90));
        hub.addSensor(std::make_shared<TemperatureSensor>(5, true, TemperatureUnit::Fahrenheit));

        hub.readValues();

        hub.writeSensorsToFile("sensors.csv");
        hub.clear();
        hub.readSensorsFromFile("sensors.csv");
        hub.readValues();
    }
    catch (const DuplicatedSensorIdException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}