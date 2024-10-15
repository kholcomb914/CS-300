//
//  conference.cpp
//  Project2
//
//  Created by Kaustubh on 10/12/24.
//

#include "conference.hpp"
#include <iostream>

Conference::Conference() : Event(){
    speakers.push_back("Splendiferous Finch");
    speakers.push_back("Cartoons Plural");
    topics.push_back("East/West Bowl");
}
Conference::Conference(std::string cEventName, std::vector<int> cEventDate, std::string cLocation, std::vector<std::string> cSpeakers, std::vector<std::string> cTopics) {
    eventName = cEventName;
    eventDate = cEventDate;
    location = cLocation;
    speakers = cSpeakers;
    topics = cTopics;
}
std::vector<std::string> Conference::getSpeakers() {
    return speakers;
}
std::vector<std::string> Conference::getTopics() {
    return topics;
}
void Conference::addSpeaker(std::string newSpeaker) {
    speakers.push_back(newSpeaker);
}
void Conference::addTopic(std::string newTopic) {
    topics.push_back(newTopic);
}
void Conference::removeSpeaker(std::string newSpeaker) {
    for(int i = 0; i < speakers.size(); i++) {
        if(speakers[i].compare(newSpeaker) == 0) {
            speakers.erase(speakers.begin()+i);
        }
    }
}
void Conference::removeTopic(std::string newTopic) {
    for(int i = 0; i < topics.size(); i++) {
        if(topics[i].compare(newTopic) == 0) {
            topics.erase(topics.begin()+i);
        }
    }
}
void Conference::getDetails() {
    std::cout << "Conference: " << eventName;
    std::cout << " (" << eventDate[0] << "-" << eventDate[1] << "-" << eventDate[2] << ")" << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Speakers: " << speakers[0];
    for(int i = 1; i < speakers.size(); i++) {
        std::cout << ", " << speakers[i];
    }
    std::cout << "\nTopics: " << topics[0];
    for(int i = 1; i < topics.size(); i++) {
        std::cout << ", " << topics[i];
    }
    std::cout << std::endl;
}
