#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template<typename T>
auto insertion_sort(std::vector<T>& vec)
{
    for(size_t i = 1; i < vec.size(); i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(vec[i] < vec[j])   
            {
                T temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
	return vec;
}

// Only to print vector in comfortable way
template<typename T>
void print_vector(std::vector<T>& vec)
{
    for (T a : vec)
    {
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
}