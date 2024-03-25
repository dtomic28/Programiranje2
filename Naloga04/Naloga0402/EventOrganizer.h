//
// Created by danijel on 3/23/2024.
//

#ifndef PROGRAMIRANJE2_EVENTORGANIZER_H
#define PROGRAMIRANJE2_EVENTORGANIZER_H
#include <string>
#include <vector>
#include "Event.h"

class EventOrganizer {
private:
    std::string name;
    std::string webAddress;
    std::vector<Event> events;

    int findEventIndexById(int id) const;
    std::string eventsToString() const;
public:
    EventOrganizer(const std::string &name, const std::string &webAddress);
    EventOrganizer();
    EventOrganizer(const EventOrganizer &eventOrganizer);

    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);

    [[nodiscard]] const std::string &getWebAddress() const;

    void setWebAddress(const std::string &webAddress);

    void addEvent(const Event& event);
    [[nodiscard]] std::string toString() const;
    bool sellTicket(int eventId);

    const std::vector<Event> &getEvents() const;
    std::vector<Event> getEventsByStatus(EventStatus status) const;
    bool removeCompleatedEvents();
};


#endif //PROGRAMIRANJE2_EVENTORGANIZER_H
