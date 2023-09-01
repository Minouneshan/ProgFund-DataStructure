/*
 * File:   data.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

struct Data {
    int id;
    int weight;
};

struct DataNode {
    Data data;
    DataNode *left, *right;
};

#endif /* GRAPH_DATA_H */

