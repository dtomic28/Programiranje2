//
// Created by Danijel Tomić on 7. 03. 24.
//
#include "Event.h"
#include <iostream>

using namespace std;

string titles[] = {"Pustovanje", "Lampioncki", "Luka Doncic kosarka", "Maribor VS Ljubljana", "Martinovanje"};
string descriptions[] = {"Desc 1", "Desc 2", "Desc 3", "Desc 4", "Desc5"};
const float prices[] = {4.00f, 10.00f, 149.99f, 50.00f, 5.00f};
const unsigned int numOfTickets[] = {500, 1000, 5000, 10000, 300};

void Free(Event *array[]) {
    for (int i = 0; i < 7; i++)
        delete array[i];
}

int main() {
    Event *events[7];
    string title;

    for (int i = 0; i < 5; i++) {
        events[i] = new Event(titles[i], prices[i], numOfTickets[i], descriptions[i]);
        events[i]->print();
    }

    events[5] = new Event();
    events[5]->print();

    events[6] = new Event(*events[0]);
    events[6]->print();

    cout << endl;

    title = "Prvi event";
    events[0]->setTitle(title);
    cout << events[0]->getTitle() << endl;

    events[1]->setNumTickets(12345);
    cout << events[1]->getNumTickets() << endl;

    events[2]->setPrice(0.99f);
    cout << events[2]->getPrice() << endl;

    cout << events[3]->toString() << endl;

    string desc = "Desc xy";
    events[4]->setDescription(desc);
    cout << events[4]->getDescription() << endl;

    Free(events);

    return 0;
}