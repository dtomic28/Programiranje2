//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Event.h"
#include <string>
#include <iostream>
#include <cmath>

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
    return (this->title + " (" + std::to_string(this->price) + ") " + "Num of tickets: " +
            std::to_string(this->numTickets) + " Description: " + this->description);
}

void Event::print() const {
    std::cout << this->toString() << std::endl;
}

void Event::setTitle(std::string &title) {
    this->title = title;
}

Event::Event() : id(-1), price(0), numTickets(0),
                 location(nullptr), date(), ageGroup(),
                 title("Event") {}

Event::Event(const Event &event) = default;

const Date &Event::getDate() const {
    return date;
}

void Event::setDate(const Date &date) {
    Event::date = date;
}

Location *Event::getLocation() const {
    return location;
}

void Event::setLocation(Location *location) {
    Event::location = location;
}

Event::Event(int id, const std::string &title, float price, unsigned int numTickets, Location *location,
             const Date &date, EventAgeGroup ageGroup) : id(id), price(price), numTickets(numTickets),
                                                         location(location), date(date), ageGroup(ageGroup),
                                                         title(title) {

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

void Event::setId(int id) {
    this->id = id;
}
