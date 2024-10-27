#include "L2_insertion_sort.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main()
{
    // Already sorted vector
    std::vector<std::string> vec_str_1({"a", "ab1c", "ab10", "ab15", "ab20c", 
    "ab20c1", "ab20c15", "ab100", "ab303c", "b"});

    // Unsorted vec_str_1
    std::vector<std::string> vec_str_2 = {"ab1c","ab20c1","ab20c","ab10", "ab20c15",
    "ab303c","ab15","ab100","b","a"};


    std::cout<<"\nvec1: \n";
    print_vector(vec_str_1);
    insertion_sort(vec_str_1);
    print_vector(vec_str_1);

    std::cout<<"\nvec2: \n";
    print_vector(vec_str_2);
    insertion_sort(vec_str_2);
    print_vector(vec_str_2);

    return 0;
}