#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
public:
    static Singleton& instance();
    void calls();

    // Usuwamy konstruktor kopiujący i operator przypisania
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    ~Singleton();

private:
    Singleton();

    static Singleton* instance_;
    int callCount_;
};

#endif // SINGLETON_H