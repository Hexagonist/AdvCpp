#pragma once
#include <iostream>
#include <vector>
#include <string>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15
namespace cpplab{
    template<typename T> 
    class vector
    {
        public:
            // Default constructor without memory allocation
            vector() : maxSize(0), _size(0), begin(nullptr)
            {
                // std::cout<<"cpplab::vector created!"<<std::endl;
            }

            // [] Operator overloading to acquire element of vector
            T& operator[](int a) const
            {
                return begin[a];
            }

            // Method to append new element at the end of the vector 
            void push_back(T val)
            {
                // Memory allocation if begin pointer doesn't "exist" yet
                if(begin == nullptr)// Sprawdzić is_empty i poprawnie zaimplementować (nullptr prawdopodobnie może nie wystarczyć
                //  może być np samo null) 
                {
                    resize(1);
                    begin[0] = val;
                    _size++;
                    // std::cout<<"begin==nullptr\n";
                }

                else if(_size < maxSize)
                {
                    // std::cout<<"Pushing back: "<<val<<"\n";
                    begin[_size] = val;
                    _size++;
                    // std::cout<<"_size<\n";
                }
                else if (_size == maxSize)
                {
                    resize(maxSize + 1);
                    begin[_size] = val;
                    _size++;
                    // std::cout<<"_size==\n";
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
                    // std::cout<<"Poping back"<<"\n";
                    _size--;
                    begin[_size] = 0;
                    // std::cout<<"Popped val =  "<<begin[_size]<<"\n";
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

            // Destructor of the vector 
            ~vector()
            {
                delete[] begin;
                // std::cout<<"cpplab::vector destroyed!\n";
            }

            
        private:
            size_t maxSize; // Max size of vector
            size_t _size; // Current size of vector
            T* begin; // Pointer to first element of the vector
            using value_type = T; // Type of vector elements
    };

    // * operator overloading for cpp::vector and std::vector
    template<typename T, typename U> 
    auto operator*(T& L_type, U& R_type)
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
};

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


