#pragma once

#include <iostream>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

namespace cpplab {

template<typename T>
class allocator {
public:
    // Alias type for the type to allocate
    using value_type = T;

    // Default constructor and destructor (stateless object)
    allocator() noexcept = default;
    ~allocator() noexcept = default;

    // Method to allocate memory for n elements of type T
    T* allocate(std::size_t n) {
        if (n == 0) {
            return nullptr;
        }
        // Cast allocated memory to type T*
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    // Method to deallocate memory pointed to by p
    void deallocate(T* p, std::size_t n) noexcept {
        if (p == nullptr) {
            return;
        }
        // Deallocate memory using placement delete
        ::operator delete(p, n * sizeof(T));
    }
};

}