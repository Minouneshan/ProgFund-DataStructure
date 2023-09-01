/*
 * File:   hash.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef HASH_H
#define HASH_H


#include <iostream>
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
};

class Hashtable {

public:

    Hashtable();
    ~Hashtable();

    bool insertEntry(int,string*);
    string getEntry(int);
    bool removeEntry(int);
    int getCount();
    void printTable();
    bool clearTable();


private:


    int hash(int);
    int count;
    Node *table[HASHTABLESIZE];
    bool addHeader(Node*,int,string*);
    bool deleteNode(Node*, int);

};

#endif //HASH_H