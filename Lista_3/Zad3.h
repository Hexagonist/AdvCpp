#include <iostream>
#include <memory>

template<typename T>
class Forward_list
{
    public:
    Forward_list(T new_val)
    {
        next = nullptr;
        this->value = new_val;
        std::cout<<"Node created!\n";

    }

    add(T new_val)
    {
        this->next = std::make_unique<Forward_list>(new_val);
        std::cout<<"added: "<<new_val<<"\n";
    }

    private:
    std::unique_ptr<Forward_list> next;
    T value;
    // T *next = nullptr;
};