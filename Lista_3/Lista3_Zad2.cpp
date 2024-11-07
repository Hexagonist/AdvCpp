#include <iostream>
// Mateusz Wojcicki ISSP2

struct Link
{
    int value;
    Link *next = nullptr;
};

void release(Link** phead)
{
    Link* head = *phead;
    while (head != nullptr)
    {
        Link* tmp = head;
        head = head->next;
        delete tmp;
    }
    *phead = nullptr;
}

void recursive_release(Link** phead)
{
    Link* head = *phead;
    if(head != nullptr)
    {
        Link* tmp = head;
        head = head->next;
        phead = &head;
        delete tmp;
        recursive_release(phead);
    }
    *phead = nullptr;
}

int main()
{
    // Creating linked list
    Link *third = new Link{.value = 1, .next = nullptr};
    Link *second = new Link{.value = 2, .next = third};
    Link *first = new Link{.value = 3, .next = second};
    Link *head = first;
    Link **phead = &head;
    
    // Function 'release' releases memory allocated to list pointed by phead. 
    // This is why when we trying to cout third->value it prints random number (undefined behaviour) 
    std::cout << "Before: " << third->value << "\n";
    release(phead);
    // To test recursive release please comment release and uncomment section below.    
    // recursive_release(phead);
    std::cout << "After: " << third->value << "\n";
}