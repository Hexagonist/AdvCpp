#pragma once
#include <iostream>
#include <algorithm>
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
    auto comparator = [](std::string str1, std::string str2)
    {
        size_t lenght;
        // length = length of shorter string
        str1.size() > str2.size() ? lenght = str2.size() : lenght = str1.size(); 
        std::cout<<"len = "<<lenght<<"\n";
        
        
        bool result = false;
        for(size_t i = 0; i <= lenght-1; i++)
        {
            unsigned int i_first = 0;
            unsigned int i_second = 0;

            std::cout<<"String 1: "<<str1[i]<<" "<<"String 2: "<<str2[i]<<"\n";

            if(std::isdigit(str1[i]) && std::isdigit(str2[i]))
            {
                std::cout<<"Liczby\n";

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


                std::cout<<"Liczba 1: "<<i_first<<" "<<"Liczba 2: "<<i_second<<"\n";
                result = i_first > i_second;
                i = lenght;
            }
            else if(str1[i] != str2[i])
            {
                // std::cout<<"Chary\n";

                // std::cout<<"String 1: "<<str1[i]<<" "<<"String 2: "<<str2[i]<<"\n";
                // Zwraca tru albo false w zależności od porównywanych charów
                result = str1[i] > str2[i];
                i = lenght;
            }
            else if(str1.size() != str2.size() && i==(lenght-1))
            {
                // std::cout<<"Size\n";
                result = str1.size() > str2.size();
                i = lenght;
            }
            else
            {
                // std::cout<<"Not matched!\n";
                // result = str1.size() > str2.size();
                // i = lenght;
            }
            // std::cout<<"result = "<<result<<"\n";
        }
        return result;
    };



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



// template<>
// void insertion_sort<std::string>(std::vector<std::string>& vec_str)
// {
//     std::cout<<"Dziala\n";
//     for(size_t i = 1; i < vec_str.size(); i++)
//     {
//         for(size_t j = 0; j < i; j++)
//         {
//             /*
//              porównanie dwoch stringow
//              1. wyrzucamy takie same chary w stringach
//              2. jesli sa liczbami to sprawdzmy czy sa samotne
//              SPRAWDZAMY ktorymi sie roznia i porownujemy je
//             */ 

//            // Choose shorter string to compare
//            size_t len = 0;
//            if (vec_str[i].size() <= vec_str[j].size()) len = vec_str[i].size();
//            else len = vec_str[j].size();

//            for(size_t k = 0; k < len; k++)
//            {
            
//            }

//             // if(vec_str[i] < vec_str[j])   
//             // {
//             //     std::string temp = vec_str[i];
//             //     vec_str[i] = vec_str[j];
//             //     vec_str[j] = temp;
//             // }
//         }
//     }
//     // std::cout<<"dziala specyfikacja\n";
// }




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