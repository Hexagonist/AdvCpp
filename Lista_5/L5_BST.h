#pragma once
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
        if(root) root->insert(n);
        else root = std::make_unique<Node>(n);
    }

    void print_in_order()
    {
        root->print();
    }

    private:
    struct Node
    {
        T key;
        std::shared_ptr<Node> parent;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(T val)
        {
            this->key = val;
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        void insert(T n)
        {
            if(n < key)
            {
                if(left) left->insert(n);
                else left = std::make_unique<Node>(n);
            }
            else 
            {
                if(right) right->insert(n);
                else right = std::make_unique<Node>(n);
            }
        }  

        void print()
        {
            if(left) left->print();
            std::cout<<key<<"   ";
            if(right) right->print();
        }
    };
    std::unique_ptr<Node> root;
};