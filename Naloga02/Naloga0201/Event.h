//
// Created by Danijel Tomić on 7. 03. 24.
//

#ifndef PROGRAMIRANJE2_EVENT_H
#define PROGRAMIRANJE2_EVENT_H
#include <string>

class Event {
private:
    std::string title;
    float price;
    unsigned int numTickets;
    std::string description;
public:
    Event(std::string& title, float price, unsigned int numTickets, std::string& description);
    Event();
    Event(const Event &event);

    std::string getTitle();
    float getPrice();
    unsigned int getNumTickets();
    std::string getDescription();

    void setTitle(std::string& title);
    void setPrice(float price);
    void setNumTickets(unsigned int numTickets);
    void setDescription(std::string& description);

    std::string toString();
    void print();
};



#endif //PROGRAMIRANJE2_EVENT_H
