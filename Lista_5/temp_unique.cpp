#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace cpplab{
    template<typename T>
    class unique_ptr
    {
        using value_type = T;

        public:
        unique_ptr() : adress(nullptr) {}
        unique_ptr(T value) : adress(&value) {}

        T* get() const 
        {return adress;}

        T operator*() const
        {return *adress;}

        T* operator->() const
        {return adress;}

        // ~unique_ptr()
        // {
        //     // delete adress;
        // }

        private:
        T* adress;
    };
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
        std::cout<<"pixel destroyed!\n";
    }
};

int main() 
{
    std::cout<<"\nZadanie 2:\n";
    std::string str = "I am a string";
    // std::unique_ptr<std::string> standard_ptr = std::make_unique(str);
    std::string  *standard_ptr = &str;

    cpplab::unique_ptr<std::string> str_ptr = cpplab::unique_ptr<std::string>(str);
    std::cout<<str_ptr.get()<<"\n";
    std::cout<<*str_ptr<<"\n";
    std::cout<<str_ptr->size()<<"\n";
    std::cout<<standard_ptr->size()<<"\n";



	return 0;
}
