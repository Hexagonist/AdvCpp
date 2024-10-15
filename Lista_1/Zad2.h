#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template<typename T>
auto insertion_sort(std::vector<T>& vec)
{
    for(int i = 1; i < vec.size(); i++)
    {
        for(int j = 0; j < i; j++)
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