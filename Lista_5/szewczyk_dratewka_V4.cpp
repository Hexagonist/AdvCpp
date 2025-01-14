#include <iostream>
#include <vector>
#include <algorithm>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

// Function to solve the knapsack problem and retrieve selected treasures
std::pair<int, std::vector<int>> knapsack(int W, const std::vector<int>& weights, const std::vector<int>& prices) {
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

// Main function
int main() {
    // Example treasures: weights and prices
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> prices = {60, 100, 120};
    int W = 50;

    auto [max_price, selected] = knapsack(W, weights, prices);


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

    return 0;
}
