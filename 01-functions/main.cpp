/*********************
* Your comment header here.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    // arc is a count of the command line parameters passed to the program
    // argv are the actual parameters passed in command line

    std::cout << "My Command line analyzer..." << std::endl;
    std::cout << "The number of command line parameters are: " << argc << std::endl;
    std::cout << "The length of the name of the program is: " << string_length(argv[0]) << std::endl;

    // loop through all the command line parameters not including the program name
    if(argc > 1){
        for(int i=1;i<argc;i++){
            std::cout << "The length of the parameter " << i <<" is " << string_length(argv[i]) << std::endl;
        }
    }

    return 0;
}
