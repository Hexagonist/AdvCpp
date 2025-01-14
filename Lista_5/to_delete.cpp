#include <iostream>
#include <vector>

int main()
{
    std::vector<std::pair<int, int>> test({std::pair<int, int>(1, 11), std::pair<int, int>(3, 33), std::pair<int, int>(2, 22)});
    std::cout<<test[0].first;



    return 0;     
}