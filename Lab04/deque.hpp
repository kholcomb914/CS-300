//
//  deque.hpp
//  Lab04
//
//  Created by Kaustubh on 9/25/24.
//

#ifndef deque_hpp
#define deque_hpp

#include <stdio.h>

class Deque {

private:
    struct Node {
        int val;
        Node *nextNode;
        Node *prevNode;
        Node(int cVal, Node *cPrevNode, Node *cNextNode);
    };
    Node *topOfDeque;
    Node *botOfDeque;

public:
    Deque();
    Node *getTopOfDeque();
    Node *getBotOfDeque();
    void setTopOfDeque(Node *n);
    void setBotOfDeque(Node *n);
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int peak_front();
    int peak_back();
    void remove_all();
    ~Deque();
};

#endif /* deque_hpp */
