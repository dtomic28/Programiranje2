//
// Created by danijel on 3/23/2024.
//

#include "EventOrganizer.h"

const std::string &EventOrganizer::getName() const {
    return name;
}

void EventOrganizer::setName(const std::string &name) {
    EventOrganizer::name = name;
}

const std::string &EventOrganizer::getWebAddress() const {
    return webAddress;
}

void EventOrganizer::setWebAddress(const std::string &webAddress) {
    EventOrganizer::webAddress = webAddress;
}

EventOrganizer::EventOrganizer(const std::string &name, const std::string &webAddress) :name(name), webAddress(webAddress) {}

EventOrganizer::EventOrganizer() : name("Event organizer"), webAddress("www.eventorganizer.com") {}

EventOrganizer::EventOrganizer(const EventOrganizer &eventOrganizer) = default;

void EventOrganizer::addEvent(const Event &event) {
    events.push_back(event);
}

std::string EventOrganizer::toString() const {

}

int EventOrganizer::findEventIndexById(int id) {
    for(int i = 0; i<events.size(); i++){
        if(events[i].getId() == id)
            return i;
    }
    return -1;
}

bool EventOrganizer::sellTicket(int eventId) {
    unsigned int eventIndex = findEventIndexById(eventId);
    if(eventIndex > 0)
        return false;

    return events[eventIndex].sellTicket();
}
