#include <iostream>
#include <memory>
#include <string>
#include <vector>

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
            std::cout<<key<<"\n";
            if(right) right->print();
        //     if(next != nullptr) next->print();
        }
    };
    std::unique_ptr<Node> root;
};



int main() 
{
	try
	{
    
    std::cout<<"\nZadanie 1:\n";

    BST<int> tree_1;
    tree_1.insert(8);
    tree_1.insert(3);
    tree_1.insert(6);
    tree_1.insert(10);
    tree_1.insert(4);
    tree_1.insert(10);
    tree_1.insert(1);
    tree_1.insert(7);
    tree_1.insert(2);
    tree_1.insert(9);
    tree_1.insert(5);

    tree_1.print_in_order();

	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	catch(...)
	{
		std::cout << "Other Exception occured!" << '\n';
	}
	return 0;
}
