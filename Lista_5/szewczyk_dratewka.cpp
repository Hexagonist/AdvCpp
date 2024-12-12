#include <iostream>
#include <memory>
#include <string>
#include <vector>



int main() 
{
    std::cout<<"\nZadanie 2:\n";
    std::string str = "I am a string";
    // std::unique_ptr<std::string> standard_ptr = std::make_unique(str);
    std::string  *standard_ptr = &str;

    std::cout<<standard_ptr->size()<<"\n";



	return 0;
}
