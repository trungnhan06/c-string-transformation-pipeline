#pragma once

/*
    Function prototypes for string transformation functions.
*/

// returns a new string that is the reverse of the input string
char* f_reverse(const char* input);     

// returns a new string that is the uppercase version of the input string
char* f_uppercase(const char* input); 

// returns a new string that is the lowercase version of the input string
char* f_lowercase(const char* input);   

// returns a new string that has the case of each character toggled
char* f_togglecase(const char* input);  

// returns a new string that is a shuffled version of the input string
char* f_shuffle(const char* input);     

// returns a new string that is identical to the input string
char* f_same(const char* input);      
