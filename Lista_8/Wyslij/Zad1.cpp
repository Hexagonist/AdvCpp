#include "singleton.h"
#include "calls1.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main() 
{
    Singleton& singleton = Singleton::instance();
    singleton.calls();
    calls1();
    
    return 0;
}