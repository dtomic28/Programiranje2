//
// Created by danijel on 3/23/2024.
//

#include "EventOrganizer.h"
#include <iostream>

const std::string& EventOrganizer::getName() const
{
    return name;
}

void EventOrganizer::setName(const std::string& name)
{
    EventOrganizer::name = name;
}

const std::string& EventOrganizer::getWebAddress() const
{
    return webAddress;
}

void EventOrganizer::setWebAddress(const std::string& webAddress)
{
    EventOrganizer::webAddress = webAddress;
}

EventOrganizer::EventOrganizer(const std::string& name, const std::string& webAddress)
    : name(name)
    , webAddress(webAddress)
{
}

EventOrganizer::EventOrganizer()
    : name("Event organizer")
    , webAddress("www.eventorganizer.com")
{
}

EventOrganizer::EventOrganizer(const EventOrganizer& eventOrganizer) = default;

void EventOrganizer::addEvent(Event* event)
{
    events.push_back(event);
}

std::string EventOrganizer::toString() const
{
    return "Name: " + this->name + " - " + this->webAddress + "  " + "Events: " + eventsToString();
}

int EventOrganizer::findEventIndexById(int id) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getId() == id)
            return i;
    }
    return -1;
}

bool EventOrganizer::sellTicket(int eventId)
{
    int eventIndex = findEventIndexById(eventId);
    if (eventIndex < 0)
        return false;

    return events[eventIndex]->sellTicket();
}

std::string EventOrganizer::eventsToString() const
{
    std::string result = "{\n";
    for (auto event : events)
    {
        if (dynamic_cast<Concert*>(event))
        {
            result.append(dynamic_cast<Concert*>(event)->toString() + ", ");
        }
        else
        {
            result.append(event->toString() + ", ");
        }
    }
    result += "}";
    return result;
}

const std::vector<Event*>& EventOrganizer::getEvents() const
{
    return events;
}

EventOrganizer::~EventOrganizer()
{
    for (auto& event : events)
    {
        delete event;
    }
}