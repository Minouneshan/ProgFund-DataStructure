/*********************
/*
 * File:   fifo.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#ifndef FIFO_STACK_H
#define FIFO_STACK_H

#define STACKSIZE 10

#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class Stack
{
public:
    Stack();
    ~Stack();
    // declaring all the function
    bool push(int);
    int pull();
    bool peek(int*);
    bool isEmpty();

    // this is a programmer debug routine
    // DO NOT LEAVE THIS IN PRODUCTION CODE
    bool clearList();

private:

    int top;
    Node *head;
    bool addNode(int);
    int deleteHeader();

};


#endif //FIFO_STACK_H