#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
public:
    static Singleton& instance();
    void calls();

    // Usuwamy konstruktor kopiujący i operator przypisania
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton();
    ~Singleton();

    static Singleton* instance_;
    int callCount_;
};

#endif // SINGLETON_H

#include <iostream>

Singleton* Singleton::instance_ = nullptr;

Singleton::Singleton() {
    std::cout << "Created object at address: " << this << " +\n";
    callCount_ = 0;
}

Singleton::~Singleton() {
    std::cout << "Destroyed object at address: " << this << " -\n";
    delete instance_;
}


Singleton& Singleton::instance() {
    if (instance_ == nullptr) {
        instance_ = new Singleton();
    }
    return *instance_;
}

void Singleton::calls() {
    ++callCount_;
    std::cout << "Object at address: " << this << " has been called " << callCount_ << " times.\n";
}

#ifndef CALLS1_H
#define CALLS1_H

void calls1();

#endif // CALLS1_H


void calls1() {
    Singleton::instance().calls();
}


int main() {
    
    Singleton& singleton = Singleton::instance();
    singleton.calls();
    calls1();
    
    // delete &singleton;
    std::cout<<"end of program\n";
    return 0;
}