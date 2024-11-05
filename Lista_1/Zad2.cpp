#include "Zad2.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


int main() {

	std::cout << "Lista 1 Zad 2:\n";

    // Testing ints
    std::vector<int> vec1({2, 4, 3, 4, 2, 1});
    std::cout<<"\nvector_1 before sorting: ";
    print_vector(vec1);

    insertion_sort(vec1);
    std::cout<<"vector_1 after insertion sort: ";
    print_vector(vec1);


    // Floats test
    std::vector<float> vec2({1.3f, 0.3f, 4.5f, 0.3f, 34.6f});
    std::cout<<"\nvector_2 before sorting: ";
    print_vector(vec2);

    insertion_sort(vec2);
    std::cout<<"vector_2 after insertion sort: ";
    print_vector(vec2);


    // Chars test
    std::vector<char> vec3({'b', 'c', 'a', 'b', 'd'});
    std::cout<<"\nvector_3 before sorting: ";
    print_vector(vec3);

    insertion_sort(vec3);
    std::cout<<"vector_3 after insertion sort: ";
    print_vector(vec3);

    // Odpowiedź do Zadania 2:
    // Złożoność algorytmu insertion sort dla najgorszego przypadku
    // wynosi O(n^2), ale dla już posortowanych elementów
    // złożoność wynosi O(n).

	return 0;
}