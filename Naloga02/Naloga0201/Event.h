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
public:
    Event(const std::string& title, float price, unsigned int numTickets);

    std::string getTitle();
    float getPrice();
    unsigned int getNumTickets();

    void setTitle(std::string& title);
    void setPrice(float price);
    void setNumTickets(unsigned int numTickets);

    std::string toString();
    void print();
};


#endif //PROGRAMIRANJE2_EVENT_H
