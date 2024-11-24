#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <concepts>


// Dlaczego nie używać memcpy?
// Ponieważ memcpy działa w przypadku gdy klasa posiada prymitywne typy danych
// np. int, float. W przypadku obiektów innych klas musimy upewnić się, że zostaną
// wywołane odpowiednie kostruktory tych klas - dlatego używamy std::move.

namespace cpplab{
    template<typename T> 
    class vector
    {
        using value_type = T; // Type of vector elements
        public:
            // Default constructor without memory allocation
            vector() : maxSize(0), _size(0), begin(nullptr) {}

            // Copy constructor
            vector(const vector<T> &other) : maxSize(other.maxSize), _size(other._size)
            {
                std::cout<<"\nCopied";
                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = other[i];
            }

            // Move constructor
            vector(vector<T> &&other) noexcept : maxSize(std::move(other.maxSize)), _size(std::move(other._size))
            {
                std::cout<<"\nMoved";
                delete[] begin;
                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = std::move(other[i]);

                other._size = 0;
                other.maxSize = 0;
                delete[] other.begin;
            }

            // [] Operator overloading to acquire element of vector
            T& operator[](int a) const
            {
                return begin[a];
            }

            // Method to append new element at the end of the vector 
            void push_back(const T &val)
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
                // std::cout<<"push_back\n";
            }

            template<typename... Args>
            T& emplace_back(Args&&... args)
            {
                // Memory allocation if begin pointer doesn't "exist" yet
                if(empty())
                {
                    resize(1);

                    // Forward created T object to allocated heap memory 
                    // exactly at adress &begin[_size]
                    new(&begin[_size]) T(std::forward<Args>(args)...);
                    // Worse version which creates temp on stack, and then moving 
                    // to memory on heap:
                    // begin[_size] = T(std::forward<Args>(args)...);
                    _size++;
                }
                else if(_size < maxSize)
                {
                    new(&begin[_size]) T(std::forward<Args>(args)...);
                    // begin[_size] = T(std::forward<Args>(args)...);
                    _size++;
                }
                else if (_size == maxSize)
                {
                    resize(maxSize + 1);
                    new(&begin[_size]) T(std::forward<Args>(args)...);
                    // begin[_size] = T(std::forward<Args>(args)...);
                    _size++;
                }
                else 
                {
                    throw std::runtime_error("cpplab::vector emplace_back error!");
                }   
                
                return begin[_size];
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

            // copy operator=
            cpplab::vector<T>& operator=(const cpplab::vector<T> &other)
            {
                std::cout<<"\n=Copied";
                delete[] begin;
                _size = other._size;
                maxSize = other.maxSize;

                begin = new T[maxSize];
                for(size_t i = 0; i < _size; i++) begin[i] = other[i];

                return *this;
            }

            // move operator=
            cpplab::vector<T>& operator=(cpplab::vector<T> &&other) noexcept
            {
                std::cout<<"\n=Moved";
                if(this != &other)
                {
                    delete[] begin;
                    _size = other._size;
                    maxSize = other.maxSize;

                    begin = new T[maxSize];
                    // for(size_t i = 0; i < _size; i++) begin[i] = other[i];
                    begin = std::move(other.begin);

                    other._size = 0;
                    other.maxSize = 0;
                    other.begin = nullptr;
                }
                return *this;
            }

            // Destructor of the vector 
            ~vector()
            {
                _size = 0;
                maxSize = 0;
                delete[] begin;
                std::cout<<"\ncpplab::vector destroyed!";
            }

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



struct pixel
{
    int r;
    int g;
    int b;

    // default constructor
    pixel() : r(0), g(0), b(0)
    {
        // std::cout<<"pixel constructed by default!\n"; 
    }

    // move constructor
    pixel(int &&r, int &&g, int &&b) noexcept : r(std::move(r)), g(std::move(g)), b(std::move(b)) 
    {
        // std::cout<<"pixel constructed by move!\n";
    }

    ~pixel() 
    {
        // std::cout<<"pixel destroyed!\n";
    }
};

// << overload for pixel struct
std::ostream& operator<<(std::ostream& os, const pixel& pix)
{
    os <<"("<<pix.r<<", "<<pix.g<<", "<<pix.b<<")";   
    return os;
}



int main() 
{
	try
	{
    
    std::cout<<"\nZadanie 1:\n";

	// Test for copy constructor
	cpplab::vector<int> vec_1;
	vec_1.push_back(1);
	vec_1.push_back(2);
	vec_1.push_back(3);

	std::cout<<"vec_1: "<<vec_1;
    cpplab::vector<int> vec_1copy(vec_1);
	std::cout<<"\nvec_1copy: "<<vec_1copy<<"\n";

    // Test for copy operator=
    cpplab::vector<int> vec_3;
	vec_3.push_back(2);
	vec_3.push_back(3);
    vec_3.push_back(4);
	std::cout<<"\nvec_3: "<<vec_3;
    vec_3 = vec_1;
	std::cout<<"\nvec_3 after vec_3=vec_1: "<<vec_3<<"\n";

    // Test for move constructor
    cpplab::vector<int> vec_4;
	vec_4.push_back(5);
	vec_4.push_back(6);
    vec_4.push_back(7);
	std::cout<<"\nvec_4: "<<vec_4;
    cpplab::vector<int> vec_4dest(std::move(vec_4));
	std::cout<<"\nvec_4: "<<vec_4;
	std::cout<<"\nvec_4dest: "<<vec_4dest<<"\n";


    // Test for move operator=
    cpplab::vector<int> vec_6;
	vec_6.push_back(5);
	vec_6.push_back(6);
    vec_6.push_back(7);
    cpplab::vector<int> vec_7;
	std::cout<<"\n\nBefore move: ";
	std::cout<<"\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;
    vec_7 = std::move(vec_6);
	std::cout<<"\nAfter move: ";
	std::cout<<"\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;

    std::cout<<"\n\nDlaczego nie używać memcpy?\n";
    std::cout<<"Ponieważ memcpy działa w przypadku gdy klasa posiada prymitywne typy danych\n";
    std::cout<<"np. int, float. W przypadku obiektów innych klas musimy upewnić się, że zostaną\n";
    std::cout<<"wywołane odpowiednie kostruktory tych klas - dlatego używamy std::move.\n";


    // Zadanie 2
    std::cout<<"\nZadanie 2:\n";
    cpplab::vector<pixel> vec_pixels;
	vec_pixels.push_back(pixel(1, 2, 3));
	vec_pixels.push_back(pixel(2, 3, 4));
	vec_pixels.push_back(pixel(3, 4, 5));
	std::cout<<"vec_pixels before: "<<vec_pixels<<"\n";


    vec_pixels.emplace_back(1, 2, 3);
	std::cout<<"vec_pixels after: "<<vec_pixels<<"\n";
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

