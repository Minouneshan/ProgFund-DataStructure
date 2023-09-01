/*
 * File:   main.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 *
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // create your hash table object here
    Hashtable hashtable;

    // show it is empty by calling getCount and printTable
    cout << hashtable.getCount() << "\n\n";
    hashtable.printTable();

    // try and put ALL the test data into the table and show what happens
    for (int i=0;i<testdatasize;i++){
        hashtable.insertEntry(ids[i],&strs[i]);
    }
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    // counting the number inserted values in our hashtable
    cout << hashtable.getCount() << "\n\n";

    for (int i=0;i<testdatasize;i++){
        hashtable.insertEntry(ids[i],&strs[i]);
    }
    // printing all the hashtable after adding
    hashtable.printTable();


    // Now remove all values from hashtable to see what happens
    if (hashtable.clearTable()){
        cout << "whole table cleared." << "\n\n";
    }


    // printing all the hashtable after removing
    hashtable.printTable();
    // counting the number existing values in our hashtable after total removal
    cout << hashtable.getCount() << "\n\n";


    // inserting all values again to the hashtable


    cout << hashtable.getCount() << "\n\n";
    hashtable.printTable();
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;
    for (int i=0;i<testdatasize;i++){
        hashtable.insertEntry(ids[i],&strs[i]);
    }
    if (hashtable.clearTable()){
        cout << "whole table cleared." << "\n\n";
    }
    hashtable.printTable();

    return 0;
}
