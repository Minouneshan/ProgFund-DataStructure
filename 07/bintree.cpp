/*
 * File:   bintree.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#include "bintree.h"

BinTree::BinTree() {
    count = 0;
    root = NULL;
}

BinTree::~BinTree() {
    clear();
}

bool BinTree::isEmpty() {
    return (count == 0);
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data *d) {
    bool get = false;
    if (root != NULL){
        *d = root->data;
        get = true;
    }
    else{
        d->id = -1;
        d->information = "";
    }
    return get;
}

void BinTree::displayTree() {
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "==============================================" << std::endl;
    if (isEmpty()){
        std::cout << "Tree is empty" << std::endl;
    }
    else{
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height " << getHeight() << std::endl;
    std::cout << "Count " << getCount() << "\n\n";
    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "==============================================" << "\n\n";
}

void BinTree::clear() {
    clear(root);
    root = NULL;
    count = 0;
}

void BinTree::clear(DataNode *rn) {
    if (rn){
        clear(rn->left);
        clear(rn->right);
        rn->left = NULL;
        rn->right = NULL;
        delete rn;
    }
}

bool BinTree::addNode(int i, const string *s) {
    bool added = false;
    if (i>0 && *s != ""){
        DataNode *node;
        node = new DataNode;
        node->data.id = i;
        node->data.information = *s;
        node->right = NULL;
        node->left = NULL;
        if (addNode(node,&root)){
            added = true;
            count ++;
        }
    }
    return added;
}

bool BinTree::addNode(DataNode *node, DataNode **rn) {
    bool added = false;
    if (*rn){
        if ((*rn)->data.id > node->data.id){
            added = addNode(node,&((*rn)->left));
        }
        else if ((*rn)->data.id < node->data.id){
            added = addNode(node,&((*rn)->right));
        }
    }
    else{
        *rn = node;
        added = true;
    }
    return added;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

bool BinTree::removeNode(int id) {
    bool removed = false;
    int tempcount = count;
    root = removeNode(id,root);
    if (tempcount > count){
        removed = true;
    }
    return removed;
}

DataNode* BinTree::removeNode(int id, DataNode *rn) {
    if (rn){
        if (rn->data.id > id){
            rn->left = removeNode(id,rn->left);
        }
        else if (rn->data.id < id){
            rn->right = removeNode(id,rn->right);
        }
        else{
            DataNode *temp;
            if (rn->left == NULL){
                temp = rn->right;
                delete rn;
                rn = temp;
                count --;
            }
            else if (rn->right == NULL){
                temp = rn->left;
                delete rn;
                rn = temp;
                count --;
            }
            else{
                temp = minValueNode(rn->right);
                rn->data.id = temp->data.id;
                rn->data.information = temp->data.information;
                rn->right = removeNode(temp->data.id,rn->right);
            }
        }
    }
    return rn;
}

bool BinTree::getNode(Data *d, int i) {
    bool gotNode = false;
    if (i>0){
        gotNode = getNode(d,i,root);
    }
    return gotNode;
}

bool BinTree::getNode(Data *d, int i, DataNode *rn) {
    bool gotNode = false;
    if (rn){
        if (rn->data.id == i){
            gotNode = true;
            *d = rn->data;
        }
        else if (rn->data.id > i ){
            gotNode = getNode(d,i,rn->left);
        }
        else{
            gotNode = getNode(d,i,rn->right);
        }
    }
    return gotNode;
}

bool BinTree::contains(int i) {
    bool contained = false;
    if (i>0){
        contained = contains(i,root);
    }
    return contained;
}

bool BinTree::contains(int i, DataNode *rn) {
    bool contained = false;
    if (rn){
        if (rn->data.id == i){
            contained = true;
        }
        else if (rn->data.id > i ){
            contained = contains(i,rn->left);
        }
        else{
            contained = contains(i,rn->right);
        }
    }
    return contained;
}

int BinTree::getHeight() {
    int height = 0;
    if (root){
        height = getHeight(root);
    }
    return height;
}

int BinTree::getHeight(DataNode *rn) {
    int lh = 0;
    int rh = 0;
    int height = 0;
    if (rn){
        lh = getHeight(rn->left);
        rh = getHeight(rn->right);
        if (lh > rh){
            height = lh+1;
        }
        else{
            height = rh+1;
        }
    }
    return height;
}

void  BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void  BinTree::displayPreOrder(DataNode *rn){
    if (rn){
        std::cout << rn->data.id << " " << rn->data.information << std::endl;
        displayPreOrder(rn->left);
        displayPreOrder(rn->right);
    }
}

void  BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void  BinTree::displayPostOrder(DataNode *rn) {
    if (rn){
        displayPostOrder(rn->left);
        displayPostOrder(rn->right);
        std::cout << rn->data.id << " " << rn->data.information << std::endl;
    }
}

void  BinTree::displayInOrder() {
    displayInOrder(root);
}

void  BinTree::displayInOrder(DataNode *rn) {
    if (rn){
        displayInOrder(rn->left);
        std::cout << rn->data.id << " " << rn->data.information << std::endl;
        displayInOrder(rn->right);
    }
}