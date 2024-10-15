//
//  event.cpp
//  Project2
//
//  Created by Kaustubh on 10/1/24.
//

#include "event.hpp"
#include <iostream>
#include <format>
#include <chrono>

Event::Event() {
    eventName = "Rammstein in Amerika";
    eventDate.push_back(12);
    eventDate.push_back(11);
    eventDate.push_back(2010);
    location = "Madison Square Garden";
}

Event::Event(std::string cEventName, std::vector<int> cEventDate, std::string cLocation) {
    eventName = cEventName;
    eventDate = cEventDate;
    location = cLocation;
}

void Event::setEventName(std::string cEventName) {
    eventName = cEventName;
}
void Event::setEventDate(std::vector<int> cEventDate) {
    eventDate = cEventDate;
}
void Event::setLocation(std::string cLocation) {
    location = cLocation;
}
std::string Event::getEventName() {
    return eventName;
}
std::vector<int> Event::getEventDate() {
    return eventDate;
}
std::string Event::getLocation() {
    return location;
}

int Event::currentYear() {
    /*
     The following code was originally written, but std::format is something new to C++20--and while the compiler on Xcode did just fine with it, the command line compiler didn't like it, so I'm just simplifying the function to return 2024, which is the current year.
     const auto now = std::chrono::system_clock::now();
     std::string year = std::format("{:%Y}", now);
     return std::stoi(year)
    */
    return 2024;
}

bool Event::isUpcoming() {
    return (eventDate[2] - currentYear() == 0 || eventDate[2] - currentYear() == 1);
}

void Event::getDetails() {
    std::cout << "Event: " << eventName;
    std::cout << " (" << eventDate[0] << "-" << eventDate[1] << "-" << eventDate[2] << ")" << std::endl;
    std::cout << "Location: " << location << std::endl;
}
