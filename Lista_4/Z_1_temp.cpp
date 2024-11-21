#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <concepts>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

// Odpowiedz do zad1 The Cherno vector 15:35
// move assignment operator https://youtu.be/OWNeCTd7yQE?si=tmP63_gxBAEXrfuE&t=650

namespace cpplab{
    template<typename T> 
    class vector
    {
        using value_type = T; // Type of vector elements
        
        private:
            size_t maxSize; // Max size of vector
            size_t _size; // Current size of vector
            T* begin; // Pointer to first element of the vector

        public:
            // Default constructor without memory allocation
            vector() : maxSize(0), _size(0), begin(nullptr) {}

            // Copy constructor
            vector(const vector<T> &other) : maxSize(other.maxSize), _size(other._size)
            {
                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = other[i];
            }

            // Move constructor
            vector(const vector<T> &&other) noexcept : maxSize(std::move(other.maxSize)), _size(std::move(other._size))
            {
                delete[] begin;
                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = std::move(other[i]);
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

            // operator=
            auto operator=(const cpplab::vector<T> &other)
            {
                delete[] begin;
                _size = other._size;
                maxSize = other.maxSize;

                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = other[i];
            }

            // move operator=
            auto operator=(const cpplab::vector<T> &&other) noexcept
            {
                delete[] begin;
                _size = other._size;
                maxSize = other.maxSize;

                begin = new T[maxSize];
                // for(size_t i = 0; i < _size; i++) begin[i] = other[i];
                begin = std::move(other.begin);
            }

            // Destructor of the vector 
            ~vector()
            {
                // std::cout<<"cpplab::vector destroyed!\n";
                delete[] begin;
            }
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





int main() 
{
	try
	{
	// Test for copy constructor
	std::vector<int> standard_vector_ints({2, 3, 4});
	cpplab::vector<int> vec_1;
	vec_1.push_back(1);
	vec_1.push_back(2);
	vec_1.push_back(3);

    cpplab::vector<int> vec_2(vec_1);


	std::cout<<"vec_1: \n"<<vec_1;

	std::cout<<"\nvec_2: \n"<<vec_2;


    // Test for oprator=
    cpplab::vector<int> vec_3;
	vec_3.push_back(2);
	vec_3.push_back(3);
    vec_3.push_back(4);
	std::cout<<"\n\nvec_3: \n"<<vec_3;
    vec_3 = vec_1;
	std::cout<<"\nvec_3 after operator=: \n"<<vec_3;

    // Test for move constructor
    // cpplab::vector<int> vec_4;
	// vec_4.push_back(5);
	// vec_4.push_back(6);
    // vec_4.push_back(7);
    // cpplab::vector<int> vec_5;
	// std::cout<<"\n\nvec_4: \n"<<vec_4;
	// std::cout<<"\nvec_5: \n"<<vec_5;
    // vec_5(std::move(vec_4));
	// std::cout<<"\nvec_4 after: \n"<<vec_4;
	// std::cout<<"\nvec_5 after: \n"<<vec_5;

    // Test for move constructor
    cpplab::vector<int> vec_6;
	vec_6.push_back(5);
	vec_6.push_back(6);
    vec_6.push_back(7);
    cpplab::vector<int> vec_7;
	std::cout<<"\n\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;
    // vec_7 = std::move(vec_6);
	std::cout<<"\n\nAfter: ";
	std::cout<<"\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;



    
    
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	catch(...)
	{
		std::cout << "Other Exception occured!" << '\n';
	}


	return 0;
}

