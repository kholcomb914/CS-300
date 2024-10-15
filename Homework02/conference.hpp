//
//  conference.hpp
//  Project2
//
//  Created by Kaustubh on 10/12/24.
//

#ifndef conference_hpp
#define conference_hpp

#include "event.hpp"
#include <stdio.h>

class Conference : public Event {
private:
    std::string eventName;
    std::vector<int> eventDate;
    std::string location;
    std::vector<std::string> speakers;
    std::vector<std::string> topics;
public:
    Conference();
    Conference(std::string cEventName, std::vector<int> cEventDate, std::string cLocation, std::vector<std::string> cSpeakers, std::vector<std::string> cTopics);
    std::vector<std::string> getSpeakers();
    std::vector<std::string> getTopics();
    void addSpeaker(std::string newSpeaker);
    void addTopic(std::string newTopic);
    void removeSpeaker(std::string newSpeaker);
    void removeTopic(std::string newTopic);
    void getDetails();
};


#endif /* conference_hpp */
