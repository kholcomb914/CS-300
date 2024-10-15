//
//  concert.cpp
//  Project2
//
//  Created by Kaustubh on 10/12/24.
//

#include "concert.hpp"
#include <iostream>

Concert::Concert() : Event(){
    bandName = "Rammstein";
    genre = "Neue Deutsche Harte";
}
Concert::Concert(std::string cEventName, std::vector<int> cEventDate, std::string cLocation, std::string cBandName, std::string cGenre) {
    eventName = cEventName;
    eventDate = cEventDate;
    location = cLocation;
    bandName = cBandName;
    genre = cGenre;
}
std::string Concert::getBandName() {
    return bandName;
}
std::string Concert::getGenre() {
    return genre;
}
void Concert::setBandName(std::string cBandName) {
    bandName = cBandName;
}
void Concert::setGenre(std::string cGenre) {
    genre = cGenre;
}
void Concert::getDetails() {
    std::cout << "Concert: " << eventName;
    std::cout << " (" << eventDate[0] << "-" << eventDate[1] << "-" << eventDate[2] << ")" << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Band Name: " << bandName << "(" << genre << ")" << std::endl;
}
