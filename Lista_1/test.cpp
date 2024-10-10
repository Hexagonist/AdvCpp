
#include <iostream>
#include <vector>

// https://godbolt.org/ dobra strona

int main() {

	int a = 1000;
	std::cout << a <<std::endl;

	int test[] = {1, 2, 3};

	int* ptr = nullptr;
	ptr = new int;

	*ptr = 10;
	std::cout<<"*ptr = "<<*ptr<<std::endl;

	delete ptr;


	// test = {3, 2, 4};
	
	return 0;
}