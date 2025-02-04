#ifndef SINGLETON_DYNAMIC_H
#define SINGLETON_DYNAMIC_H

#ifdef _WIN32
    #ifdef BUILDING_DLL
        #define SINGLETON_DYNAMIC_API __declspec(dllexport)
    #else
        #define SINGLETON_DYNAMIC_API __declspec(dllimport)
    #endif
#else
    #define SINGLETON_DYNAMIC_API
#endif

class __declspec(dllexport) Singleton;

extern "C" {
    __declspec(dllexport) void calls2();
    __declspec(dllexport) Singleton& instance();
}

#endif // SINGLETON_DYNAMIC_H