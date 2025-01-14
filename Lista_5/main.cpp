#include "L5_BST.h"
#include "L5_unique_and_non0_ptr.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15




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


	std::cout<<"\nZadanie 2:\n";

    {
        std::unique_ptr<pixel> pixel_1 = std::make_unique<pixel>(1, 2, 3);
        std::unique_ptr<pixel> pixel_2(new pixel(3, 2, 1));

        cpplab::unique_ptr<pixel> pixel_22(new pixel(6, 5, 4));

        pixel_1->print();
        pixel_2->print();

        pixel_22->print();
    }

    // Non0_ptr
    pixel pixel_3(8, 9, 0);
    non0_ptr<pixel*> p1(&pixel_3);
    p1->print();

    // Uncommenting the following line will throw an exception
    // non0_ptr<pixel*> p2(nullptr);


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
