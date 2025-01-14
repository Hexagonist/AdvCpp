#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace cpplab{
    template<typename T>
    class unique_ptr
    {
        using value_type = T;

        public:
        constexpr void reset()
        {
            delete data;
            data = nullptr;
        }

        constexpr unique_ptr() = default;
        // unique_ptr(T value) : adress(&value) {}
        constexpr unique_ptr(T* data_) : data(data_) {}

        // Move 
        constexpr unique_ptr(unique_ptr &&other) : data(std::exchange(other.data, nullptr)) {}
        constexpr unique_ptr &operator=(unique_ptr &&other)
        {
            if(data)    {reset();}
            data = std::exchange(other.data, nullptr);
        }

        // copy operations deleted
        unique_ptr(const unique_ptr &) = delete;
        unique_ptr &operator=(const unique_ptr &) = delete; 

        

        T* get() const 
        {return data;}

        T operator*() const
        {return *data;}

        T* operator->() const
        {return data;}

        constexpr ~unique_ptr()   {reset();}

        private:
        T* data;
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
        std::cout<<"pixel constructed by default!\n"; 
    }

    // move constructor
    pixel(int &&r, int &&g, int &&b) noexcept : r(std::move(r)), g(std::move(g)), b(std::move(b)) 
    {
        std::cout<<"pixel constructed by move!\n";
    }

    void print()
    {
        std::cout<<r<<" "<<g<<" "<<b<<"\n";
    }

    ~pixel() 
    {
        std::cout<<"pixel destroyed!\n";
    }
};

int main() 
{
    std::cout<<"\nZadanie 2:\n";
    // std::string str = "I am a string";
    // std::unique_ptr<std::string> standard_ptr = std::make_unique(str);
    // std::string  *standard_ptr = &str;

    // cpplab::unique_ptr<std::string> str_ptr = cpplab::unique_ptr<std::string>(str);
    // std::cout<<str_ptr.get()<<"\n";
    // std::cout<<*str_ptr<<"\n";
    // std::cout<<str_ptr->size()<<"\n";
    // std::cout<<standard_ptr->size()<<"\n";
    





    // // int a = 5;
    // cpplab::unique_ptr<int> my_unique_1(new int(5));
    // std::cout<<my_unique_1.get()<<"\n"<<*my_unique_1<<"\n";


    // int *test = new int(8);
    // cpplab::unique_ptr<int> my_unique_2(std::move(test));
    // std::cout<<"\nmy_unique_2 = "<<my_unique_2.get()<<"\n"<<*my_unique_2<<"\n";
    // std::cout<<"*test = "<<test<<"\n"<<*test<<"\n";


    // pixel *test_pixel = new pixel(1, 2, 3); 
    // std::cout<<test_pixel->r<<"  "<<test_pixel->g<<"  "<<test_pixel->b<<"\n";

    // cpplab::unique_ptr<pixel> my_unique_pixel(test_pixel);

    // std::cout<<test_pixel->r<<"  "<<test_pixel->g<<"  "<<test_pixel->b<<"\n";
    // std::cout<<my_unique_pixel->r<<"  "<<my_unique_pixel->g<<"  "<<my_unique_pixel->b<<"\n";
    // std::cout<<"unique: "<<my_unique_pixel.get()<<"\n"<<"standard_ptr: "<<test_pixel<<"\n";


    // int *temp  = new int(7);
    // std::unique_ptr<int> standard_unique(std::move(temp));
    // delete temp;
    // int *temp_2 = standard_unique.get();

    // std::cout<<temp<<"\n"<<standard_unique<<"\n"<<temp_2<<"\n";

    // int *temp_3 = new int(9);
    // // std::unique_ptr<int> standard_unique_proper = std::make_unique(temp_3);


    /////////////////////////////////////////////////////////////

    {
        std::unique_ptr<pixel> pixel_1 = std::make_unique<pixel>(1, 2, 3);
        std::unique_ptr<pixel> pixel_2(new pixel(3, 2, 1));

        // cpplab::unique_ptr<pixel> pixel_11 = std::make_unique<pixel>(4, 5, 6);
        cpplab::unique_ptr<pixel> pixel_22(new pixel(6, 5, 4));


        pixel_1->print();

        pixel_22->print();
    }

    // pixel_1->print();

    // pixel_22->print();


	return 0;
}
