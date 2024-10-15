//
//  factory.cpp
//  Project2
//
//  Created by Kaustubh on 10/13/24.
//

#include <stdio.h>
#include "event.hpp"
#include "concert.hpp"
#include "conference.hpp"

class EventFactory {
public:
    enum class EventType{
        Concert,
        Conference,
    };
    Event* createEventFactory(EventType type) {
        Event* newEvent = nullptr;
        if(type == EventType::Concert) newEvent = new Concert();
        else if(type == EventType::Conference) newEvent = new Conference();
        return newEvent;
    }
    Event* createEvent() {
        return new Event();
    }
    Concert* createConcert() {
        return new Concert();
    }
    Conference* createConference() {
        return new Conference();
    }
};
