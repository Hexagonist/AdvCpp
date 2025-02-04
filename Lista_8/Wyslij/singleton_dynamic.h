#ifndef SINGLETON_DYNAMIC_H
#define SINGLETON_DYNAMIC_H

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

class __declspec(dllexport) Singleton;

extern "C" {
    __declspec(dllexport) void calls2();
    __declspec(dllexport) Singleton& instance();
}

#endif