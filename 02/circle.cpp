/*
 *
 *
 *
 *
 */

/*
 * File:   circle.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
*/

#include "circle.h"

Circle::Circle() {
    //setter for Radius
    setRadius(MIN);
}

Circle::Circle(int r) {
    //setter for Radius
    setRadius(r);
}

Circle::~Circle() {
}

int Circle::getRadius() {
    return radius;
}

int Circle::getArea() {
    return (PI*pow(radius,2));
}

void Circle::setRadius(int r) {
    //setters are where you keep your protections for attributes
    if (r > MIN) {
        radius = r;
    } else {
        radius = MIN;
    }
}