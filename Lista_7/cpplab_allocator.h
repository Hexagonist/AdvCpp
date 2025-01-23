#pragma once

#include <iostream>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

namespace cpplab {

template<typename T>
class allocator {
public:
    // Alias type for type to allocate
    using value_type = T;

    // Domyślny konstruktor i destruktor (bezstanowy obiekt)
    allocator() noexcept = default;
    ~allocator() noexcept = default;

    // Metoda alokująca pamięć dla n elementów typu T
    T* allocate(std::size_t n) {
        if (n == 0) {
            return nullptr;
        }
        // Rzutowanie alokowanej pamięci na typ T*
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    // Metoda zwalniająca pamięć wskazaną przez p
    void deallocate(T* p, std::size_t n) noexcept {
        if (p == nullptr) {
            return;
        }
        // Zwalnianie pamięci za pomocą operatora placement delete
        ::operator delete(p, n * sizeof(T));
    }
};

}