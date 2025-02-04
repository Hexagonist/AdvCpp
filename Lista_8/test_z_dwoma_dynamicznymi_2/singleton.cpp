#include "singleton.h"
#include <iostream>

Singleton& Singleton::instance() {
    static Singleton instance;  // Statyczna zmienna lokalna
    return instance;
}

Singleton::Singleton() {
    std::cout << "Created object at address: " << this << " +\n";
    callCount_ = 0;
}

Singleton::~Singleton() {
    std::cout << "Destroyed object at address: " << this << " -\n";
}

void Singleton::calls() {
    ++callCount_;
    std::cout << "Object at address: " << this << " has been called " << callCount_ << " times.\n";
}
