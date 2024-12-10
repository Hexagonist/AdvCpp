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

        auto operator->()
        {return *adress;}

        private:
        T* adress;
    };
}



int main() 
{
    std::cout<<"\nZadanie 2:\n";
    std::string str = "I am a string";
    std::string *standard_ptr = &str;

    cpplab::unique_ptr<std::string> str_ptr = cpplab::unique_ptr<std::string>(str);
    std::cout<<str_ptr.get()<<"\n";
    // std::cout<<*str_ptr<<"\n";
    // std::cout<<str_ptr->size()<<"\n";
    std::cout<<standard_ptr->size()<<"\n";

	return 0;
}
