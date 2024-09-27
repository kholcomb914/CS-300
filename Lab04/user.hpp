//
//  user.hpp
//  Lab04
//
//  Created by Kaustubh on 9/26/24.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>
#include <string>
#include <vector>

class User {
    
private:
    std::string userName;
    std::string email;
    std::vector<User*> friendList;
    
public:
    User();
    User (std::string userName, std::string email, std::vector<User*> friendList);
    void addFriend(User* newFriend);
    void removeFriend(std::string username);
    int numFriends();
    User* getFriendAt(int index);
    std::string getUserName();
    std::string getEmail();
    void setUserName(std::string username);
    void setEmail(std::string email);
};

#endif /* user_hpp */
