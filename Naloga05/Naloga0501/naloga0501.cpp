//
// Created by danijel on 4/1/2024.
//
#include <iostream>
#include "EventOrganizer.h"

#define LocationSize 10

using namespace std;

void initLocations(Location* arr)
{
    arr[0].setCity("Maribor");
    arr[0].setCountry("Slovenia");
    arr[0].setName("Maribor Slovenia");
    arr[0].setStreet("Tyrseva ulica");

    arr[1].setCity("New York City");
    arr[1].setCountry("USA");
    arr[1].setName("New York City USA");
    arr[1].setStreet("Fifth Avenue");

    arr[2].setCity("Tokyo");
    arr[2].setCountry("Japan");
    arr[2].setName("Tokyo Japan");
    arr[2].setStreet("Ginza");

    arr[3].setCity("Rome");
    arr[3].setCountry("Italy");
    arr[3].setName("Rome Italy");
    arr[3].setStreet("Via del Corso");

    arr[4].setCity("Barcelona");
    arr[4].setCountry("Spain");
    arr[4].setName("Barcelona Spain");
    arr[4].setStreet("La Rambla");

    arr[5].setCity("Dubai");
    arr[5].setCountry("UAE");
    arr[5].setName("Dubai UAE");
    arr[5].setStreet("Sheikh Zayed Road");

    arr[6].setCity("London");
    arr[6].setCountry("UK");
    arr[6].setName("London UK");
    arr[6].setStreet("Oxford Street");

    arr[7].setCity("Sydney");
    arr[7].setCountry("Australia");
    arr[7].setName("Sydney Australia");
    arr[7].setStreet("George Street");

    arr[8].setCity("Hong Kong");
    arr[8].setCountry("China");
    arr[8].setName("Hong Kong China");
    arr[8].setStreet("Nathan Road");

    arr[9].setCity("Rio de Janeiro");
    arr[9].setCountry("Brazil");
    arr[9].setName("Rio de Janeiro Brazil");
    arr[9].setStreet("Copacabana Beach");
}

void initEvents(Event* events, Location* locations)
{
    string str;
    events[0].setDate(Date::parse("28.10.2023"));
    events[0].setLocation(&locations[0]);
    events[0].setNumTickets(90);
    events[0].setPrice(15.0f);
    str = "Pre halloween party";
    events[0].setTitle(str);
    events[0].setAgeGroup(EventAgeGroup::Adult);

    events[1].setDate(Date::parse("15.05.2024"));
    events[1].setLocation(&locations[2]);
    events[1].setNumTickets(120);
    events[1].setPrice(20.5f);
    str = "Spring Music Festival";
    events[1].setTitle(str);
}

void initConcerts(Concert* Concerts, Location* locations)
{
    string str;
    Concerts[0].setDate(Date::parse("28.10.2023"));
    Concerts[0].setLocation(&locations[0]);
    Concerts[0].setNumTickets(90);
    Concerts[0].setPrice(15.0f);
    str = "Mambo kings concert";
    Concerts[0].setTitle(str);
    Concerts[0].setAgeGroup(EventAgeGroup::Adult);
    Concerts[0].setConcertType(ConcertType::Rock);
    Concerts[0].setPerformer("Mambo kings");

    Concerts[1].setDate(Date::parse("15.05.2024"));
    Concerts[1].setLocation(&locations[2]);
    Concerts[1].setNumTickets(120);
    Concerts[1].setPrice(20.5f);
    str = "Spring Music Festival concert";
    Concerts[1].setTitle(str);
    Concerts[1].setPerformer("Martin Garrix");
    Concerts[1].setConcertType(ConcertType::Pop);
}

int main()
{
    auto locationPtrArr = new Location[LocationSize];
    initLocations(locationPtrArr);
    Event events[2];
    Concert concerts[2];
    initEvents(events, locationPtrArr);
    initConcerts(concerts, locationPtrArr);

    EventOrganizer eventOrganizer("Event organizers Maribor", "www.spletna-stran.si");
    eventOrganizer.addEvent(&events[0]);
    eventOrganizer.addEvent(&events[1]);
    eventOrganizer.addEvent(&concerts[0]);
    eventOrganizer.addEvent(&concerts[1]);

    cout << eventOrganizer.toString() << endl;

    delete[] locationPtrArr;
}