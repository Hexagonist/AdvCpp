#include <iostream>


constexpr int fac(int n)
{
    int result = 0;
    if(n>2) result = n*fac(n-1);
    else result = n*(n-1);

    return result;
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