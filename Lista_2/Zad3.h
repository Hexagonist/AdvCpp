#pragma once

#include <iostream>

// Funkcja końcowa dla przypadku bez argumentów (przerywa rekurencję)

void print_all() {
    std::cout <<"end of args"<< std::endl;
}
// Funkcja rekurencyjna dla przypadku, gdy >1 argumentów (dziala)
// template <typename First, typename... Rest>
// void print_all(First first, Rest... rest) {
//     std::cout << first << " ";
    
//     print_all(rest...); 
// }

// Funkcja rekurencyjna dla przypadku, gdy >1 argumentów
// Function prints all of arguments recursively
template <typename First, typename... Rest>
void print_all(First first, Rest... rest) {
    std::cout << first << " ";
    
    if(sizeof...(rest) > 0) 
    {
        print_all(rest...);
    }

    // for(size_t i = 0; i < sizeof...(rest); i++)
    // {
    //     (std::cout << ... << rest) << " ";
    // }; 

    // std::cout << sizeof...(rest) << " ";

}