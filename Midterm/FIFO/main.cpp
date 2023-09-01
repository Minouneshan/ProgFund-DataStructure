/*********************
/*
 * File:   main.cpp
 * Author: Mohamad Minoneshan
 * student ID: s2134963
 */

#include "main.h"

#include "main.h"

int main() {
    // seeds the rand() function
    // call only ONCE per application!
    srand(time(NULL));

    // create stack
    Stack stack;

    /************************************************
    ******* EMPTY TESTS *****************************
    ************************************************/

    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    /* NOTE: peek() and pull() use different techniques in this example ONLY
     * for demonstration purposes. normally peek() and pull() should have
     * identical interfaces and calls.
     */

    // testing peek() and pull() on empty stack
    int value;

    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    try{
        value = stack.pull();
        cout << "pull: " << value << endl;
    } catch(...){
        cout << "pull underflow error: stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/

    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    // testing filling the stack and overflow
    cout << "Filling stack..." << endl;
    for (int i = 0; i < MULTIPLIER*STACKSIZE; i++) {
        if (stack.push(i + 1)) {
            cout << "pushed: " << i + 1 << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }
    cout << endl;

    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pull() on full stack
    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    try{
        value = stack.pull();
        cout << "pull: " << value << endl;
    } catch(...){
        cout << "pull underflow error: stack is empty" << value << endl;
    }
    cout << endl;

    cout << "Clearing stack..." << endl;
    cout << "=====================================================" << endl;

    // this is a programmer debug routine used for
    // testing and is not part of normal stack methods
    stack.clearList();

    /************************************************
    ******** EMPTYING AND EMPTY TESTS ***************
    ************************************************/

    cout << "Testing peek and pull, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing pulling and peeking whole stack
    for (int i = 0; i < MULTIPLIER*STACKSIZE; i++) {
        if(stack.peek(&value)){
            cout << "peeked: " << value  << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        try {
            cout << "pulled: " << stack.pull() << endl;
        } catch (...) {
            cout << "pull underflow error: stack is empty" << endl;
        }
    }
    cout << endl;
    cout << "clearing stack..." << endl;
    cout << "=====================================================" << endl;
    stack.clearList();

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pull() on empty stack
    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    try{
        value = stack.pull();
        cout << "pulled: " << value << endl;
    } catch(...){
        cout << "pull underflow error: stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/

    cout << "Random testing..." << endl;
    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACKSIZE / 2); i++) {
        value = rand() % MAX_INT + 1;
        if (stack.push(value)) {
            cout << "pushed: " << value << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }
    cout << endl;

    /*
     * the following will test random operations. push() and pull()
     * are called twice as often as peek and isempty because they
     * change the stack and should be tested more rigorously.
     */
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_TRIES; i++) {
        switch (choice) {
            case 1:
            case 2:
                // push
                value = (rand() % MAX_INT) + 1;
                if (stack.push(value)) {
                    cout << "pushed: " << value << endl;
                } else {
                    cout << "overflow error: " << value << " not pushed" << endl;
                }
                break;
            case 3:
            case 4:
                // pull
                try{
                    value = stack.pull();
                    cout << "pulled: " << value << endl;
                } catch(...){
                    cout << "pull underflow error: stack is empty" << endl;
                }
                break;
            case 5:
                // peek
                if(stack.peek(&value)){
                    cout << "peeked: " << value << endl;
                } else {
                    cout << "peek underflow error: stack is empty" << endl;
                }
                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    cout << endl;

    stack.clearList();

    cout << "Testing complete." << endl;
    return 0;
}

