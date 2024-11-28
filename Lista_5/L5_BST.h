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
        this->root = std::make_unique<Node>(new_val);
    }

    BST()
    {
        this->root = nullptr;
    }

    void insert(T n)
    {
        if (root == nullptr)
        {
            root = new Node{.left = nullptr, .right = nullptr, .parent = nullptr, .key = n};
            // return root;
        }
        if (n < root->key)
        {
            auto tmp = insert(root->left, n);
            if (tmp == root->left)
                root->left->parent = root;
            // return root->left;
        }
        auto tmp = insert(root->right, n);
        if (tmp == root->right)
            root->right->parent = root;
        // return root->right;    
    }   

    // void reverse()
    // {
    //     if(head->next != nullptr)
    //     {
    //         // Make head Node's next ptr = nullptr (Now it is last element of linked list)
    //         std::unique_ptr<Node> temp = std::move(head);
    //         head = std::move(temp->next);
    //         temp->next = nullptr;

    //         // Then reverse whole list by moving head and 
    //         // changing pointers accordingly until while statement is reached
    //         while(head->next != nullptr)
    //         {
    //             std::unique_ptr<Node> temp_2 = std::move(temp);
    //             temp = std::move(head);
    //             head = std::move(temp->next);
    //             temp->next = std::move(temp_2);
    //         }

    //         // Head is now at the end of previous list
    //         // Change head's next pointer from nullptr to appropriate one
    //         head->next = std::move(temp);
    //     }
    // }

    // void print()
    // {
    //     head->print();
    // }
    
    void print_in_order()
    {
        root->print();
    }

    private:
    struct Node
    {
        T key;
        std::unique_ptr<Node> parent;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(T val)
        {
            this->key = val;
            this->left = nullptr;
            this->right = nullptr;
            // this->next = nullptr;
            // std::cout<<"Node created!\n";
            // std::cout<<"added: "<<val<<"\n";
        }

        void print()
        {
        //     std::cout<<key<<"\t";
        //     if(next != nullptr) next->print();
        }
    };
    
    std::unique_ptr<Node> root;
};