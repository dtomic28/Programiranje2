//
// Created by Danijel Tomić on 7. 03. 24.
//
#include "Event.h"
#include <iostream>

using namespace std;

const string titles[] = {"Pustovanje", "Lampioncki", "Luka Doncic kosarka", "Maribor VS Ljubljana", "Martinovanje"};
const float prices[] = {4.00f, 10.00f, 149.99f, 50.00f, 5.00f};
const unsigned int numOfTickets[] = {500, 1000, 5000, 10000, 300};

void Free(Event* array[]){
    for(int i = 0; i<5; i++)
        delete array[i];
}

int main(){
    Event* events[5];
    string title;

    for(int i = 0; i<5; i++){
        events[i] = new Event(titles[i], prices[i], numOfTickets[i]);
        events[i]->print();
    }

    cout << endl;

    title = "Prvi event";
    events[0]->setTitle(title);
    cout << events[0]->getTitle() << endl;

    events[1]->setNumTickets(12345);
    cout << events[1]->getNumTickets() << endl;

    events[2]->setPrice(0.99f);
    cout << events[2]->getPrice() << endl;

    cout << events[3]->toString() << endl;

    Free(events);

    return 0;
}