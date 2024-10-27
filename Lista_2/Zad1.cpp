#include "L2_insertion_sort.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main()
{
    std::vector<std::string> vec_str({"ada", "basia", "celina", "2", "11", "1"});
    std::vector<std::string> vec_str_2({"2", "11", "1"});
    std::vector<std::string> vec_str_3({"a", "ab1c", "ab10", "ab11", "ab20c", 
    "ab20c1", "ab20c10", "ab100", "ab201c", "b"});
    std::vector<std::string> vec_str_4 = {"ab1c","ab10","ab20c","ab20c1",
    "ab20c10","ab201c","ab11","ab100","b","a"};

    std::vector<std::string> vec_str_5 = {"ab1c","a"};
    std::vector<std::string> vec_str_6 = {"ab1c","a", "ab"};

    std::cout<<"\nvec3: \n";
    print_vector(vec_str_3);
    insertion_sort(vec_str_3);
    print_vector(vec_str_3);

    // std::cout<<"\nvec4: \n";
    // print_vector(vec_str_4);
    // insertion_sort(vec_str_4);
    // print_vector(vec_str_4);

    // std::cout<<"\nvec5: \n";
    // print_vector(vec_str_5);
    // insertion_sort(vec_str_5);
    // print_vector(vec_str_5);

    // std::string str1 = "1abc";
    // std::cout<<str1[0];

    return 0;
}