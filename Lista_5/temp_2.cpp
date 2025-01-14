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

    // void insert(Node*& root, T n)
    // {
    //     // Tree is empty
    //     if (root == nullptr)
    //     {
    //         // root = new Node{.left = nullptr, .right = nullptr, .parent = nullptr, .key = n};
    //         root = std::make_unique<Node>(n);
    //         // return root;
    //     }
    //     if (n < root->key)
    //     {
    //         // root->left = std::make_unique<Node>(n);
    //         auto tmp = insert(root->left, n);
    //         if (tmp == root->left)
    //             root->left->parent = root;
    //         // return root->left;
    //     }
    //     // else root->right = std::make_unique<Node>(n);
    //     auto tmp = insert(root->right, n);
    //     if (tmp == root->right)
    //         root->right->parent = root;
    //     // return root->right;    
    // }   

    void insert(T n)
    {
        if(root == nullptr) root = std::make_unique<Node>(n);
        else root->insert(n);
    }

    
    void print_in_order()
    {
        // root->left->print();
        root->print();
        // root->right->print();
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

        void insert(T n)
        {
            if(n < key)
            {
                if(left==nullptr) left = std::make_unique<Node>(n);
                else left->insert(n);
            }
            else 
            {
                if(right==nullptr) right = std::make_unique<Node>(n);
                else right->insert(n);
            }
        }  



        // void insert(Node*& root, T n)
        // {
        //     // Tree is empty
        //     if (root == nullptr)
        //     {
        //         // root = new Node{.left = nullptr, .right = nullptr, .parent = nullptr, .key = n};
        //         root = std::make_unique<Node>(n);
        //         // return root;
        //     }
        //     if (n < root->key)
        //     {
        //         // root->left = std::make_unique<Node>(n);
        //         auto tmp = insert(root->left, n);
        //         if (tmp == root->left)
        //             root->left->parent = root;
        //         // return root->left;
        //     }
        //     // else root->right = std::make_unique<Node>(n);
        //     auto tmp = insert(root->right, n);
        //     if (tmp == root->right)
        //         root->right->parent = root;
        //     // return root->right;    
        // }  




        void print()
        {
            if(left != nullptr) left->print();
            std::cout<<key<<"\n";
            if(right != nullptr) right->print();
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
