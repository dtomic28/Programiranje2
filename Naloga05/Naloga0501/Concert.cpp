//
// Created by danijel on 3/30/2024.
//

#include "Concert.h"

Concert::Concert(const std::string &title, float price, unsigned int numTickets, Location *location, const Date &date,
                 EventAgeGroup ageGroup, const std::string &performer, ConcertType type) : Event(title, price, numTickets, location, date,
                                                                               ageGroup), performer(performer), concertType(type) {}

std::string Concert::toString() const {
    return Event::toString() + "Performer: " + performer + "\n" +
                               "Concert type: " + Concert::concertTypeToString(concertType) + "\n";
}

Concert::Concert() {}

ConcertType Concert::getConcertType() const {
    return concertType;
}

void Concert::setConcertType(ConcertType concertType) {
    Concert::concertType = concertType;
}

const std::string &Concert::getPerformer() const {
    return performer;
}

void Concert::setPerformer(const std::string &performer) {
    Concert::performer = performer;
}

std::string Concert::concertTypeToString(ConcertType concertType) {
    switch(concertType){
        case(ConcertType::Pop):
            return "Pop";
            break;
        case(ConcertType::Rock):
            return "Rock";
            break;
        case(ConcertType::Classical):
            return "Classical";
            break;
        case(ConcertType::Metal):
            return "Metal";
            break;
    }
    return "";
}

Concert::Concert(const Concert &Concert) = default;
