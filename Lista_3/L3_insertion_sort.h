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

// Only to print std::vector in comfortable way
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (T a : vec)
    {
        os << a << " ";
    }
    return os;
}

template<typename T>
std::vector<T> as_sorted_view(std::vector<T> vector)
{
    std::vector<T> sorted = vector;
    insertion_sort(sorted);
    return sorted;
}