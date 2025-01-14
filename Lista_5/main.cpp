#include "L5_BST.h"
#include "L5_unique_and_non0_ptr.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


// Function to solve the Dratewka problem and retrieve selected treasures
std::pair<int, std::vector<int>> dratewka(int W, const std::vector<int>& weights, const std::vector<int>& prices) {
    int N = weights.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + prices[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find the selected treasures
    std::vector<int> selected;
    int w = W;
    for (int i = N; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i - 1); // Treasure index
            w -= weights[i - 1];
        }
    }
    reverse(selected.begin(), selected.end());

    return {dp[N][W], selected};
}


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

    // Nie znalazłem bezpośrednio w concept'ach możliwości "zabronienia" przypisania wartości nullptr.
    // Możemy weryfikować typy danych np. czy jest to pointer, czy operator dereferencji (*) działa an tym typie, 
    // ale żeby zablokować przypisanie nullptr, trzeba sprawdzić wartość w czasie działania programu, a nie w czasie kompilacji, jak to robią koncepty.
    std::cout<<"\nNie znalazłem bezpośrednio w concept'ach możliwości \"zabronienia\" przypisania wartości nullptr.\n";
    std::cout<<"Możemy weryfikować typy danych np. czy jest to pointer, czy operator dereferencji (*) działa an tym typie,\n";
    std::cout<<"ale żeby zablokować przypisanie nullptr, trzeba sprawdzić wartość w czasie działania programu, a nie w czasie kompilacji, jak to robią koncepty.\n\n";


	std::cout<<"\nZadanie 3:\n";

    // Example treasures: weights and prices
    std::vector<int> weights = {1, 1, 2, 3, 3};
    std::vector<int> prices = {2, 1, 3, 7, 6};
    int W = 7;

    auto [max_price, selected] = dratewka(W, weights, prices);


    std::cout << "Treasures available: " << std::endl;
    for(auto i = 0; i < weights.size(); i++)
    {
        std::cout<<"treasure_"<<i<<"("<<weights[i]<<", "<<prices[i]<<")\n";
    }

    // Output results
    std::cout << "Maximum price Dratewka can collect: " << max_price << std::endl;
    std::cout << "Treasures to collect (0-based index): ";
    for (int index : selected) {
        std::cout << index << " ";
    }
    std::cout << std::endl;


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
