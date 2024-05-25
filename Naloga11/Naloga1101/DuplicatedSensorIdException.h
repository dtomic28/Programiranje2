//
// Created by danijel on 5/25/2024.
//

#ifndef PROGRAMIRANJE2_DUPLICATEDSENSORIDEXCEPTION_H
#define PROGRAMIRANJE2_DUPLICATEDSENSORIDEXCEPTION_H
#include <string>
#include <exception>

class DuplicatedSensorIdException : public std::exception
{
private:
    std::string message;

public:
    DuplicatedSensorIdException(int id);
    const char* what() const noexcept override;
};

#endif  // PROGRAMIRANJE2_DUPLICATEDSENSORIDEXCEPTION_H
