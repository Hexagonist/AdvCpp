#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <utility>
#include <stdexcept>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

// Compute dot product with exception handling
void dot_product(std::vector<double> vec_1, std::vector<double> vec_2, std::promise<double> promise)
{
    try {
        // Check for invalid conditions
        if (vec_1.size() != vec_2.size()) {
            throw std::invalid_argument("Vectors must be of the same size.");
        }
        if (vec_1.empty() || vec_2.empty()) {
            throw std::invalid_argument("Vectors must not be empty.");
        }

        // Compute the dot product
        double product = 0.0;
        for (size_t i = 0; i < vec_1.size(); i++) {
            product += vec_1[i] * vec_2[i];
        }
        promise.set_value(product); // Set the computed product

    } catch (...) {
        // Capture any exception and set it in the promise
        promise.set_exception(std::current_exception());
    }
}

int main()
{
    // Initialize test vectors
    std::vector<double> vec_3;
    for (size_t i = 0; i < 3; i++)
        vec_3.push_back(i);

    std::vector<double> vec_49;
    for (size_t i = 0; i < 49; i++)
        vec_49.push_back(i);

    std::vector<double> vec_0{}; // Empty vector

    std::vector<std::promise<double>> promise_vec;
    std::vector<std::future<double>> future_vec;
    std::vector<std::thread> workers;

    // Launch threads
    for (size_t i = 0; i < 10; i++) { // Test multiple cases
        promise_vec.emplace_back();
        future_vec.emplace_back(promise_vec.back().get_future());

        if (i > 1) { // Valid case: vec_3 vs vec_3
            workers.emplace_back(dot_product, vec_3, vec_3, std::move(promise_vec.back()));
        } else if (i == 0) { // Invalid case: vec_3 vs vec_49
            workers.emplace_back(dot_product, vec_3, vec_49, std::move(promise_vec.back()));
        } else if (i == 1) { // Invalid case: vec_0 (empty)
            workers.emplace_back(dot_product, vec_0, vec_0, std::move(promise_vec.back()));
        }
    }

    // Aggregate results or handle exceptions
    double total_result = 0.0;
    for (auto &future : future_vec) {
        try {
            total_result += future.get(); // Get the result from the future
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << "\n"; // Print error message
        }
    }

    std::cout << "Total Result = " << total_result << "\n";

    // Join threads
    for (auto &thread : workers) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
