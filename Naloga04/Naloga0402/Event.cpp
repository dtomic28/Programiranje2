//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Event.h"
#include <string>
#include <iostream>
#include <cmath>

unsigned int Event::MaxId = -1;

std::string Event::getTitle() const
{
    return this->title;
}

float Event::getPrice() const
{
    return this->price;
}

unsigned int Event::getNumTickets() const
{
    return this->numTickets;
}

void Event::setNumTickets(unsigned int numTickets)
{
    this->numTickets = numTickets;
}

void Event::setPrice(float price)
{
    this->price = std::abs(price);
}

std::string Event::toString() const
{
    return ("Id: " + std::to_string(this->id) + "\n" + "Title: " + this->title + "\n" + "Price: " + std::to_string(this->price) + "\n" +
            "Num of tickets: " + std::to_string(this->numTickets) + "\n" + "Age group: " + eventAgeGroupToString(this->ageGroup) + "\n" +
            "Start time: " + this->start.toString() + "\n" + "End time: " + this->end.toString() + "\n" +
            "Status: " + eventStatusToString(getEventStatus()) + "\n");
}

void Event::print() const
{
    std::cout << this->toString() << std::endl;
}

void Event::setTitle(std::string& title)
{
    this->title = title;
}

Event::Event()
    : price(0)
    , numTickets(0)
    , location(nullptr)
    , ageGroup()
    , title("Event")
    , start(start)
    , end(end)
{
    this->id = ++MaxId;
}

Event::Event(const Event& event) = default;

Location* Event::getLocation() const
{
    return location;
}

void Event::setLocation(Location* location)
{
    Event::location = location;
}

Event::Event(const std::string& title,
             float price,
             unsigned int numTickets,
             Location* location,
             const Date& date,
             EventAgeGroup ageGroup,
             const DateTime& start,
             const DateTime& end)
    : id(id)
    , price(price)
    , numTickets(numTickets)
    , location(location)
    , start(start)
    , end(end)
    , ageGroup(ageGroup)
    , title(title)
{
    this->id = ++MaxId;
}

bool Event::sellTicket(unsigned int numOfTickets)
{
    if (numOfTickets <= 0)
        return false;

    this->numTickets -= numOfTickets;
    return true;
}

int Event::getId() const
{
    return this->id;
}

EventAgeGroup Event::getAgeGroup() const
{
    return ageGroup;
}

void Event::setAgeGroup(EventAgeGroup ageGroup)
{
    Event::ageGroup = ageGroup;
}

const DateTime& Event::getStart() const
{
    return start;
}

void Event::setStart(const DateTime& start)
{
    Event::start = start;
}

const DateTime& Event::getEnd() const
{
    return end;
}

void Event::setEnd(const DateTime& anEnd)
{
    end = anEnd;
}

EventStatus Event::getEventStatus() const
{
    DateTime currentDateTime = DateTime::getCurrentDateTime();

    if (currentDateTime < start)
    {
        return Upcoming;
    }
    else if (currentDateTime >= start && currentDateTime <= end)
    {
        return Ongoing;
    }
    else
    {
        return Completed;
    }
}

std::string eventAgeGroupToString(EventAgeGroup ageGroup)
{
    std::string result;
    switch (ageGroup)
    {
        case Child:
        {
            result = "Child";
            break;
        }
        case Adult:
        {
            result = "Adult";
            break;
        }
        case Senior:
        {
            result = "Senior";
            break;
        }
        case All:
        {
            result = "All";
            break;
        }
    }
    return result;
}

std::string eventStatusToString(EventStatus status)
{
    switch (status)
    {
        case Upcoming:
            return "Upcoming";
        case Ongoing:
            return "Ongoing";
        case Completed:
            return "Completed";
        default:
            return "Unknown";
    }
}
