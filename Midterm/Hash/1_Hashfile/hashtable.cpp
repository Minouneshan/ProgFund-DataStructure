/*
 * File:   hashtable.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#include "hashtable.h"

/************************************
 * Constructor / Destructor
 ************************************/

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        table[i] = new LinkedList;
    }
}

Hashtable::~Hashtable() {
}


/************************************
 * Private
 ************************************/

int Hashtable::hash(int id) {
    // guarantees a position between 0 and HASHTABLESIZE - 1
    return id % HASHTABLESIZE;
}


/************************************
 * Public
 ************************************/
bool Hashtable::insertEntry(int id,string* info){
    bool inserted = false;
    int position = hash(id);

    if(table[position]->addNode(id,info)){
        std::cout << id << " position: " << position << "\n\n";
        inserted = true;
        count++;
    }
    return inserted;
}

string Hashtable::getData(int id){
    string ret = "";
    int position = hash(id);
    Data tmpd;
    if(table[position]){
        if(table[position]->getNode(id,&tmpd)){
            ret = tmpd.data;
        }
    }
    return ret;
}

bool Hashtable::removeEntry(int id){
    bool del = false;
    int position = hash(id);
    if (table[position]->deleteNode(id)){
        del = true;
        count--;
    }
    return del;
}

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for (int i=0;i<HASHTABLESIZE;i++){
        std::cout << "Entry " << i+1 << " : ";
        table[i]->printList();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Hashtable::clearTable() {
    for (int i=0;i<HASHTABLESIZE;i++){
        table[i]->clearList();
    }
    count = 0 ;
    return true;
}