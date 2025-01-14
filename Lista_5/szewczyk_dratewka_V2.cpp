#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>



std::vector<std::pair<int, int>> choose_best_treasures(const std::vector<std::pair<int, int>> &treasures, const int &W)
{
    // Case 1 - best treasures based on only value
    // Case 2 - best treasures based on value / weight ratio
    // Answer - higher value of chosen treasures

    // Case 1
    std::vector<std::pair<int, int>> case_1;
    case_1.push_back()
}

// Case 1
std::vector<std::pair<int, int>> best_by_value(const std::vector<std::pair<int, int>> &treasures, const int &W)
{
    std::vector<std::pair<int, int>> result;
    
}


int main() 
{
    std::cout<<"\nZadanie 5 (Szewczyk Dratewka):\n";

    const int N = 5, W = 30;

    // treasure(weight, price)
    const std::vector<std::pair<int, int>> treasures 
    ({
    std::pair(5, 100), 
    std::pair(20, 300),
    std::pair(2, 150), 
    std::pair(5, 100), 
    std::pair(5, 100)
    });





    // for(auto x : treasures)
    // {

    // }

    choose_best_treasures(N, treasures);



	return 0;
}
