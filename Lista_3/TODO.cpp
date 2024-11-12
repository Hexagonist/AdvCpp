#include <iostream>
// #include <type_traits>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


/*

To do:

// Wymogi Zad1:
// zeby byly liczbami zawartosci
// size rowne
// byly vectory



*/

int main()
{
    std::vector<int> inty({1, 2, 3});
    std::vector<int*> test_vector;
    for(size_t i = 0; i<inty.size(); i++)
    {
        test_vector.push_back(&inty[i]);
        // std::cout<<&inty[i]<<"\n";
    }

    for (auto x : test_vector)
        std::cout<<*x<<" ";
    std::cout<<"test\n";
}