/*********************
/*
 * File:   main.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "main.h"

int main(int argc, char** argv) {
    Stack s1;
    std::cout << "First check our isempty method: " << std::endl;
    if (s1.isEmpty()){
        std::cout << "Stack is Empty"<< std::endl;
    }
    else{
        std::cout << "Stack is not Empty"<< std::endl;
    }
    std::cout << "Check pop method before adding any array member(underflow for empty): "<<std::endl;
    try {
        s1.pop();
    } catch (int e) {
        std::cout << "Underflow" << std::endl;
    }
    try {
        std::cout << "Also before pushing, the Peak in the empty stack should be empty therefore underflow(underflow for empty): "<< s1.peak() << std::endl;
    } catch (int e) {
        std::cout << "Underflow" << std::endl;
    }

    int x1 = std::rand() % 20 +10;
    std::cout << "The number of random trials to push data into the stack is: "<< x1 << std::endl;
    int x2 = std::rand() % 30 + x1 ;
    std::cout << "The number of random trials to pop data from the stack is: "<< x2 << std::endl;
    std::cout << "The number of printing overflows should be: "<< x1-10<<std::endl;
    for(int i=1; i <= x1;i++ ){
        try {
            s1.push(i);}
        catch (int e){
            std::cout<< "overflow" <<std::endl;
        }
    }
    try {
        std::cout << "Now after ending pushing, the Peak is(underflow for empty): "<< s1.peak() << std::endl;
    } catch (int e) {
        std::cout << "Underflow" << std::endl;
    }
    if (s1.isEmpty()){
        std::cout << "Empty"<< std::endl;
    }
    else{
        std::cout << "Not Empty"<< std::endl;
    }
    std::cout << "The number of printing underflows should be: "<< x2-10<<std::endl;
    for(int i=0; i<x2;i++) {
        try {
            s1.pop();
        } catch (int e) {
            std::cout << "Underflow" << std::endl;
        }
    }
    std::cout << "Now lets check again our isempty method: " << std::endl;
    if (s1.isEmpty()){
        std::cout << "Empty"<< std::endl;
    }
    else{
        std::cout << "Not Empty"<< std::endl;
    }
    try {
        std::cout << "Now in the end pushing, the Peak in the empty stack: "<< s1.peak() << std::endl;
    } catch (int e) {
        std::cout << "Underflow" << std::endl;
    }
    try {
        std::cout << "Now in the end of poping, the Peak in the empty stack: "<< s1.peak() << std::endl;
    } catch (int e) {
        std::cout << "Underflow" << std::endl;
    }
    return 0;
}
