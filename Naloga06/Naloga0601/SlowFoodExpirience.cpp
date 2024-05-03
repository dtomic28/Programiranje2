//
// Created by Danijel Tomić on 8. 04. 24.
//

#include "SlowFoodExpirience.h"
SlowFoodExpirience::SlowFoodExpirience(const std::string& title,
                                       float price,
                                       unsigned int numTickets,
                                       Location* location,
                                       const Date& date,
                                       EventAgeGroup ageGroup,
                                       const std::string& cook,
                                       unsigned int numMeals)
    : Event(title, price, numTickets, location, date, ageGroup)
    , cook(cook)
    , numMeals(numMeals)
{
}
SlowFoodExpirience::~SlowFoodExpirience() = default;
std::string SlowFoodExpirience::toString() const
{
    return Event::toString() + "Cook: " + cook + "\n" + "Num of meals: " + std::to_string(numMeals) + "\n";
}
const std::string& SlowFoodExpirience::getCook() const
{
    return cook;
}
void SlowFoodExpirience::setCook(const std::string& cook)
{
    SlowFoodExpirience::cook = cook;
}
unsigned int SlowFoodExpirience::getNumMeals() const
{
    return numMeals;
}
void SlowFoodExpirience::setNumMeals(unsigned int numMeals)
{
    SlowFoodExpirience::numMeals = numMeals;
}
SlowFoodExpirience::SlowFoodExpirience()
    : numMeals(0)
    , cook("Cook")
    , Event()
{
}
SlowFoodExpirience::SlowFoodExpirience(const SlowFoodExpirience& slowFoodExpirience) = default;
