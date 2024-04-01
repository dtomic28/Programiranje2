//
// Created by danijel on 4/1/2024.
//

#ifndef PROGRAMIRANJE2_PERSON_H
#define PROGRAMIRANJE2_PERSON_H
#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string &firstName, const std::string &lastName);
    Person();
    Person(const Person &person);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    std::string toString() const;
};


#endif //PROGRAMIRANJE2_PERSON_H
