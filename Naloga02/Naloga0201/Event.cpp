//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Event.h"
#include <string>
#include <iostream>

Event::Event(const std::string &title, float price, unsigned int numTickets) {
    this->title = title;
    this->price = price;
    this->numTickets = numTickets;
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
    this->price = price;
}

std::string Event::toString() {
    return(this->title + " (" + std::to_string(this->price) + ") " + "Num of tickets: " + std::to_string(this->numTickets));
}

void Event::print() {
    std::cout << this->toString() << std::endl;
}

void Event::setTitle(std::string &title) {
    this->title = title;
}