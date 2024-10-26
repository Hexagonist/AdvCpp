#pragma once

#include <iostream>

// Funkcja końcowa dla przypadku bez argumentów (przerywa rekurencję)
void print_all() {
    std::cout << std::endl;
}

// Funkcja rekurencyjna dla przypadku, gdy >1 argumentów
template <typename First, typename... Rest>
void print_all(First first, Rest... rest) {
    std::cout << first << " ";
    
    print_all(rest...); 
}