//
// Created by Dragana on 14. 03. 2024.
//

#include "Location.h"

Location::Location(const std::string &name, const std::string &street, const std::string &city,
                   const std::string &country) : name(name), street(street), city(city), country(country) {}

const std::string &Location::getName() const {
    return name;
}

void Location::setName(const std::string &name) {
    this->name = name;
}

const std::string &Location::getStreet() const {
    return street;
}

void Location::setStreet(const std::string &street) {
    this->street = street;
}

const std::string &Location::getCity() const {
    return city;
}

void Location::setCity(const std::string &city) {
    this->city = city;
}

const std::string &Location::getCountry() const {
    return country;
}

void Location::setCountry(const std::string &country) {
    this->country = country;
}

std::string Location::toString() const {
    return name + ", " + street + ", " + city + ", " + country;
}
