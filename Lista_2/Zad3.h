#pragma once
#include <iostream>

// Final function to stop recursion in case of 0 arguments
void print_all() {
    std::cout <<"No arguments were given"<< std::endl;
}

// Function prints all of arguments recursively in case >0 arguments given
template <typename First, typename... Rest>
void print_all(First first, Rest... rest) {
    std::cout << first << " ";
    
    if(sizeof...(rest) > 0) 
    {
        print_all(rest...);
    }
}