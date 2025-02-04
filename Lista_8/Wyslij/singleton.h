#ifndef SINGLETON_H
#define SINGLETON_H

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

class __declspec(dllexport) Singleton {
public:
    static Singleton& instance();
    void calls();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    ~Singleton();

private:
    Singleton();

    static Singleton* instance_;
    int callCount_;
};

#endif