#include "singleton_dynamic.h"
#include "singleton.h"

// Oznacz funkcję calls2() jako SINGLETON_DYNAMIC_API
// SINGLETON_DYNAMIC_API void calls2() {
void calls2() {
    Singleton::instance().calls();
}

// Nie oznaczaj funkcji instance() jako SINGLETON_DYNAMIC_API w definicji
Singleton& instance() {
    return Singleton::instance();
}