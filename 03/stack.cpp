/*********************
/*
 * File:   stack.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "stack.h"
// constructor
Stack::Stack(){
    top = -1;
}
// destructor
Stack::~Stack(){

    }
}
// function to insert data into stack
bool Stack::push(int x)
{
    if (top >= (SIZE-1)){
        throw 0;
    }
    a[++top] = x;
    return 1;
}
// function to remove data from the top of the stack
int Stack::pop()
{
    if(isEmpty()) {
        throw 0;
    }
    return a[top--];
}
// function to return the last  imported data from the top of Stack
int Stack::peak(){
    if(isEmpty()) {
        throw 0;
    }
    return a[top];
}
// function to check if stack is empty
bool Stack::isEmpty() {
    return top < 0;
}