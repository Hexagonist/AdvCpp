#include "Zad3.h"

int main()
{
    std::string test = "test";

    print_all(1, 1.0, 1.0f, "Hello", test);
    std::cout<<"\n";

    print_all(1, 2.0);
    std::cout<<"\n";

    print_all(1);

    return 0;
}