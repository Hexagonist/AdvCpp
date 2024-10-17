#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template<typename T>
void insertion_sort(std::vector<T>& vec)
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
}

template<>
void insertion_sort<std::string>(std::vector<std::string>& vec_str)
{
    for(size_t i = 1; i < vec_str.size(); i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(vec_str[i] < vec_str[j])   
            {
                T temp = vec_str[i];
                vec_str[i] = vec_str[j];
                vec_str[j] = temp;
            }
        }
    }
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