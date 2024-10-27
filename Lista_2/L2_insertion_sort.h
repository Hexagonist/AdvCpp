#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    for(size_t i = 1; i < vec.size(); i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(vec[i] < vec[j] && i != j)   
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
    auto comparator = [](std::string& str1, std::string& str2)
    {
        size_t lenght;
        // length = length of shorter string
        str1.size() > str2.size() ? lenght = str2.size() : lenght = str1.size();         
        
        bool result = false;

        // Iterating through every single char in shorter string
        for(size_t i = 0; i <= lenght-1; i++)
        {
            // Both chars are digits - creating ints to compare
            if(std::isdigit(str1[i]) && std::isdigit(str2[i]))
            {
                unsigned int i_first = 0;
                unsigned int i_second = 0;

                int j = 0;
                std::string temp = "";
                while(std::isdigit(str1[i+j]))
                {
                    temp += str1[i+j];
                    j++;
                }
                i_first = std::stoi(temp);

                j = 0;
                temp = "";
                while(std::isdigit(str2[i+j]))
                {
                    temp += str2[i+j];
                    j++;
                }
                i_second = std::stoi(temp);

                result = i_first > i_second;
                if(i_first != i_second) i = lenght; // End for loop
            }
            // Both chars differs - compare as chars
            else if(str1[i] != str2[i])
            {
                result = str1[i] > str2[i];
                i = lenght; // End for loop
            }
            // All chars from shorter string are the same as in second -
            // - check which string is longer
            else if(str1.size() != str2.size() && i==(lenght-1))
            {
                result = str1.size() > str2.size();
                i = lenght; // End for loop
            }
            // Both chars are the same - keep going
            else
            {
                result = false;
            }
        }
        return result;
    };


    // Slightly changed insertion sort from Lista_1
    for(size_t i = 1; i < vec_str.size(); i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(comparator(vec_str[j], vec_str[i]) && i != j)   
            {
                std::string temp = vec_str[i];
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