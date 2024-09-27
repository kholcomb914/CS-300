//
//  deque.cpp
//  Lab04
//
//  Created by Kaustubh on 9/25/24.
//

#include "deque.hpp"
#include <iostream>

Deque::Node::Node(int cVal, Node *cPrevNode, Node *cNextNode) {
    val = cVal;
    prevNode = cPrevNode;
    nextNode = cNextNode;
}
Deque::Deque() {
    topOfDeque = nullptr;
    botOfDeque = nullptr;
}

Deque::Node *Deque::getTopOfDeque() {
    return topOfDeque;
}
Deque::Node *Deque::getBotOfDeque() {
    return botOfDeque;
}
void Deque::setTopOfDeque(Node *n) {
    topOfDeque = n;
}
void Deque::setBotOfDeque(Node *n) {
    botOfDeque = n;
}

void Deque::push_back(int i) {
    Node *newNode = new Node(i, botOfDeque, topOfDeque);
    setBotOfDeque(newNode);
}
void Deque::push_front(int i) {
    Node *newNode = new Node(i, botOfDeque, topOfDeque);
    setTopOfDeque(newNode);
}

int Deque::pop_back() {
    if(topOfDeque != nullptr && botOfDeque != nullptr) {
        int val = botOfDeque -> val;
        Node *ptrNewBot = botOfDeque -> prevNode;
        delete botOfDeque;
        setBotOfDeque(ptrNewBot);
        return val;
    }
    std::cout << "Deque is empty--operation pop_back cannot be executed." << std::endl;
    return 0;
}
int Deque::pop_front() {
    if(topOfDeque != nullptr && botOfDeque != nullptr) {
        int val = topOfDeque -> val;
        Node *ptrNewTop = topOfDeque -> nextNode;
        delete topOfDeque;
        setTopOfDeque(ptrNewTop);
        return val;
    }
    std::cout << "Deque is empty--operation pop_front cannot be executed." << std::endl;
    return 0;
}

int Deque::peak_back() {
    if(topOfDeque != nullptr && botOfDeque != nullptr) {
        int val = botOfDeque -> val;
        return val;
    }
    std::cout << "Deque is empty--operation peak_back cannot be executed." << std::endl;
    return 0;
}
int Deque::peak_front() {
    if(topOfDeque != nullptr && botOfDeque != nullptr) {
        int val = topOfDeque -> val;
        return val;
    }
    std::cout << "Deque is empty--operation peak_front cannot be executed." << std::endl;
    return 0;
}

void Deque::remove_all() {
    while(getTopOfDeque() != nullptr) {
        Node *ptrNewTop = topOfDeque -> nextNode;
        delete topOfDeque;
        setTopOfDeque(ptrNewTop);
    }
}

Deque::~Deque() {
    remove_all();
}
