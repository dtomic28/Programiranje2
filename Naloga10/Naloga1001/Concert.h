//
// Created by danijel on 3/30/2024.
//

#ifndef PROGRAMIRANJE2_CONCERT_H
#define PROGRAMIRANJE2_CONCERT_H
#include "Event.h"
#include <iostream>

enum class ConcertType
{
    Rock = 0,
    Pop = 1,
    Classical = 2,
    Metal = 3
};

class Concert : public Event
{
private:
    std::string performer;
    ConcertType concertType;

public:
    Concert(const std::string& title,
            float price,
            unsigned int numTickets,
            Location* location,
            const Date& date,
            EventAgeGroup ageGroup,
            const std::string& performer,
            ConcertType type);

    Concert();

    Concert(const Concert& Concert);

    ConcertType getConcertType() const;

    void setConcertType(ConcertType concertType);

    const std::string& getPerformer() const;

    void setPerformer(const std::string& performer);

    std::string toString() const override;

    static std::string concertTypeToString(ConcertType concertType);
};

class PrintIfConcert
{
public:
    void operator()(Event* e)
    {
        if (dynamic_cast<Concert*>(e))
        {
            std::cout << e->toString() << std::endl;
        }
    }
};

#endif  // PROGRAMIRANJE2_CONCERT_H
