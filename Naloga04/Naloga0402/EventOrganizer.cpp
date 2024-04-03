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

void EventOrganizer::addEvent(const Event& event)
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
        if (events[i].getId() == id)
            return i;
    }
    return -1;
}

bool EventOrganizer::sellTicket(int eventId)
{
    int eventIndex = findEventIndexById(eventId);
    if (eventIndex < 0)
        return false;

    return events[eventIndex].sellTicket();
}

std::string EventOrganizer::eventsToString() const
{
    std::string result = "{";
    for (auto event : events)
    {
        result.append(event.toString() + ", ");
    }
    result += "}";
    return result;
}

const std::vector<Event>& EventOrganizer::getEvents() const
{
    return events;
}

std::vector<Event> EventOrganizer::getEventsByStatus(EventStatus status) const
{
    std::vector<Event> eventsByStatus;
    for (auto& event : events)
    {
        if (event.getEventStatus() == status)
            eventsByStatus.push_back(event);
    }
    return eventsByStatus;
}

bool EventOrganizer::removeCompleatedEvents()
{
    std::vector<int> compleatedEvents;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getEventStatus() == EventStatus::Completed)
            compleatedEvents.push_back(i);
    }
    if (compleatedEvents.empty())
        return false;
    for (auto index : compleatedEvents)
        events.erase(events.begin() + index);
    return true;
}
