#include "calls1.h"
#include "singleton.h"

void calls1() {
    Singleton::instance().calls();
}