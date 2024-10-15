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
            vector() : maxSize(0), size(0), begin(nullptr)
            {
                // std::cout<<"cpplab::vector created!"<<std::endl;
            }

            // [] Operator overloading to acquire element of vector
            T& operator[](int a) const
            {
                return begin[a];
            }

            // Method to append new element at the end of the vector 
            void push_back(T&& val)
            {
                // Memory allocation if begin pointer doesn't "exist" yet
                if(begin == nullptr)
                {
                    resize(1);
                    begin[0] = val;
                    size++;
                    // std::cout<<"begin==nullptr\n";
                }

                else if(size < maxSize)
                {
                    // std::cout<<"Pushing back: "<<val<<"\n";
                    begin[size] = val;
                    size++;
                    // std::cout<<"size<\n";
                }
                else if (size == maxSize)
                {
                    resize(maxSize + 1);
                    begin[size] = val;
                    size++;
                    // std::cout<<"size==\n";
                }
                else 
                {
                    std::cout<<"push_back error!\n";
                }
            }

            // Method to delete element at the end of the vector 
            void pop_back()
            {
                if(size > 0)
                {
                    std::cout<<"Poping back"<<"\n";
                    size--;
                    begin[size] = 0;
                    std::cout<<"Popped val =  "<<begin[size]<<"\n";
                }
            }

            // Method to create new, bigger vector and copy previous 
            // content into the new one 
            void resize(size_t count)
            {
                if(maxSize != count)
                {
                    maxSize = count;

                    T* new_begin = new T[count];
                    for(size_t i = 0; i < size; i++)
                    {
                        new_begin[i] = begin[i];
                    }

                    if(begin != nullptr) {delete[] begin;}
                    begin = new_begin;
                }
            }

            // Method to get current size of the vector 
            size_t get_size() const
            {
                return size;
            }

            // Destructor of the vector 
            ~vector()
            {
                delete[] begin;
                std::cout<<"cpplab::vector destroyed!\n";
            }

            
        private:
            size_t maxSize; // Max size of vector
            size_t size; // Current size of vector
            T* begin; // Pointer to first element of the vector
            using value_type = T; // Type of vector elements
    };

    template<typename T> 
    // * operator overloading for cpp::vector and std::vector
    T operator*(vector<T>& my_vec, std::vector<T>& standard_vec)
    {
            T product = 0;
            size_t size = 0;

            // Do wprowadzenia error różnych rozmiarow

            size = standard_vec.size();
            for(size_t i = 0; i < size; i++)
            {
                product += my_vec[i] * standard_vec[i];
            }
            return product;
    }

    template<typename T> 
    // * operator overloading for 
    // std::vector and cpp::vector using template defined above
    T operator*(std::vector<T>& standard_vec, vector<T>& my_vec)
    {
        return my_vec * standard_vec;
    }

};


