/*
 * File:   linkedlist.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */


#include "linkedlist.h"


LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

Node *LinkedList::goWhile(int i,Node *current) {
    current = head;
    while ((current->data.id < i) and (current->next != NULL)) {
        current = current->next;
    }
    return current;
}

Node *LinkedList::addData(int i, string *info, Node *input) {
    input = new Node;
    input->data.id = i;
    input->data.data = *info;
    return input;
}

bool LinkedList::addHeader(int i, string *info,Node *input) {
    input = addData(i,info,input);
    if (head != NULL){
        head->prev = input;
        input->next = head;
        input->prev = NULL;
    }
    head = input;
    return true;
}

bool LinkedList::addTail(int i, string *info, Node *current, Node *input) {
    input = addData(i,info,input);
    input->next = NULL;
    input->prev = current;
    current->next = input;
    return true;
}
bool LinkedList::addMiddle(int i, string *info, Node *current, Node *input) {
    input = addData(i,info,input);
    input->next = current;
    input->prev = current->prev;
    current->prev->next = input;
    current->prev = input;
    return true;
}

bool LinkedList::addNode(int i, string* info) {
    bool added = false;
    if ((i > 0) and (*info != "")) {
        Node *current,*input;
        if (head != NULL) {
            current = goWhile(i,current);
            if (head->data.id > i){ /// add header
                added = addHeader(i,info,input);
                std::cout << "header added x" ;
            }
            else if ((current->next == NULL) and (current->data.id != i)){ /// add tail
                added = addTail(i,info,current,input);
                std::cout << "tail added" ;
            }
            else if (i != (current->data.id)){ /// add middle
                added = addMiddle(i,info,current,input);
                std::cout << "middle added" ;

            }
        }
        else{ /// add header when head == NULL
            added = addHeader(i,info,input);
            std::cout << "header added y" ;
        }
    }
    return added;
}

bool LinkedList::deleteHeader(Node *current) {
    current->next->prev = NULL;
    head = current->next;
    delete current;
    return true;
}

bool LinkedList::deleteTail(Node *current) {
    current->prev->next = NULL;
    delete current;
    return true;
}

bool LinkedList::deleteMiddle(Node *current) {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
}

bool LinkedList::deleteNode(int i) {
    bool deleted = false;
    if (i > 0) {
        if (head != NULL) {
            Node *current;
            current = goWhile(i,current);
            if ((current->prev == NULL) and (current->next == NULL) and (current->data.id == i)){
                delete head;
                head = NULL;
                deleted = true;
                std::cout << "one member deleted" << "\n";
            }
            else if ((current->prev == NULL) and (current->data.id == i)){ /// delete header Node
                deleted = deleteHeader(current);
                std::cout << "header deleted" << "\n\n";
            }
            else if ((current->next == NULL) and (current->data.id == i)){ /// delete Tail Node
                deleted = deleteTail(current);
                std::cout << "Tail deleted" << "\n\n";
            }
            else if (current->data.id == i){ /// delete Middle Node
                deleted = deleteMiddle(current);
                std::cout << "Middle deleted" << "\n\n";
            }
        }
    }
    return deleted;
}

bool LinkedList::getNode(int i, Data* d){

    bool found = false;
    if (i > 0) {
        if (head != NULL) {
            Node *current;
            current = goWhile(i,current);
            if (current->data.id == i){
                d->id = current->data.id;
                d->data = current->data.data;
                found = true;
            }
        }
    }
    if (!found){
        d->id = -1;
        d->data = "";
    }
    return found;
}

void LinkedList::printList() {
    if (head != NULL) {
        Node *current;
        current = head;
        while (current != NULL) {
            std::cout << current->data.id;
            if(current->next) {std::cout << " --> ";}
            current = current->next;}
        }
    else{
        std::cout << "EMPTY" ;
    }
}

int LinkedList::getCount() {
    int num = 0;
    if (head != NULL) {
        Node *current;
        current = head;
        while (current){
            num += 1;
            current = current->next;
        }
    }
    return num;
}

bool LinkedList::clearList() {
    Node *current;
    current = head;
    while (current){
        current = current->next;
        std::cout<< "removed " << head->data.id << "\n";
        delete head;
        head = current;
    }
    head = NULL;
    return true;
}

bool LinkedList::exists(int i) {
    bool existed = false;
    if (head != NULL) {
        Node *current;
        current = goWhile(i,current);
        if (current->data.id == i){
            existed = true;
        }
    }
    return existed;
}









