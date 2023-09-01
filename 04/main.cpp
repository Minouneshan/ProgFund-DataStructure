/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    std::string temp;
    int num;
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on empty stack
    Data *value = new Data;
    if(stack.peek(value)){
        cout << "peeked with id " << value->id << " and information " << value->information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    try{
        stack.pop(value);
        cout << "popped with id " << value->id << " and information " << value->information << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */
    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/

    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;
    cout << "Filling stack..." << endl;
    cout << "Stack size is " << STACK_SIZE << ", so we should expect "<< number_test_cases-STACK_SIZE << " overflows!" <<endl;
    for (int i = 0; i < number_test_cases; i++) {

        temp = data[i];
        if (stack.push(ids[i],&temp)) {
            cout << "pushed with id " << ids[i] << " and information " << data[i] << endl;

        } else {
            cout << "overflow error: " << ids[i] << " with " << data[i]<< " not pushed" << endl;
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

    // testing peek() and pop() on full stack
    if(stack.peek(value)){
        cout << "peeked with id " << value->id << " and information " << value->information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    try{
        stack.pop(value);
        cout << "popped with id " << value->id << " and information " << value->information << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty " << value->id << endl;
    }
    cout << endl;

    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;

    // this is a programmer debug routine used for
    // testing and is not part of normal stack methods
    stack.dumpStack();

    /************************************************
    ******** TESTING UNVALID VALUES ***************
    ************************************************/
    cout << "Testing unvalid values: empty string and negative integer." << endl;
    cout << "=====================================================" << endl;
    // trying empty string
    temp = "";
    if (stack.push(5,&temp)) {
        cout << "pushed with id " << 5 << " and information " << temp << endl;

    } else {
        cout << "unvalid values: " << 5 << " with " << temp<< " not pushed" << endl;
    }

    // trying negative integer
    temp = "aaaaaa";
    if (stack.push(-5,&temp)) {
        cout << "pushed with id " << -5 << " and information " << temp << endl;

    } else {
        cout << "unvalid values: " << -5 << " with " << temp<< " not pushed" << endl;
    }
    /************************************************
    ******** EMPTYING AND EMPTY TESTS ***************
    ************************************************/

    cout << "\n\nTesting peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack
    for (int i = 0; i < number_test_cases; i++) {
        if(stack.peek(value)){
            cout << "peeked with id " << value->id << " and information " << value->information << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        try{
            stack.pop(value);
            cout << "popped with id " << value->id << " and information " << value->information << endl;
        } catch(...){
            cout << "pop underflow error: stack is empty " << value->id << endl;
        }
    }
    cout << endl;
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else{
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on empty stack
    if(stack.peek(value)){
        cout << "peeked with id " << value->id << " and information " << value->information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }

    try{
        stack.pop(value);
        cout << "popped with id " << value->id << " and information " << value->information << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/

    cout << "Random testing..." << endl;
    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACK_SIZE / 2); i++) {
        temp = data[rand() % number_test_cases];
        num = ids[rand() % number_test_cases];
        if (stack.push(num,&temp)) {
            cout << "pushed with id " << num << " and information " << temp << endl;
        } else {
            cout << "overflow error: " << num << " with " << temp<< " not pushed" << endl;
        }
    }
    cout << endl;
    if(stack.peek(value)){
        cout << "peeked with id " << value->id << " and information " << value->information << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    /*
     * the following will test random operations. push() and pop()
     * are called twice as often as peek and isempty because they
     * change the stack and should be tested more rigorously.
     */

   int choice = rand() % CHOICES + 1;
   for (int i = 0; i < number_test_cases * 20; i++) {
       switch (choice) {
           case 1:
           case 2:
               // push
               temp = data[rand() % number_test_cases];
               num = ids[rand() % number_test_cases];
               if (stack.push(num,&temp)) {
                   cout << "pushed with id " << num << " and information " << temp << endl;
               } else {
                   cout << "overflow error: " << num << " with " << temp << " not pushed" << endl;
               }
               break;
           case 3:
           case 4:
               // pop
               try{
                   stack.pop(value);
                   cout << "popped with id " << value->id << " and information " << value->information << endl;
               } catch(...){
                   cout << "pop underflow error: stack is empty " << value->id << endl;
               }
               break;
           case 5:
               // peek
               if(stack.peek(value)){
                   cout << "peeked with id " << value->id << " and information " << value->information << endl;
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

   stack.dumpStack();

   cout << "Testing complete." << endl;
    delete value;
    return 0;
}
