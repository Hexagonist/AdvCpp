#include "Zad3.h"

int main()
{
    Forward_list<int> first_list(1);
    first_list.insertAtHead(2);
    first_list.insertAtHead(3);
    first_list.insertAtHead(4);
    first_list.insertAtHead(5);
    // first_list.add(2);
    // first_list.add(3);
    
    // first_list.get_next();

    std::cout<<"\nBefore reverse: \n";
    first_list.print();
    first_list.reverse();
    std::cout<<"\nAfter reverse: \n";
    first_list.print();




    return 0;
}