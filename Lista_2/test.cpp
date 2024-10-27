#include <iostream>


struct test
{
    int value = 10;
};




int main()
{   

    auto struktura = test();

    std::cout<<"test: "<<struktura.value<<"\n";


    return 0;
}