
#pragma once
#include <iostream>
#include <vector>
#include <string>


namespace cpplab{
    template<typename T> 
    class vector
    {
        public:
            // Default constructor without memory allocation
            vector() : maxSize(10), size(0), begin(nullptr)
            {
                // std::cout<<"Obj created!"<<std::endl;
            }

            vector(T&& val)
            {
                begin = new T[maxSize];
                // begin = new T(val);
                maxSize = 10;
                size = 1;
                *begin = val;
                // value_type = typeid(val);
                std::cout<<"*Begin = "<<*begin<<std::endl;
                // std::cout<<"value_type = "<<value_type.name()<<std::endl;
            }

            // [] Operator overloading to acquire element of vector
            T& operator[](int a)
            {
                return begin[a];
            }

            // Method to append new element at the end of the vector 
            void push_back(T&& val)
            {
                // Memory allocation if begin pointer doesn't "exist" yet
                if(begin == nullptr)
                {
                    begin = new T[maxSize];
                    maxSize = 10;
                    size = 0;
                }

                if(size < maxSize)
                {
                    // std::cout<<"Pushing back: "<<val<<"\n";
                    begin[size] = val;
                    size++;
                }
            }

            // Method to delete element at the end of the vector 
            void pop_back()
            {
                if(this->size > 0)
                {
                    std::cout<<"Poping back"<<"\n";
                    size--;
                    begin[size] = 0;
                    std::cout<<"Popped val =  "<<begin[size]<<"\n";

                }
            }

            // Method to get current size of the vector 
            size_t get_size() const
            {
                return this->size;
            }


            // Destructor of the vector 
            ~vector()
            {
                delete[] begin;
                std::cout<<"Obj destroyed!\n";
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


