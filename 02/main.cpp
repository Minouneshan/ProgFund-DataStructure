/*
 * This is a simple application to demonstrate classes and objects in C++.
 * Note the header structure and files for all cpp and h files.
 * The only thing included in main.cpp is it's main.h file.
 * This file, main.cpp, includes only main.h.
 */

/*
 * File:   functions.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "main.h"

int main(int argc, char** argv) {
    //creates a circle object with no parameters
    Circle myCircle1;
    //creates a circle object with radius 5
    Circle myCircle2(5);

    //creates a sphere object with no parameters
    Sphere mySphere1;
    //creates a sphere object with radius 5
    Sphere mySphere2(5);

    //examples of passing objects by reference
    displayCircle(&myCircle1);
    displayCircle(&myCircle2);

    displaySphere(&mySphere1);
    displaySphere(&mySphere2);

    return 0;
}
