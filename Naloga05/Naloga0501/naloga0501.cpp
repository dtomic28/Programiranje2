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

void initEvents(EventOrganizer& eventOrganizer, Location* locations)
{
    string str;
    auto* event = new Event();
    event->setDate(Date::parse("28.10.2023"));
    event->setLocation(&locations[0]);
    event->setNumTickets(90);
    event->setPrice(15.0f);
    str = "Pre halloween party";
    event->setTitle(str);
    event->setAgeGroup(EventAgeGroup::Adult);
    eventOrganizer.addEvent(event);

    event = new Event();
    event->setDate(Date::parse("15.05.2024"));
    event->setLocation(&locations[2]);
    event->setNumTickets(120);
    event->setPrice(20.5f);
    str = "Spring Music Festival";
    event->setTitle(str);
    eventOrganizer.addEvent(event);
}

void initConcerts(EventOrganizer& eventOrganizer, Location* locations)
{
    string str;
    auto* concert = new Concert();
    concert->setDate(Date::parse("28.10.2023"));
    concert->setLocation(&locations[0]);
    concert->setNumTickets(90);
    concert->setPrice(15.0f);
    str = "Mambo kings concert";
    concert->setTitle(str);
    concert->setAgeGroup(EventAgeGroup::Adult);
    concert->setConcertType(ConcertType::Rock);
    concert->setPerformer("Mambo kings");
    eventOrganizer.addEvent(concert);

    concert = new Concert();
    concert->setDate(Date::parse("15.05.2024"));
    concert->setLocation(&locations[2]);
    concert->setNumTickets(120);
    concert->setPrice(20.5f);
    str = "Spring Music Festival concert";
    concert->setTitle(str);
    concert->setPerformer("Martin Garrix");
    concert->setConcertType(ConcertType::Pop);
    eventOrganizer.addEvent(concert);
}

int main()
{
    auto locationPtrArr = new Location[LocationSize];
    initLocations(locationPtrArr);

    EventOrganizer eventOrganizer("Event organizers Maribor", "www.spletna-stran.si");
    initEvents(eventOrganizer, locationPtrArr);
    initConcerts(eventOrganizer, locationPtrArr);

    cout << eventOrganizer.toString() << endl;

    delete[] locationPtrArr;
}