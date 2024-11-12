#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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

template<typename T>
std::vector<T*> as_sorted_view(std::vector<T> &vec)
{
    // Create vector of pointers to elements of original vector
    std::vector<T*> sorted;
    for(size_t i = 0; i<vec.size(); i++)
    {
        sorted.push_back(&vec[i]);
        // std::cout<<&vec[i]<<"\n";
    }

    // Then insertion-sort vector of pointers by values 
    for(size_t i = 1; i < sorted.size(); i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(*sorted[i] < *sorted[j])   
            {
                T* temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
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
