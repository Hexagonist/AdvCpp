#include "L3_insertion_sort.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main()
{
    std::vector<std::string> v_test = {"zupa", "kura", "jajo", "arbuz", "babilon"};
    auto v_output = as_sorted_view(v_test);
    for (auto& w : v_output)
        std::cout<<*w<<std::endl;
    std::cout<<std::endl;
    for (auto& v : v_test)
        std::cout<<v<<std::endl;

    return 0;
}