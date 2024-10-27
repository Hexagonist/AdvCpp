#include "Zad2.h"




// constexpr unsigned int fac(int n)
// {
//     return n <= 1 ? 1 : (n * fac(n - 1));
// }



int main()
{
//     const unsigned int test = 4;
//     constexpr unsigned int fac_4 = fac(test);
//     constexpr unsigned int fac_5 = fac(5);
    

    // std::cout<<"4! = "<<fac_4<<"\n";
    // std::cout<<"5! = "<<fac_5<<"\n";

    constexpr int test = Factorial<4>().get_value();

    std::cout<<"4! = "<<test<<"\n";



    return 0;
}