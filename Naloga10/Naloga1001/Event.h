//
// Created by Danijel Tomić on 7. 03. 24.
//

#ifndef PROGRAMIRANJE2_EVENT_H
#define PROGRAMIRANJE2_EVENT_H
#include <string>
#include "Date.h"
#include "Location.h"

enum class EventAgeGroup
{
    All = 0,
    Child = 1,
    Adult = 2,
    Senior = 3,
};

enum class EventStatus
{
    Upcoming = 0,
    Ongoing = 1,
    Completed = 2
};

class Event
{
private:
protected:
    static unsigned int MaxId;
    Date date;
    EventAgeGroup ageGroup;
    Location* location;
    int id;
    std::string title;
    float price;
    unsigned int numTickets;

public:
    Event(const std::string& title, float price, unsigned int numTickets, Location* location, const Date& date, EventAgeGroup ageGroup);
    Event();
    Event(const Event& event);
    virtual ~Event();

    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] unsigned int getNumTickets() const;
    [[nodiscard]] Location* getLocation() const;
    [[nodiscard]] int getId() const;
    [[nodiscard]] EventAgeGroup getAgeGroup() const;
    [[nodiscard]] const Date& getDate() const;

    void setAgeGroup(EventAgeGroup ageGroup);
    void setTitle(std::string& title);
    void setPrice(float price);
    void setDate(const Date& date);
    void setNumTickets(unsigned int numTickets);
    void setLocation(Location* location);

    virtual std::string toString() const;
    void print() const;
    bool sellTicket(unsigned int numOfTickets = 1);
    EventStatus getEventStatus() const;

    static std::string eventAgeGroupToString(EventAgeGroup ageGroup);
    static std::string eventStatusToString(EventStatus status);
};

#endif  // PROGRAMIRANJE2_EVENT_H
