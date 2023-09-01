/*
 * File:   hash.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */


#include "hash.h"

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        table[i] = NULL;
    }
}

Hashtable::~Hashtable() {
    clearTable();
}


int Hashtable::hash(int id) {
    // guarantees a position between 0 and HASHTABLESIZE - 1
    return id % HASHTABLESIZE;
}

bool Hashtable::insertEntry(int id,string* info){
    bool inserted = false;
    int position = hash(id);

    if(addHeader(table[position],id,info)){
        std::cout << id << " position: " << position << "\n\n";
        inserted = true;
        count++;
    }
    return inserted;
}

bool Hashtable::addHeader(Node *head, int i, string *info) {
    bool added = false;
    if (i > 0) {
        Node *input;
        if (head == NULL) {
            input = new Node;
            input->data.id = i;
            input->data.data = *info;
            added = true;
        }
        else{
            Node *current;
            current = head;
            input = new Node;
            input->data.id = i;
            input->data.data = *info;
            input->next = current;
            added = true;
        }
    }
    return added;
}


string Hashtable::getEntry(int id){
    string ret = "";
    int position = hash(id);
    if(table[position]){
        while(table[position]->next != NULL and table[position]->data.id != id){
            table[position] = table[position]->next;
        }
        if(table[position]->data.id == id){
            ret = table[position]->data.data;
        }
    }
    return ret;
}

bool Hashtable::removeEntry(int id){
    bool del = false;
    int position = hash(id);
    if (deleteNode(table[position], id)){
        del = true;
        count--;
    }
    return del;
}

int Hashtable::getCount(){
    return count;
};

void Hashtable::printTable(){
    for (int i=0;i<HASHTABLESIZE;i++){
        std::cout << "Entry " << i+1 << " : ";
        Node *current;
        current = table[i];
        while (current){
            std::cout << "id: " << current->data.id << " and data: " << current->data.data << " ,";
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Hashtable::clearTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        Node *current;
        current = table[i];
        while (current){
            current = current->next;
            std::cout<< "removed " << table[i]->data.id << "\n";
            delete table[i];
            table[i] = current;
        }
    }
    return true;
}

bool Hashtable::deleteNode(Node *head, int i) {
    bool deleted = false;
    if (i > 0) {
        if (head != NULL) {
            Node *current;
            while (head->next != NULL and head->data.id != i) {
                current = head;
                head = head->next;
                if (head->data.id == i) {
                    if (head->next != NULL) {
                        current->next = head->next;
                    } else {
                        current->next = NULL;
                    }
                    delete head;
                    deleted = true;
                }
            }
        }
    }
    return deleted;
}














