#ifndef CPPLAB_ALLOCATOR_H
#define CPPLAB_ALLOCATOR_H

#include <cstddef> // std::size_t
#include <new>     // placement new, placement delete
#include <iostream>
#include <vector>

namespace cpplab {

template<typename T>
class allocator {
public:
    // Typ alias dla typu alokowanego
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

} // namespace cpplab

#endif // CPPLAB_ALLOCATOR_H



int main(){
    cpplab::allocator<int> alloc;
    std::cout<<typeid(cpplab::allocator<int>::value_type).name()<<std::endl;
    cpplab ::allocator<int>::value_type* p_test = alloc.allocate(1);
    std::cout<<*p_test<<std::endl;
    *p_test= 3;
    std::cout<<*p_test<<std::endl; alloc.deallocate(p_test,1);
    std::vector<int, cpplab::allocator<int>> v;
    v.push_back(13); v.push_back(23);
    std::cout<<*(v.end()-1)<<std::endl;
}