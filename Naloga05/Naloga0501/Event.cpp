//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Event.h"
#include <string>
#include <iostream>
#include <cmath>

unsigned int Event::MaxId = -1;

std::string Event::getTitle() const {
    return this->title;
}

float Event::getPrice() const {
    return this->price;
}

unsigned int Event::getNumTickets() const {
    return this->numTickets;
}

void Event::setNumTickets(unsigned int numTickets) {
    this->numTickets = numTickets;
}

void Event::setPrice(float price) {
    this->price = std::abs(price);
}

std::string Event::toString() const {
    return ("Id: " + std::to_string(this->id) + "\n" +
            "Title: " + this->title + "\n" +
            "Price: " + std::to_string(this->price) + "\n" +
            "Num of tickets: " + std::to_string(this->numTickets) + "\n" +
            "Age group: " + Event::eventAgeGroupToString(this->ageGroup) + "\n" +
            "Date: " + date.toString() + "\n");
}

void Event::print() const {
    std::cout << this->toString() << std::endl;
}

void Event::setTitle(std::string &title) {
    this->title = title;
}

Event::Event() : price(0), numTickets(0),
                 location(nullptr), ageGroup(),
                 title("Event"), date() {
    this->id = ++MaxId;
}

Event::Event(const Event &event) = default;

Location *Event::getLocation() const {
    return location;
}

void Event::setLocation(Location *location) {
    Event::location = location;
}

Event::Event(const std::string &title, float price, unsigned int numTickets, Location *location, const Date &date,
             EventAgeGroup ageGroup) : id(id), price(price),
                                       numTickets(numTickets),
                                       location(location), date(date), ageGroup(ageGroup),
                                       title(title) {
    this->id = ++MaxId;

}

bool Event::sellTicket(unsigned int numOfTickets) {
    if (numOfTickets <= 0)
        return false;

    this->numTickets -= numOfTickets;
    return true;
}

int Event::getId() const {
    return this->id;
}

EventAgeGroup Event::getAgeGroup() const {
    return ageGroup;
}

void Event::setAgeGroup(EventAgeGroup ageGroup) {
    Event::ageGroup = ageGroup;
}

const Date &Event::getDate() const {
    return date;
}

void Event::setDate(const Date &date) {
    Event::date = date;
}

Event::~Event(){
    location = nullptr;
};

std::string Event::eventAgeGroupToString(EventAgeGroup ageGroup) {
    std::string result;
    switch (ageGroup) {
        case EventAgeGroup::Child: {
            result = "Child";
            break;
        }
        case EventAgeGroup::Adult: {
            result = "Adult";
            break;
        }
        case EventAgeGroup::Senior: {
            result = "Senior";
            break;
        }
        case EventAgeGroup::All: {
            result = "All";
            break;
        }
    }
    return result;
}

std::string Event::eventStatusToString(EventStatus status) {
    switch (status) {
        case EventStatus::Upcoming:
            return "Upcoming";
        case EventStatus::Ongoing:
            return "Ongoing";
        case EventStatus::Completed:
            return "Completed";
        default:
            return "Unknown";
    }
}
