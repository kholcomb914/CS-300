//
//  main.cpp
//  Project2
//
//  Created by Kaustubh on 10/1/24.
//

#include <iostream>
#include <string>
#include "factory.cpp"
#include "strategy.cpp"

void mainMenu(bool exit);

int main(int argc, const char * argv[]) {
    
    LocationStrategy lStrat;
    DateStrategy dStrat;
    EventFactory factory;
    Concert* concert1 = factory.createConcert();
    Conference* conference1 = factory.createConference();
    std::vector<Event*> eventList;
    std::vector<Conference*> conferenceList;
    std::vector<Concert*> concertList;
    
    concertList.push_back(concert1);
    eventList.push_back(concert1);
    concert1->setEventName("The Police Reunion Tour");
    std::vector<int> c1d;
    c1d.push_back(7);
    c1d.push_back(4);
    c1d.push_back(2007);
    concert1->setEventDate(c1d);
    concert1->setLocation("New York, NY");
    concert1->setBandName("The Police");
    concert1->setGenre("Pop");
    
    conferenceList.push_back(conference1);
    eventList.push_back(conference1);
    conference1->setEventName("United Nations General Assembly");
    std::vector<int> o1d;
    o1d.push_back(9);
    o1d.push_back(23);
    o1d.push_back(2024);
    conference1->setEventDate(o1d);
    conference1->setLocation("New York, NY");
    conference1->addSpeaker("Joe Biden");
    conference1->addSpeaker("Keir Starmer");
    conference1->addTopic("Global Affairs");
    
    bool exit = false;
    while(!exit) {
        
        std::cout << "MAIN MENU - SELECT AN OPTION:" << std::endl;
        std::cout << "Create New Event (c)" << std::endl;
        std::cout << "Search for Event (s)" << std::endl;
        std::cout << "Display Event Type Details (d)" << std::endl;
        std::cout << "List All Upcoming Events (l)" << std::endl;
        std::cout << "Exit (e)" << std::endl;
        std::cout << "Enter command (lowercase letter): ";
        char command;
        std::cin >> command;
        std::cout << std::endl;
        
        switch(command) {
                
            case 'c': {
                std::cout << "CREATE EVENT" << std::endl;
                std::cout << "Specify type of event to be created:" << std::endl;
                std::cout << "Concert (c)" << std::endl;
                std::cout << "Conference (o)" << std::endl;
                std::cout << "Generic Event (e)" << std::endl;
                std::cout << "Enter event type (lowercase letter): ";
                char eventType;
                std::cin >> eventType;
                
                switch(eventType) {
                        
                    case 'c': {
                        Concert* concert2 = factory.createConcert();
                        concertList.push_back(concert2);
                        eventList.push_back(concert2);
                        
                        std::cout << "Event name:" << std::endl;
                        std::cin.ignore();
                        std::string c2name;
                        std::getline(std::cin, c2name);
                        concert2->setEventName(c2name);
                        
                        std::cout << "Event month (enter integer value):" << std::endl;
                        int c2month;
                        std::cin >> c2month;
                        std::cout << "Event day (enter integer value):" << std::endl;
                        int c2day;
                        std::cin >> c2day;
                        std::cout << "Event year (enter integer value):" << std::endl;
                        int c2year;
                        std::cin >> c2year;
                        std::vector<int> c2date;
                        c2date.push_back(c2month);
                        c2date.push_back(c2day);
                        c2date.push_back(c2year);
                        concert2->setEventDate(c2date);

                        std::cout << "Event location: " << std::endl;
                        std::cin.ignore();
                        std::string c2location;
                        std::getline(std::cin, c2location);
                        concert2->setLocation(c2location);
                        
                        std::cout << "Artist/band name: " << std::endl;
                        std::cin.ignore();
                        std::string c2band;
                        std::getline(std::cin, c2band);
                        concert2->setBandName(c2band);
                        
                        std::cout << "Genre: " << std::endl;
                        std::cin.ignore();
                        std::string c2genre;
                        std::getline(std::cin, c2genre);
                        concert2->setGenre(c2genre);
                        std::cout << std::endl;
                        break;
                    }
                        
                    case 'o': {
                        Conference* conference2 = factory.createConference();
                        conferenceList.push_back(conference2);
                        eventList.push_back(conference2);
                        
                        std::cout << "Event name:" << std::endl;
                        std::cin.ignore();
                        std::string o2name;
                        std::getline(std::cin, o2name);
                        conference2->setEventName(o2name);
                        
                        std::cout << "Event month (enter integer value):" << std::endl;
                        int o2month;
                        std::cin >> o2month;
                        std::cout << "Event day (enter integer value):" << std::endl;
                        int o2day;
                        std::cin >> o2day;
                        std::cout << "Event year (enter integer value):" << std::endl;
                        int o2year;
                        std::cin >> o2year;
                        std::vector<int> o2date;
                        o2date.push_back(o2month);
                        o2date.push_back(o2day);
                        o2date.push_back(o2year);
                        conference2->setEventDate(o2date);

                        std::cout << "Event location: " << std::endl;
                        std::cin.ignore();
                        std::string o2location;
                        std::getline(std::cin, o2location);
                        conference2->setLocation(o2location);
                        
                        std::cout << "Primary speaker: " << std::endl;
                        std::cin.ignore();
                        std::string o2speaker;
                        std::getline(std::cin, o2speaker);
                        conference2->addSpeaker(o2speaker);
                        
                        std::cout << "Topic: " << std::endl;
                        std::cin.ignore();
                        std::string o2topic;
                        std::getline(std::cin, o2topic);
                        conference2->addTopic(o2topic);
                        std::cout << std::endl;
                        break;
                    }
                        
                    case 'e': {
                        Event* event2 = factory.createEvent();
                        eventList.push_back(event2);
                        
                        std::cout << "Event name:" << std::endl;
                        std::cin.ignore();
                        std::string e2name;
                        std::getline(std::cin, e2name);
                        event2->setEventName(e2name);
                        
                        std::cout << "Event month (enter integer value):" << std::endl;
                        int e2month;
                        std::cin >> e2month;
                        std::cout << "Event day (enter integer value):" << std::endl;
                        int e2day;
                        std::cin >> e2day;
                        std::cout << "Event year (enter integer value):" << std::endl;
                        int e2year;
                        std::cin >> e2year;
                        std::vector<int> e2date;
                        e2date.push_back(e2month);
                        e2date.push_back(e2day);
                        e2date.push_back(e2year);
                        event2->setEventDate(e2date);

                        std::cout << "Event location: " << std::endl;
                        std::cin.ignore();
                        std::string e2location;
                        std::getline(std::cin, e2location);
                        event2->setLocation(e2location);
                        std::cout << std::endl;
                        break;
                    }
                        
                    default: {
                        break;
                    }
                }
                break;
            }
                
            case 's': {
                std::cout << "SEARCH FOR EVENTS" << std::endl;
                std::cout << "Specify the search criteria:" << std::endl;
                std::cout << "Search by date (d)" << std::endl;
                std::cout << "Search by location (l)" << std::endl;
                std::cout << "Enter search criteria (lowercase letter): ";
                char searchType;
                std::cin >> searchType;
                
                if(searchType == 'd') {
                    
                    std::cout << "Start date:" << std::endl;
                    std::cout << "Year: ";
                    int sYear;
                    std::cin >> sYear;
                    std::cout << "Month: ";
                    int sMonth;
                    std::cin >> sMonth;
                    std::cout << "Day: ";
                    int sDay;
                    std::cin >> sDay;
                    std::vector<int> startDate;
                    startDate.push_back(sMonth);
                    startDate.push_back(sDay);
                    startDate.push_back(sYear);
                    
                    std::cout << "End date:" << std::endl;
                    std::cout << "Year: ";
                    int eYear;
                    std::cin >> eYear;
                    std::cout << "Month: ";
                    int eMonth;
                    std::cin >> eMonth;
                    std::cout << "Day: ";
                    int eDay;
                    std::cin >> eDay;
                    std::vector<int> endDate;
                    endDate.push_back(eMonth);
                    endDate.push_back(eDay);
                    endDate.push_back(eYear);

                    std::cout << "Events within the given dates:" << std::endl;
                    dStrat.search(eventList, startDate, endDate);
                }
                else if(searchType == 'l') {
                    std::cout << "Enter the location keyword(s) you would like to search for:" << std::endl;
                    std::cin.ignore();
                    std::string lSearch;
                    std::getline(std::cin, lSearch);
                    lStrat.search(eventList, lSearch);
                }
                break;
            }
            
            case 'd': {
                std::cout << "FILTER EVENTS" << std::endl;
                std::cout << "Specify type of event to view entries for:" << std::endl;
                std::cout << "Concert (c)" << std::endl;
                std::cout << "Conference (o)" << std::endl;
                std::cout << "Enter event type (lowercase letter): ";
                char eventType;
                std::cin >> eventType;
                
                if(eventType == 'c') {
                    for(Concert* concert : concertList) {
                        concert->getDetails();
                        std::cout << std::endl;
                    }
                } else if(eventType == 'o') {
                    for(Conference* conference : conferenceList) {
                        conference->getDetails();
                        std::cout << std::endl;
                    }
                }
                break;
            }
            
            case 'l': {
                std::cout << "EVENT LIST" << std::endl;
                for(Event* event : eventList) {
                    event->getDetails();
                    std::cout << std::endl;
                }
                break;
            }
                
            case 'e':
                exit = true;
                std::cout << "Exiting..." << std::endl;
                break;
                
            default:
                break;
        }
    }
    
    return 0;
}
