#include "Zad3.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

int main() 
{
	cpplab::vector<int> my_vec_1;

	// Appending new elements to vector
	my_vec_1.push_back(12);
	my_vec_1.push_back(14);
	my_vec_1.push_back(16);
	std::cout<<"my_vec_1 : "<<my_vec_1<<"\n";

	// Last element deleted
	my_vec_1.pop_back();
	std::cout<<"my_vec_1 after last element deleted : "<<my_vec_1<<"\n";

	// First element modified to 11
	my_vec_1[0]=11;
	std::cout<<"my_vec_1 after change of first : "<<my_vec_1<<"\n";



	// Testing scalar multiplication
	std::vector<int> standard_vector({2, 3, 4});
	cpplab::vector<int> my_vec_2;
	my_vec_2.push_back(1);
	my_vec_2.push_back(2);
	my_vec_2.push_back(3);

	std::cout<<"\nScalar multiplication of: \n";
	std::cout<<"Standard vector: "<<standard_vector<<"\nand\n";
	std::cout<<"Cpplab vector: "<<my_vec_2<<"\n";

	int result = my_vec_2 * standard_vector;
	std::cout<<"\nresult of multiplification #1: "<<result<<std::endl;
	
	int result_2 = standard_vector * my_vec_2;
	std::cout<<"result of multiplification #2: "<<result_2<<std::endl;


	// Test for floats
	cpplab::vector<float> my_vec_floats;

	// Appending new elements to vector
	my_vec_floats.push_back(1.5f);
	my_vec_floats.push_back(2.5f);
	my_vec_floats.push_back(3.8f);
	std::cout<<"\nmy_vec_floats : "<<my_vec_floats<<"\n";

	// Test for chars
	cpplab::vector<char> my_vec_chars;

	// Appending new elements to vector
	my_vec_chars.push_back('a');
	my_vec_chars.push_back('c');
	my_vec_chars.push_back('d');
	std::cout<<"my_vec_chars : "<<my_vec_chars<<"\n";

	// Test for strings
	cpplab::vector<std::string> my_vec_strings;
	my_vec_strings.push_back("ala");
	my_vec_strings.push_back("ma");
	my_vec_strings.push_back("kota");
	std::cout<<"my_vec_strings : "<<my_vec_strings<<"\n";


	return 0;
}