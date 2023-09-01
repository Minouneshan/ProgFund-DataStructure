/*********************
/*
 * File:   fifo.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "fifo.h"
// constructor
Stack::Stack(){
    head = NULL;
}
// destructor
Stack::~Stack(){
    clearList();
    top = -1;
    }
// function to insert data into stack
bool Stack::push(int i){
    bool pushed = false;

    if (top < STACKSIZE - 1) {
        top++;
        pushed = addNode(i);
    }

    return pushed;
}

bool Stack::addNode(int i) {
    bool added = false;
    if (i > 0) {
        Node *input;
        if (head == NULL) {
            input = new Node;
            input->data = i;
            head = input;
            added = true;
        }
        else{
            Node *current;
            current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            input = new Node;
            input->data = i;
            input->next = NULL;
            input->prev = current;
            current->next = input;
            added = true;
        }
    }
    return added;
}

int Stack::deleteHeader() {
    int deleted;
    Node *current;
    current = head;
    deleted = current->data;
    if (current->next != NULL){
        current->next->prev = NULL;
        head = current->next;
        delete current;
    }
    else{
        delete head;
        head = NULL;
    }

    return deleted;
}

// function to remove data from the top of the stack
int Stack::pull()
{
    if (top < 0) {
        // throw an int because we cannot return one
        throw -1;
    } // there is no 'else' because throw causes an immediate halt to execution
    int i;
    i = deleteHeader();
    top--;
    return i;
}


// function to return the last  imported data from the top of Stack
bool Stack::peek(int *ret) {

    bool pulled = false;
    if (top > -1) {
        *ret = head->data;
        pulled = true;
    }
    return pulled;
}
// function to check if stack is empty
bool Stack::isEmpty() {
    return (top < 0);
}

// this is a programmer debug routine
// DO NOT LEAVE THIS IN PRODUCTION CODE
bool Stack::clearList() {
    Node *current;
    current = head;
    while (current){
        current = current->next;
        delete head;
        head = current;
    }
    head = NULL;
    top = -1;
    return true;
}