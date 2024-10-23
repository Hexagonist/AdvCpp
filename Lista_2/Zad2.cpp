#include <iostream>


constexpr int fac(int n)
{
    return n <= 1 ? 1 : (n * fac(n - 1));
}


int main()
{
    const int test = 4;
    constexpr int fac_4 = fac(test);
    constexpr int fac_5 = fac(5);
    

    std::cout<<"4! = "<<fac_4<<"\n";
    std::cout<<"5! = "<<fac_5<<"\n";
    return 0;
}