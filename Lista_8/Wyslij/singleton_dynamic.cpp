#include "singleton_dynamic.h"
#include "singleton.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

void calls2() 
{
    Singleton::instance().calls();
}

Singleton& instance() 
{
    return Singleton::instance();
}