#include "functions.h"

// This function counts the length of the input character
int string_length(const char *str){
    int count = 0;
        while(str[count] != '\0'){
            count++;}
        return count;

}
