/*
 * File:   hashtable.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "string"

#define HASHTABLESIZE 15


using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

class Hashtable {
public:
    Hashtable();
    ~Hashtable();

    bool insertEntry(int,string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();
    bool clearTable();

private:

    int hash(int);
    LinkedList *table[HASHTABLESIZE];
    int count;

};

#endif /* HASHTABLE_H */