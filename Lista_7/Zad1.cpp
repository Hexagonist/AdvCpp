#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <utility>

#include "L6_thread_pool.h"

void dot_product(std::vector<double>& vec_1, std::vector<double>& vec_2, std::promise<double> promise)
{
    if(vec_1.size() != vec_2.size()) std::cout<<"throwuje\n";//throw ale set value
    else
    {
        double product = 0.0;
        for (size_t i = 0; i < vec_1.size(); i++)
        {
            product += vec_1[i] * vec_2[i];
        }
        promise.set_value(product);
    }
}


int main()
{
    std::vector<double> vec_3;
    for (size_t i = 0; i < 3; i++)
        vec_3.push_back(i);
    
    std::vector<double> vec_49;
    for (size_t i = 0; i < 49; i++)
        vec_49.push_back(i);

    std::vector<double> vec_0{};

    std::promise<double> promise_1;
    std::future<double> future_1 = promise_1.get_future();

    dot_product(vec_3, vec_3, std::move(promise_1));

    std::cout<<"Wynik = "<<future_1.get()<<"\n";






    return 0;
}