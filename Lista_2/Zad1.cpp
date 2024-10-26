#include "L2_insertion_sort.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main()
{
    std::vector<std::string> vec_str({"ada", "basia", "celina", "2", "11", "1"});
    std::vector<std::string> vec_str_2({"2", "11", "1"});

    print_vector(vec_str_2);
    insertion_sort(vec_str_2);
    print_vector(vec_str_2);

    std::string str1 = "1abc";
    std::cout<<str1[0];

    return 0;
}