/*
 *
 *
 *
 *
 */

/*
 * File:   sphere.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "sphere.h"

Sphere::Sphere() {
    //use your own setters!
    setRadius(MIN);
}

Sphere::Sphere(int r) {
    //use your own setters!
    setRadius(r);
}

Sphere::~Sphere() {
}


int Sphere::getVolume() {
    return ((pow(radius,3.0)*PI*4)/3);
}

int Sphere::getArea() {
    /*
     * This returns surface area overriding the getArea() of Circle
     * since 2D area makes no sense for a Sphere
    */
    return (pow(radius,2.0)*4*PI);
}