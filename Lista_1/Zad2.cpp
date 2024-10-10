#include "Zad2.h"

int main() {

	std::cout << "test\n";

    std::vector<int> vec1({2, 4, 3, 4, 2, 1});

    for (auto a : vec1)
    {
        std::cout<<a<<std::endl;
    }

    std::cout<<std::endl;
    insertion_sort(vec1);

    for (auto a : vec1)
    {
        std::cout<<a<<std::endl;
    }
	return 0;
}