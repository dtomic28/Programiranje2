//
// Created by danijel on 4/1/2024.
//

#include "Person.h"

Person::Person(const std::string &firstName, const std::string &lastName) : firstName(firstName), lastName(lastName){}

Person::Person() : firstName("Janez"), lastName("Novak") {}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

std::string Person::toString() const {
    return "Name: " + firstName + " LastName: " + lastName;
}

Person::Person(const Person &person) = default;
