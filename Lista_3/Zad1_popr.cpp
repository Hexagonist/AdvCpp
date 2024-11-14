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
                if(empty())
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

                    if(begin != nullptr) 
                    {
                        std::cout<<"resize dest\n";
                        delete[] begin;}
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
                std::cout<<"cpplab::vector destroyed!\n";
                delete[] begin;
                // std::cout<<
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
        // if(L_type.size() == R_type.size())
        // {
            auto product = 0;
            size_t size = 0;

            size = R_type.size();
            std::cout<<size<<"\n";
            for(size_t i = 0; i < size; i++)
            {
                product += L_type[i] * R_type[i];
            }
            return product;
            // return 0;
        // }
        // else
        // {
            // throw std::runtime_error("Vectors must be the same size!");
        // }
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


// #include "L3_cpplab.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


int main() 
{
	// try
	// {
	// Testing scalar multiplication
	std::vector<int> standard_vector_ints({2, 3});
	std::vector<int> standard_vector_ints_2({2, 3});
	cpplab::vector<int> cpplab_vec_ints;
	cpplab_vec_ints.push_back(1);
	cpplab_vec_ints.push_back(2);
	// cpplab_vec_ints.push_back(3);

	std::cout<<"\nScalar multiplication of: \n";
	std::cout<<"standard_vector_ints: "<<standard_vector_ints<<"\nand\n";
	std::cout<<"cpplab_vec_ints: "<<cpplab_vec_ints<<"\n";

    std::cout<<standard_vector_ints[0]<<"\n";
    std::cout<<cpplab_vec_ints[0]<<"\n";

	auto result = cpplab_vec_ints * standard_vector_ints;
	// auto result = standard_vector_ints * standard_vector_ints_2;
	// std::cout<<"\nresult of multiplification #1: "<<result<<std::endl;
	
	// auto result_2 = standard_vector_ints * cpplab_vec_ints;
	// std::cout<<"result of multiplification #2: "<<result_2<<std::endl;


	// // Test for floats
	// cpplab::vector<float> cpplab_vec_floats;

	// // Appending new elements to vector
	// cpplab_vec_floats.push_back(1.5f);
	// cpplab_vec_floats.push_back(2.5f);
	// cpplab_vec_floats.push_back(3.8f);
	// std::cout<<"\ncpplab_vec_floats : "<<cpplab_vec_floats<<"\n";
    // auto result_3 = standard_vector_ints * cpplab_vec_floats;
	// std::cout<<"result of multiplification #3: "<<result_3<<std::endl;


	// // Test for chars
	// cpplab::vector<char> cpplab_vec_chars;

	// // Appending new elements to vector
	// cpplab_vec_chars.push_back('a');
	// cpplab_vec_chars.push_back('c');
	// cpplab_vec_chars.push_back('d');
	// std::cout<<"\ncpplab_vec_chars : "<<cpplab_vec_chars<<"\n";
    // auto result_4 = standard_vector_ints * cpplab_vec_chars;
	// std::cout<<"result of multiplification #4: "<<result_4<<std::endl;

	// Test for vector of strings DOES NOT WORK!
	// cpplab::vector<std::string> my_vec_strings;
	// my_vec_strings.push_back("ala");
	// my_vec_strings.push_back("ma");
	// my_vec_strings.push_back("kota");
	// std::cout<<"my_vec_strings : "<<my_vec_strings<<"\n";
    // int result_5 = standard_vector_ints * my_vec_strings;
	// std::cout<<"result of multiplification #5: "<<result_5<<std::endl;

	// Test for strings DOES NOT WORK!
    // std::string str_1 = "abc";
    // std::string str_2 = "cda";
    // auto result_5 = str_1*str_2;
	// std::cout<<"result of multiplification #5: "<<result_5<<std::endl;



	// Exception test
	// std::vector<int>test_vector({99});
	// int result_3 = cpplab_vec_ints * test_vector;
	// std::cout<<"\nresult_3 of multiplification #1: "<<result_3<<std::endl;
	// std::cout<<"\nresult_4 of multiplification #1: "<<my_vec_1<<std::endl;
    
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "Exception: " << e.what() << '\n';
	// }
	// catch(...)
	// {
	// 	std::cout << "Other Exception occured!" << '\n';
	// }


	return 0;
}
