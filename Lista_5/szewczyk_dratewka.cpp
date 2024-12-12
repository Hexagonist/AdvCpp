#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>



bool comp(std::pair<unsigned int, float> a, std::pair<unsigned int, float> b) {
    return a.second >= b.second;
}



    // const unsigned int &treasures_amount,
std::vector<std::pair<unsigned int, unsigned int>> choose_best_treasures(
    const unsigned int &max_weight,
    const std::vector<std::pair<unsigned int, unsigned int>> &treasures)
{
    std::vector<std::pair<unsigned int, unsigned int>> result;
    std::vector<std::pair<unsigned int, float>> temp; //vector of <iterator, price/kg>

    for(size_t i = 0; i < treasures.size(); i++)
    {
        // Oblicza cena / kg i dodaje najlepsze do resulta
        temp.push_back(std::pair(i, static_cast<float>(treasures[i].second)/treasures[i].first));
    }

    // Picking most valuable treasures
    // while(current_weight <= max_weight)
    // {
    //     if()
    // }
    std::cout<<temp[0].first;


    for(size_t i = 0; i < temp.size(); i++)
    {
        std::cout<<temp[i].first<<"   "<<temp[i].second<<"\n";
    }
    std::cout<<"\n";

    std::sort(temp.begin(), temp.end(), comp);
    
    for(size_t i = 0; i < temp.size(); i++)
    {
        std::cout<<temp[i].first<<"   "<<temp[i].second<<"\n";
    }

    // wybieraj najabrdziej opłacalne elementy
    unsigned int current_weight = 0;
    for(size_t i = 0; i < temp.size(); i++)
    {
        if((current_weight+treasures[temp[i].first].second)<=max_weight);
    }


    return treasures;
}



int main() 
{
    std::cout<<"\nZadanie 5 (Szewczyk Dratewka):\n";

    const unsigned int N = 5, W = 30;

    // treasure(weight, price)
    const std::vector<std::pair<unsigned int, unsigned int>> treasures 
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
