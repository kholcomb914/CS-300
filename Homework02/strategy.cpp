//
//  strategy.cpp
//  Project2
//
//  Created by Kaustubh on 10/14/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "event.hpp"
#include "concert.hpp"
#include "conference.hpp"

class LocationStrategy {
public:
    void search(std::vector<Event*> eventList, std::string location) {
        for(Event* event : eventList) {
            if(event->getLocation().find(location) != std::string::npos) {
                event->getDetails();
                std::cout << std::endl;
            }
        }
    }
};

class DateStrategy {
public:
    void search(std::vector<Event*> eventList, std::vector<int> startDate, std::vector<int> endDate) {
        for(Event* event : eventList) {
            bool withinRange = false;
            if(startDate[2] != endDate[2]) {
                if(startDate[2] < event->getEventDate()[2] && endDate[2] > event->getEventDate()[2]) {
                    withinRange = true;
                } else if(startDate[2] == event->getEventDate()[2]) {
                    if(startDate[1] < event->getEventDate()[1]) {
                        withinRange = true;
                    } else if(startDate[1] == event->getEventDate()[1]) {
                        if(startDate[0] < event->getEventDate()[0]) {
                            withinRange = true;
                        }
                    }
                } else if(endDate[2] == event->getEventDate()[2]) {
                    if(endDate[1] > event->getEventDate()[1]) {
                        withinRange = true;
                    } else if(endDate[1] == event->getEventDate()[1]) {
                        if(endDate[0] > event->getEventDate()[0]) {
                            withinRange = true;
                        }
                    }
                }
            } else {
                if(startDate[1] != endDate[1]) {
                    if(startDate[1] < event->getEventDate()[1] && endDate[1] > event->getEventDate()[1]) {
                        withinRange = true;
                    } else if(startDate[1] == event->getEventDate()[1]) {
                        if(startDate[0] <= event->getEventDate()[0]) {
                            withinRange = true;
                        }
                    } else if(endDate[1] == event->getEventDate()[1]) {
                        if(endDate[0] >= event->getEventDate()[0]) {
                            withinRange = true;
                        }
                    }
                } else {
                    if(startDate[0] != endDate[0]) {
                        if(event->getEventDate()[0] <= endDate[0] && event->getEventDate()[0] >= startDate[0]) {
                            withinRange = true;
                        }
                    } else {
                        if(startDate[0] == event->getEventDate()[0]) {
                            withinRange = true;
                        }
                    }
                }
            }
            if(withinRange) {
                event->getDetails();
                std::cout << std::endl;
            }
        }
    }
};
