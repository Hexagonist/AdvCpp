#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <concepts>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

namespace cpplab{
    template<typename T>
    class unique_ptr
    {
        using value_type = T;

        public:
        constexpr void reset()
        {
            delete data;
            data = nullptr;
        }

        constexpr unique_ptr() = default;
        // unique_ptr(T value) : adress(&value) {}
        constexpr unique_ptr(T* data_) : data(data_) {}

        // Move 
        constexpr unique_ptr(unique_ptr &&other) : data(std::exchange(other.data, nullptr)) {}
        constexpr unique_ptr &operator=(unique_ptr &&other)
        {
            if(data)    {reset();}
            data = std::exchange(other.data, nullptr);
        }

        // copy operations deleted
        unique_ptr(const unique_ptr &) = delete;
        unique_ptr &operator=(const unique_ptr &) = delete; 

        

        T* get() const 
        {return data;}

        T operator*() const
        {return *data;}

        T* operator->() const
        {return data;}

        constexpr ~unique_ptr()   {reset();}

        private:
        T* data;
    };
}

struct pixel
{
    int r;
    int g;
    int b;

    // default constructor
    pixel() : r(0), g(0), b(0)
    {
        std::cout<<"pixel constructed by default!\n"; 
    }

    // move constructor
    pixel(int &&r, int &&g, int &&b) noexcept : r(std::move(r)), g(std::move(g)), b(std::move(b)) 
    {
        std::cout<<"pixel constructed by move!\n";
    }

    void print()
    {
        std::cout<<r<<" "<<g<<" "<<b<<"\n";
    }

    ~pixel() 
    {
        std::cout<<"pixel destroyed!\n";
    }
};



// Concept to ensure a type is a pointer type
template <typename T>
concept PointerType = requires(T t) {
    // Ensure it behaves like a pointer (must be comparable to nullptr)
    { t == nullptr } -> std::same_as<bool>; 
    // Ensure dereferencing is valid
    { *t };                                
};

// Template class for non0_ptr
template <PointerType T>
class non0_ptr {
private:
    T ptr;

    void validate(T p) {
        if (p == nullptr) {
            throw std::invalid_argument("non0_ptr cannot be initialized or assigned with nullptr.");
        }
    }

public:
    // Constructor
    explicit non0_ptr(T p) : ptr(p) {
        validate(p);
    }

    // Deleted default constructor to avoid uninitialized non0_ptr
    non0_ptr() = delete;

    // Deleted nullptr assignment
    non0_ptr(std::nullptr_t) = delete;

    // Copy constructor
    non0_ptr(const non0_ptr& other) : ptr(other.ptr) {}

    // Move constructor
    non0_ptr(non0_ptr&& other) noexcept : ptr(std::move(other.ptr)) {
        other.ptr = nullptr;
    }

    // Destructor
    ~non0_ptr() = default;

    // Assignment operator (copy)
    non0_ptr& operator=(const non0_ptr& other) {
        if (this != &other) {
            validate(other.ptr);
            ptr = other.ptr;
        }
        return *this;
    }

    // Assignment operator (move)
    non0_ptr& operator=(non0_ptr&& other) noexcept {
        if (this != &other) {
            ptr = std::move(other.ptr);
            other.ptr = nullptr;
        }
        return *this;
    }

    // Accessors
    T operator*() const {
        return *ptr;
    }

    T operator->() const {
        return ptr;
    }

    T get() const {
        return ptr;
    }
};
