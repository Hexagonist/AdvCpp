#include "singleton.h"
// #include "calls1.h"

int main() {
    
    Singleton& singleton = Singleton::instance();
    singleton.calls();
    // calls1();
    
    return 0;
}