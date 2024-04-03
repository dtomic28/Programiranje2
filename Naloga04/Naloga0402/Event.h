//
// Created by Danijel Tomić on 7. 03. 24.
//

#ifndef PROGRAMIRANJE2_EVENT_H
#define PROGRAMIRANJE2_EVENT_H
#include <string>
#include "Date.h"
#include "Location.h"
#include "DateTime.h"

enum EventAgeGroup
{
    All = 0,
    Child = 1,
    Adult = 2,
    Senior = 3,
};

enum EventStatus
{
    Upcoming = 0,
    Ongoing = 1,
    Completed = 2
};

std::string eventAgeGroupToString(EventAgeGroup ageGroup);
std::string eventStatusToString(EventStatus status);

class Event
{
private:
    int id;
    std::string title;
    float price;
    unsigned int numTickets;
    Location* location;
    EventAgeGroup ageGroup;
    DateTime start;
    DateTime end;
    static unsigned int MaxId;

public:
    Event(const std::string& title,
          float price,
          unsigned int numTickets,
          Location* location,
          const Date& date,
          EventAgeGroup ageGroup,
          const DateTime& start,
          const DateTime& end);
    Event();
    Event(const Event& event);

    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] unsigned int getNumTickets() const;
    [[nodiscard]] Location* getLocation() const;
    [[nodiscard]] int getId() const;
    [[nodiscard]] EventAgeGroup getAgeGroup() const;
    [[nodiscard]] const DateTime& getStart() const;
    [[nodiscard]] const DateTime& getEnd() const;

    void setAgeGroup(EventAgeGroup ageGroup);
    void setTitle(std::string& title);
    void setPrice(float price);
    void setNumTickets(unsigned int numTickets);
    void setLocation(Location* location);
    void setStart(const DateTime& start);
    void setEnd(const DateTime& anEnd);

    [[nodiscard]] std::string toString() const;
    void print() const;
    bool sellTicket(unsigned int numOfTickets = 1);
    EventStatus getEventStatus() const;
};

#endif  // PROGRAMIRANJE2_EVENT_H
