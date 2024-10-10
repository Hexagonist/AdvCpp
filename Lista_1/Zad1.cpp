#include "Zad1.h"

// https://godbolt.org/ dobra strona

int main() {

	std::cout << "test\n";

	auto lambda = [](int a, int c){ return a < c ? c : a;};

	int a = 100, c = 200;
	std::cout << my_max(a, c, lambda) << std::endl;

	a = 200, c = 100;
	std::cout << my_max(a, c, lambda) << std::endl;
	
	char ch1 = 'a', ch2 = 'z'; // a char value is 97 and z char value is 122
	std::cout << my_max(ch1, ch2, lambda) << std::endl;

	// std::string str1 = "ala", str2 = "oko";
	// std::cout << my_max(str1, str2, lambda) << std::endl;

	float f1 = 1.22, f2 = 9.99;
	std::cout << my_max(f1, f2, lambda) << std::endl;



	// std::cout << my_max(a, c, [](int a, int c){ return c;}) << std::endl;


	// std::cout<< [](int a, int c){ return a < c ? a : c;};

	// std::cout<< [=](int a, int c){ return c;};
	
	// f<double>(1); // instantiates and calls f<double>(double)
    // f<>('a');     // instantiates and calls f<char>(char)
    // f(7);         // instantiates and calls f<int>(int)
    // void (*pf)(std::string) = f; // instantiates f<string>(string)
    // pf("∇");

	return 0;
}