#include <iostream>
#include "singleton_dynamic.h"
#include "singleton.h"

// DZIALA https://www.geeksforgeeks.org/how-to-create-a-dynamic-library-in-cpp/

int main() {
    // Wywołanie funkcji calls2() z biblioteki dynamicznej
    calls2();

    // Wywołanie metody calls() na obiekcie zwróconym przez instance()
    Singleton& singleton = Singleton::instance();
    singleton.calls();

    return 0;
}