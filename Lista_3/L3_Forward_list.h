#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

template<typename T>
class BST
{
    public:
    BST(T new_val)
    {
        this->head = std::make_unique<Node>(new_val);
    }

    BST()
    {
        this->head = nullptr;
    }

    void insertAtHead(T new_val)
    {
        if(this->head != nullptr)
        {
            std::unique_ptr<Node> temp = std::make_unique<Node>(new_val);
            temp->next = std::move(head);
            head = std::move(temp);  
            // std::cout<<"added: "<<new_val<<"\n";
        }
        else this->head = std::make_unique<Node>(new_val);
    }

    void reverse()
    {
        if(head->next != nullptr)
        {
            // Make head Node's next ptr = nullptr (Now it is last element of linked list)
            std::unique_ptr<Node> temp = std::move(head);
            head = std::move(temp->next);
            temp->next = nullptr;

            // Then reverse whole list by moving head and 
            // changing pointers accordingly until while statement is reached
            while(head->next != nullptr)
            {
                std::unique_ptr<Node> temp_2 = std::move(temp);
                temp = std::move(head);
                head = std::move(temp->next);
                temp->next = std::move(temp_2);
            }

            // Head is now at the end of previous list
            // Change head's next pointer from nullptr to appropriate one
            head->next = std::move(temp);
        }
    }

    void print()
    {
        head->print();
    }


    private:
    struct Node
    {
        T value;
        std::unique_ptr<Node> next;
        Node(T val)
        {
            this->value = val;
            this->next = nullptr;
            // std::cout<<"Node created!\n";
            // std::cout<<"added: "<<val<<"\n";
        }

        void print()
        {
            std::cout<<value<<"\t";
            if(next != nullptr) next->print();
        }
    };
    
    std::unique_ptr<Node> head;
};