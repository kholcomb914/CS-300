//
//  event.hpp
//  Project2
//
//  Created by Kaustubh on 10/1/24.
//

#ifndef event_hpp
#define event_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Event {
private:
    std::string eventName;
    std::vector<int> eventDate;
    std::string location;
public:
    Event();
    Event(std::string cEventName, std::vector<int> cEventDate, std::string cLocation);
    int currentYear();
    bool isUpcoming();
    void getDetails();
    void setEventName(std::string cEventName);
    void setEventDate(std::vector<int> cEventDate);
    void setLocation(std::string cLocation);
    std::string getEventName();
    std::vector<int> getEventDate();
    std::string getLocation();
};

#endif /* event_hpp */
