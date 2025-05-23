#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <concepts>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

namespace cpplab{
    template<typename T> 
    class vector
    {
        public:
            // Default constructor without memory allocation
            vector() : maxSize(0), _size(0), begin(nullptr) {}

            // [] Operator overloading to acquire element of vector
            T& operator[](int a) const
            {
                return begin[a];
            }

            // Method to append new element at the end of the vector 
            void push_back(T val)
            {
                // Memory allocation if begin pointer doesn't "exist" yet
                if(empty())
                {
                    resize(1);
                    begin[0] = val;
                    _size++;
                }

                else if(_size < maxSize)
                {
                    begin[_size] = val;
                    _size++;
                }
                else if (_size == maxSize)
                {
                    resize(maxSize + 1);
                    begin[_size] = val;
                    _size++;
                }
                else 
                {
                    throw std::runtime_error("cpplab::vector push_back error!");
                }
            }

            // Method to delete element at the end of the vector 
            void pop_back()
            {
                if(_size > 0)
                {
                    _size--;
                    begin[_size] = 0;
                }
                else
                {
                    throw std::runtime_error("cpplab::vector pop_back error!");
                }
            }

            // Method to create new, bigger vector and copy previous 
            // content into the new one 
            void resize(size_t count)
            {
                if(maxSize != count)
                {
                    if(maxSize == 0)    maxSize = 2;
                    else
                    {
                        while(maxSize < count) maxSize *= 2;
                    }

                    T* new_begin = new T[maxSize];
                    for(size_t i = 0; i < _size; i++)
                    {
                        new_begin[i] = begin[i];
                    }

                    if(begin != nullptr) {delete[] begin;}
                    begin = new_begin;
                }
            }

            // Method to get current _size of the vector 
            size_t size() const
            {
                return _size;
            }

            bool empty()
            {
                return _size == 0;
            }

            // Destructor of the vector 
            ~vector()
            {
                // std::cout<<"cpplab::vector destroyed!\n";
                delete[] begin;
            }

            
            using value_type = T; // Type of vector elements
        private:
            size_t maxSize; // Max size of vector
            size_t _size; // Current size of vector
            T* begin; // Pointer to first element of the vector
    };

};

template<typename T>
concept multiplicable = requires (T t){
    // Check if type has size parameter
    {t.size()} -> std::same_as<size_t>;
    // Check if type is iterable
    {t[0]};
    // Check if type's values are numbers
    requires std::is_arithmetic_v<std::remove_reference_t<decltype(t[0])>>;
};

auto operator*(const multiplicable auto &L_type, const multiplicable auto &R_type)
{
    if(L_type.size() == R_type.size())
    {
        auto product = 0;
        size_t size = 0;

        size = R_type.size();
        for(size_t i = 0; i < size; i++)
        {
            product += L_type[i] * R_type[i];
        }
        return product;
    }
    else
    {
        throw std::runtime_error("Vectors must be the same size!");
    }
}

// Only to print cpplab::vector in comfortable way
template<typename T>
std::ostream& operator<<(std::ostream& os, const cpplab::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        os << vec[i] << " ";
    }
    return os;
}

// Only to print std::vector in comfortable way
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (T a : vec)
    {
        os << a << " ";
    }
    return os;
}

