/*
 * File:   stack.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 * We have class Stack which is responsible for primitive
 * functions for the Data Structure defined in data.h.
 *
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    Stack();
    ~Stack();

    bool push(int, const string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    void dumpStack();

private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H