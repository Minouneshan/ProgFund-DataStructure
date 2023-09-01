/*********************
/*
 * File:   stack.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define SIZE 10

class Stack
{
protected:
    int top;
    int a[SIZE];

public:
    Stack();
    ~Stack();
    // declaring all the function
    bool push(int x);
    int pop();
    int peak();
    bool isEmpty();
};


#endif //STACK_STACK_H