//
// Created by Danijel Tomić on 8. 04. 24.
//

#ifndef PROGRAMIRANJE2_SLOWFOODEXPIRIENCE_H
#define PROGRAMIRANJE2_SLOWFOODEXPIRIENCE_H
#include "Event.h"
class SlowFoodExpirience : public Event
{
private:
    std::string cook;
    unsigned int numMeals;

public:
    SlowFoodExpirience(const std::string& title,
                       float price,
                       unsigned int numTickets,
                       Location* location,
                       const Date& date,
                       EventAgeGroup ageGroup,
                       const std::string& cook,
                       unsigned int numMeals);

    SlowFoodExpirience();

    SlowFoodExpirience(const SlowFoodExpirience& slowFoodExpirience);

    ~SlowFoodExpirience();
    const std::string& getCook() const;
    void setCook(const std::string& cook);
    unsigned int getNumMeals() const;
    void setNumMeals(unsigned int numMeals);
    std::string toString() const override;
};

#endif  // PROGRAMIRANJE2_SLOWFOODEXPIRIENCE_H
