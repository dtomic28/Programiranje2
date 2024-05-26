//
// Created by danijel on 5/25/2024.
//

#include "DuplicatedSensorIdException.h"
DuplicatedSensorIdException::DuplicatedSensorIdException(int id)
{
    message = "Sensor with ID " + std::to_string(id) + " already exists.";
}
const char* DuplicatedSensorIdException::what() const noexcept
{
    return message.c_str();
}
