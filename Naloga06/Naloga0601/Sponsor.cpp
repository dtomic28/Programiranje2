//
// Created by Danijel Tomić on 3. 04. 24.
//

#include "Sponsor.h"
Sponsor::Sponsor(const std::string& name, unsigned int yearsOfSponsorship)
    : name(name)
    , yearsOfSponsorship(yearsOfSponsorship)
{
}
Sponsor::Sponsor()
    : name("Sponsor")
    , yearsOfSponsorship(0)
{
}
Sponsor::Sponsor(const Sponsor& sponsor) = default;

Sponsor::~Sponsor() = default;

std::string Sponsor::toString() const
{
    return "Name: " + name + "\n" + " Years of sponsorship: " + std::to_string(yearsOfSponsorship) + "\n";
}
const std::string& Sponsor::getName() const
{
    return name;
}
unsigned int Sponsor::getYearsOfSponsorship() const
{
    return yearsOfSponsorship;
}
void Sponsor::setName(const std::string& name)
{
    Sponsor::name = name;
}
void Sponsor::setYearsOfSponsorship(unsigned int yearsOfSponsorship)
{
    Sponsor::yearsOfSponsorship = yearsOfSponsorship;
}
