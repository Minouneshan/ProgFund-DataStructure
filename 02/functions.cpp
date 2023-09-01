/*
 *
 *
 *
 *
 */

/*
 * File:   functions.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */


#include "functions.h"

void displayCircle(Circle *myCircle){

    std::cout << myCircle->getRadius() << std::endl;
    std::cout << myCircle->getArea() << std::endl;
    std::cout << std::endl;

}

void displaySphere(Sphere *mySphere){

    std::cout << mySphere->getRadius() << std::endl;
    std::cout << mySphere->getVolume() << std::endl;
    std::cout << mySphere->getArea() << std::endl;
    std::cout << std::endl;

}