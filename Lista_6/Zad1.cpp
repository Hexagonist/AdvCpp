#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <random>
#include <functional>

// Funkcja generująca losowe liczby
std::vector<int> generateRandomVector(size_t size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&]() { return dis(gen); });
    return vec;
}

// Funkcja do sortowania części wektora
void sortPartial(std::vector<int>& vec, size_t start, size_t end) {
    std::sort(vec.begin() + start, vec.begin() + end);
}

int main() {
    const size_t vectorSize = 1000;
    auto vec = generateRandomVector(vectorSize, 0, 10000);

    // Wyświetlenie początkowego stanu wektora
    std::cout << "Original vector (first 20 elements): ";
    for (size_t i = 0; i < 20; ++i) std::cout << vec[i] << " ";
    std::cout << "\n";

    // Sortowanie w dwóch wątkach
    size_t mid = vectorSize / 2;
    std::thread t1(sortPartial, std::ref(vec), 0, mid);
    std::thread t2(sortPartial, std::ref(vec), mid, vectorSize);

    // Czekanie na zakończenie wątków
    t1.join();
    t2.join();

    // Wyświetlenie stanu po sortowaniu w dwóch częściach
    std::cout << "Partially sorted vector (first 20 elements): ";
    for (size_t i = 0; i < 20; ++i) std::cout << vec[i] << " ";
    std::cout << "\n";

    // Uwaga: Wektor nie jest w pełni posortowany!
    std::cout << "Is vector fully sorted? "
              << std::is_sorted(vec.begin(), vec.end()) << "\n";

    // Scalanie dwóch posortowanych połówek (aby wektor był w pełni posortowany)
    std::inplace_merge(vec.begin(), vec.begin() + mid, vec.end());

    // Wyświetlenie pełnego posortowanego wektora
    std::cout << "Fully sorted vector (first 20 elements): ";
    for (size_t i = 0; i < 20; ++i) std::cout << vec[i] << " ";
    std::cout << "\n";

    std::cout << "Is vector fully sorted after merging? "
              << std::is_sorted(vec.begin(), vec.end()) << "\n";

    return 0;
}
