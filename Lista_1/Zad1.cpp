#include "Zad1.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main() {

	std::cout << "Lista 1 Zadanie 1:\n";

	// Lambda expression as comperator to my_max
	auto lambda = [](auto a, auto b){ return a < b ? b : a;};

	int a = 100, b = 200;
	std::cout << my_max(a, b, lambda) << std::endl;

	a = 200, b = 100;
	std::cout << my_max(a, b, lambda) << std::endl;

	a = -200, b = -100;
	std::cout << my_max(a, b, lambda) << std::endl;
	
	char ch1 = 'a', ch2 = 'z'; // a char value is 97 and z char value is 122
	std::cout << my_max(ch1, ch2, lambda) << std::endl;

	float f1 = 1.22f, f2 = 9.99f;
	float test = my_max(f1, f2, lambda);
	printf( "%6.*lf", 4, test);

	return 0;
}