/*
 * File:   graph.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "data.h"
#include <iostream>

class Graph{

public:
    Graph();
    ~Graph();

private:
    Node *head;
    bool addNode(int,int);
    bool removeNode(int);
    bool getNode(int);


};


#endif /* GRAPH_GRAPH_H */

using namespace std;

bool push(Data*);
bool peek(Data*);
bool pop(Data*);
bool isEmpty();

private:
    vevtor<LinkedList*> adjList;
    int Node;
    int edge;



return 0;
}