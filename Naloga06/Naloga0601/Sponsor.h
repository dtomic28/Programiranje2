//
// Created by Danijel Tomić on 3. 04. 24.
//

#ifndef PROGRAMIRANJE2_SPONSOR_H
#define PROGRAMIRANJE2_SPONSOR_H
#include <string>

class Sponsor
{
protected:
    std::string name;
    unsigned int yearsOfSponsorship;

public:
    Sponsor(const std::string& name, unsigned int yearsOfSponsorship);
    Sponsor();
    Sponsor(const Sponsor& sponsor);
    void setName(const std::string& name);
    void setYearsOfSponsorship(unsigned int yearsOfSponsorship);

    virtual ~Sponsor();
    virtual float calculateScore() const = 0;
    virtual std::string getPromoText() const = 0;
    virtual std::string toString() const;
    const std::string& getName() const;
    unsigned int getYearsOfSponsorship() const;
};

#endif  // PROGRAMIRANJE2_SPONSOR_H
