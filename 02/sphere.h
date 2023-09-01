/*
 *
 *
 *
 *
 */

/*
 * File:   sphere.h
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere : public Circle {
public:
    Sphere();
    Sphere(int);
    ~Sphere();

    /*
     * Getters
     */
    int getVolume();
    int getArea();

    /*
     * Setters
     */
    // No setter

    /* No Private Variable
    * private:
     * */
};

#endif //CLASSES_SPHERE_H