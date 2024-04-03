//
// Created by Danijel Tomić on 7. 03. 24.
//

#ifndef PROGRAMIRANJE2_EVENT_H
#define PROGRAMIRANJE2_EVENT_H
#include <string>
#include "Date.h"
#include "Location.h"

enum EventAgeGroup
{
    All = 0,
    Child = 1,
    Adult = 2,
    Senior = 3,
};

std::string eventAgeGroupToString(EventAgeGroup ageGroup);

class Event
{
private:
    int id;
    std::string title;
    float price;
    unsigned int numTickets;
    Date date;
    Location* location;
    EventAgeGroup ageGroup;
    static unsigned int MaxId;

public:
    Event(const std::string& title, float price, unsigned int numTickets, Location* location, const Date& date, EventAgeGroup ageGroup);
    Event();
    Event(const Event& event);

    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] unsigned int getNumTickets() const;
    [[nodiscard]] const Date& getDate() const;
    [[nodiscard]] Location* getLocation() const;
    [[nodiscard]] int getId() const;
    [[nodiscard]] EventAgeGroup getAgeGroup() const;

    void setAgeGroup(EventAgeGroup ageGroup);
    void setTitle(std::string& title);
    void setDate(const Date& date);
    void setPrice(float price);
    void setNumTickets(unsigned int numTickets);
    void setLocation(Location* location);

    [[nodiscard]] std::string toString() const;
    void print() const;
    bool sellTicket(unsigned int numOfTickets = 1);
};

#endif  // PROGRAMIRANJE2_EVENT_H
