/*
 * File:   stack.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 * Definition of class Stack in this file. there m=stack methods such as
 * push, peek, pop and isempty.
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly!
#include "stack.h"
#include <iostream>
/*
 * write all your stack methods here
 */

Stack::Stack(){

    this->top = -1;
}

Stack::~Stack() {
    while (top > -1) {
        delete stack[top--];
    }
}
// only an int and string pointer to the stack. if push was succesful return true,
// otherwise false.
bool Stack::push(int i, const string* info){
    bool pushed = false;

    if (top < STACK_SIZE - 1 ){
        if (i>0 & *info != ""){
            Data *data = new Data;
            data->id = i;
            data->information = *info;
            stack[++top] = data;
            pushed = true;
        }
    }
    return pushed;
}
// we pass an empty struct Data to the stack.
bool Stack::pop(Data *d){
    bool popped = false;
    if (top < 0){
        d->id = -1;
        d->information = "";
    }
    else{
        d->id = stack[top]->id;
        d->information = stack[top]->information;
        delete stack[top--];
        popped = true;
    }
    return  popped;
}
// similar to pop except not deallocate nor decrement.
bool Stack::peek(Data *d) {
    bool peeked = false;
    if (top < 0){
        d->id = -1;
        d->information = "";
    }
    else{
        d->id = stack[top]->id;
        d->information = stack[top]->information;
        peeked = true;
    }
    return  peeked;
}

bool Stack::isEmpty() {
    return (top < 0);
}

// this is a programmer debug routine
// DO NOT LEAVE THIS IN PRODUCTION CODE
void Stack::dumpStack() {
    std::cout << "dumping whole stack..." << std::endl;
    if (!isEmpty()) {
        for (int i = top; i >= 0; i--) {
            std::cout << stack[i]->id << " with " << stack[i]->information << std::endl;
        }
    } else {
        std::cout << "\tstack is empty" << std::endl;
    }
    std::cout << std::endl;
}