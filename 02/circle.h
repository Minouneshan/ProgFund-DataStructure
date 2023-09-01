/*
 *
 *
 *
 *
 */

/*
 * File:   circle.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#include <math.h>

#define MIN 0
#define PI 2*acos(0)

class Circle {

public:

    /*
     * constructors
     * one with no params, one with params (overloading)
     */
    Circle();
    Circle(int);
    //destructor (not used in this example)
    ~Circle();

    /*
     * Getters
     */
    int getRadius();
    int getArea();

    /*
     * Setters
     */
    void setRadius(int);


protected:
    //private variables that define a circle
    int radius;

};

#endif //CLASSES_CIRCLE_H