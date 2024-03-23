//
// Created by Dragana on 14. 03. 2024.
//

#ifndef TASK0401_LOCATION_H
#define TASK0401_LOCATION_H

#include <string>

class Location {
private:
    std::string name;
    std::string street;
    std::string city;
    std::string country;

public:
    Location(const std::string &name, const std::string &street, const std::string &city, const std::string &country);

    [[nodiscard]] const std::string &getName() const;
    void setName(const std::string &name);

    [[nodiscard]] const std::string &getStreet() const;
    void setStreet(const std::string &street);

    [[nodiscard]] const std::string &getCity() const;
    void setCity(const std::string &city);

    [[nodiscard]] const std::string &getCountry() const;
    void setCountry(const std::string &country);

    [[nodiscard]] std::string toString() const;
};


#endif //TASK0401_LOCATION_H
