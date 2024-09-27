//
//  user.cpp
//  Lab04
//
//  Created by Kaustubh on 9/26/24.
//

#include "user.hpp"
#include <iostream>

User::User() {
    userName = "holcombk";
    email = "holcombk@uab.edu";
}

User::User(std::string cUserName, std::string cEmail, std::vector<User*> cFriendList) {
    userName = cUserName;
    email = cEmail;
    friendList = cFriendList;
}

std::string User::getUserName() {
    return userName;
}
std::string User::getEmail() {
    return email;
}
void User::setUserName(std::string cUserName) {
    userName = cUserName;
}
void User::setEmail(std::string cEmail) {
    email = cEmail;
}

void User::addFriend(User* newFriend) {
    friendList.push_back(newFriend);
}

void User::removeFriend(std::string oldFriend) {
    for(int i = 0; i < friendList.size(); i++) {
        std::string checkUserName = friendList[i] -> userName;
        if(oldFriend.compare(checkUserName) == 0) {
            friendList.erase(friendList.begin()+i);
        }
    }
}

int User::numFriends() {
    return friendList.size();
}

User* User::getFriendAt(int index) {
    if(index >= 0 && index < friendList.size()) {
        return friendList[index];
    } else {
        return nullptr;
    }
}
