//
//  concert.hpp
//  Project2
//
//  Created by Kaustubh on 10/12/24.
//

#ifndef concert_hpp
#define concert_hpp

#include "event.hpp"
#include <stdio.h>

class Concert : public Event {
private:
    std::string eventName;
    std::vector<int> eventDate;
    std::string location;
    std::string bandName;
    std::string genre;
public:
    Concert();
    Concert(std::string cEventName, std::vector<int> cEventDate, std::string cLocation, std::string cBandName, std::string cGenre);
    std::string getBandName();
    std::string getGenre();
    void setBandName(std::string cBandName);
    void setGenre(std::string cGenre);
    void getDetails();
};

#endif /* concert_hpp */
