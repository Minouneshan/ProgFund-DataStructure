/*
 * File:   bintree.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>
#include <string>

class BinTree {

public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    void clear();
    bool addNode(int,const string*);
    bool removeNode(int);
    bool getNode(Data*,int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    DataNode *root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*,DataNode**);
    DataNode* minValueNode(DataNode*);
    DataNode* removeNode(int,DataNode*);
    bool getNode(Data*,int,DataNode*);
    bool contains(int,DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);


};

#endif /* BINTREE_BINTREE_H */

