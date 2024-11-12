#include <iostream>
#include <memory>

template<typename T>
class Forward_list
{
    public:
    Forward_list(T new_val)
    {
        this->head = std::make_unique<Node>(new_val);
    }

    // Forward_list()
    // {
    //     this->next = nullptr;
    //     std::cout<<"Node created!\n";
    // }

    void insertAtHead(T new_val)
    {
        std::unique_ptr<Node> temp = std::make_unique<Node>(new_val);
        temp->next = std::move(head);
        head = std::move(temp);  
        // std::cout<<"added: "<<new_val<<"\n";
    }

    void reverse()
    {
        std::unique_ptr<Node> temp = std::move(head);
        head = std::move(temp->next);
        temp->next = nullptr;
        std::unique_ptr<Node> temp_2;
        while(head->next != nullptr)
        {
            temp_2 = std::move(temp);
            temp = std::move(head);
            head = std::move(temp->next);
            temp->next = std::move(temp_2);
        }
        head->next = std::move(temp);
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
            std::cout<<"Node created!\n";
            std::cout<<"added: "<<val<<"\n";
        }

        void print()
        {
            std::cout<<value<<"\t";
            if(next != nullptr) next->print();
        }
    };
    
    // std::unique_ptr<Forward_list> next;
    // T value;
    std::unique_ptr<Node> head;
    
    // T *next = nullptr;
};