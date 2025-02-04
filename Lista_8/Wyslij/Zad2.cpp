#include <iostream>
#include "singleton_dynamic.h"
#include "singleton.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main() 
{
    calls2();

    Singleton& singleton = Singleton::instance();
    singleton.calls();

    return 0;
}