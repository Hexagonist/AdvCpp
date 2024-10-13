
#pragma once
#include <iostream>
#include <vector>
#include <string>


namespace cpplab{
    template<typename T> 
    class vector
    {
        public:
            // vector() = default;
            vector() : maxSize(10), size(0), begin(nullptr)
            {
                std::cout<<"Obj created!"<<std::endl;
            }

            vector(T&& val)
            // Dać new i zaalokować od razu do maksymalnego rozmiaru
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


            // vector(T&& other[])
            // {
                
            // }

            T& operator[](int a)
            {
                return begin[a];
            }
            
            // T operator*(std::vector<T> &standard_vec)
            // {
            //     T product = 0;
            //     size_t size = 0;

            //     // Do wprowadzenia error różnych rozmiarow

            //     size = standard_vec.size();
            //     for(size_t i = 0; i < size; i++)
            //     {
            //         product += this->begin[i] * standard_vec[i];
            //     }
            //     return product;
            // }

            void push_back(T&& val)
            {
                if(this->begin == nullptr)
                {
                    begin = new T[maxSize];
                    maxSize = 10;
                    size = 0;
                    // begin = new T(val);
                    // *begin = val;
                    // value_type = typeid(val);
                    // std::cout<<"*Begin = "<<*begin<<std::endl;
                    // std::cout<<"value_type = "<<value_type.name()<<std::endl;
                }

                if(this->size < this->maxSize)
                {
                    std::cout<<"Pushing back: "<<val<<"\n";
                    begin[size] = val;
                    size++;
                    // std::cout<<"  "<<"\n";

                }
            }


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

            size_t get_size() const
            {
                return this->size;
            }



            ~vector()
            {
                delete[] begin;
                std::cout<<"Obj destroyed!\n";
            }

            
        private:
            size_t maxSize;
            size_t size;
            // std::type_info value_type;
            T* begin;
            using value_type = T;
    };

    template<typename T> 
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
    T operator*(std::vector<T>& standard_vec, vector<T>& my_vec)
    {
            return my_vec * standard_vec;
    }

    


};


