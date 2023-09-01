/*
 * File:   linkedlist.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList {

public:

    LinkedList();
    ~LinkedList();

    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    Node *head;
    Node *goWhile(int, Node*);
    Node *addData(int, string*,Node*);
    bool addHeader(int, string*,Node*);
    bool addTail(int, string*, Node*,Node*);
    bool addMiddle(int, string*,Node*,Node*);
    bool deleteHeader(Node*);
    bool deleteMiddle(Node*);
    bool deleteTail(Node*);

};

#endif //LINKEDLIST_H