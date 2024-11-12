#include "Forward_list.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


int main()
{
    Forward_list<int> just_1(1);
    std::cout<<"\nBefore reverse: \n";
    just_1.print();
    just_1.reverse();
    std::cout<<"\nAfter reverse: \n";
    just_1.print();
    std::cout<<std::endl;


    Forward_list<int> five_ints;
    for(int i = 1; i<=5; i++)
    {
        five_ints.insertAtHead(i);
    }
    std::cout<<"\nBefore reverse: \n";
    five_ints.print();
    five_ints.reverse();
    std::cout<<"\nAfter reverse: \n";
    five_ints.print();
    std::cout<<std::endl;


    Forward_list<std::string> five_strings;
    std::vector<std::string> v_test = {"zupa", "kura", "jajo", "arbuz", "babilon"};
    for(auto& x : v_test)
    {
        five_strings.insertAtHead(x);
    }
    std::cout<<"\nBefore reverse: \n";
    five_strings.print();
    five_strings.reverse();
    std::cout<<"\nAfter reverse: \n";
    five_strings.print();
    std::cout<<std::endl;




    return 0;
}