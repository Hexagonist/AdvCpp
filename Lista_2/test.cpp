#include <iostream>
#include <string>
#include <cmath>

// struct test
// {
//     int value = 10;
// };




int main()
{   

    // auto struktura = test();

    // std::cout<<"test: "<<struktura.value<<"\n";

    auto lambda = [](std::string str1, std::string str2)
    {
        size_t lenght;
        // length = length of shorter string
        str1.size() > str2.size() ? lenght = str2.size() : lenght = str1.size(); 
        std::cout<<"len = "<<lenght<<"\n";
        
        
        for(size_t i = 0; i <= lenght-1; i++)
        {
            unsigned int i_first = 0;
            unsigned int i_second = 0;
            bool found = false;

            if(std::isdigit(str1[i]))
            {
                int j = 0;
                std::string temp = "";
                while(std::isdigit(str1[i+j]))
                {
                    temp += str1[i+j];
                    j++;
                }

                // while(std::isdigit(str1[i+j]))    j++;
                // int k = 0;
                // while(j>0)
                // {
                //     // Converting char to int
                //     // std::cout<<"str1[i+j-1]: "<<str1[i+j-1]<<"\n";
                //     int it = (str1[i+j-1] - '0') * std::pow(10, k);
                //     // std::cout<<"it: "<<it<<"\n";
                //     i_first += it;
                //     j--;
                //     k++;
                // }

                i_first = std::stoi(temp);
                std::cout<<"String 1: "<<i_first<<" "<<"String 2: "<<str2[i]<<"\n";
                i = lenght;
            }
            else if(str1[i] != str2[i])
            {
                std::cout<<"String 1: "<<str1[i]<<" "<<"String 2: "<<str2[i]<<"\n";
                i = lenght;
            }
        }
    };

     
    std::string string1 = "123abc";
    std::string string2 = "15abc"; 
    std::string string3 = "1abc";
    std::string string4 = "10abc";

    lambda(string1, string2);

    return 0;
}