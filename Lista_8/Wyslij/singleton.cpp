#include "singleton.h"
#include <iostream>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

Singleton::Singleton() 
{
    std::cout << "Created object at address: " << this << " +\n";
    callCount_ = 0;
}

Singleton& Singleton::instance() 
{
    static Singleton instance;
    return instance;
}

void Singleton::calls() 
{
    ++callCount_;
    std::cout << "Object at address: " << this << " has been called " << callCount_ << " times.\n";
}

Singleton::~Singleton() 
{
    std::cout << "Destroyed object at address: " << this << " -\n";
}