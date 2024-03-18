//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Event.h"
#include <string>
#include <iostream>
#include <cmath>

Event::Event(std::string &title, float price, unsigned int numTickets, std::string &description) {
    this->title = title;
    this->price = price;
    this->numTickets = numTickets;
    this->description = description;
}

std::string Event::getTitle() {
    return this->title;
}

float Event::getPrice() {
    return this->price;
}

unsigned int Event::getNumTickets() {
   return this->numTickets;
}

void Event::setNumTickets(unsigned int numTickets) {
    this->numTickets = numTickets;
}

void Event::setPrice(float price) {
    this->price = std::abs(price);
}

std::string Event::toString() {
    return(this->title + " (" + std::to_string(this->price) + ") " + "Num of tickets: " + std::to_string(this->numTickets) + " Description: " + this->description);
}

void Event::print() {
    std::cout << this->toString() << std::endl;
}

void Event::setTitle(std::string &title) {
    this->title = title;
}

std::string Event::getDescription() {
   return this->description;
}

void Event::setDescription(std::string &description) {
    this->description = description;
}

Event::Event() {
    this->title = "Event";
    this->numTickets = 0;
    this->price = 0;
    this->description = "Description";
}

Event::Event(const Event &event) {
    this->title = event.title;
    this->price = event.price;
    this->numTickets = event.numTickets;
    this->description = event.description;
}
