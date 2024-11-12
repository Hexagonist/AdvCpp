#include "L3_cpplab.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


int main() 
{
	try
	{
	// Testing scalar multiplication
	std::vector<int> standard_vector_ints({2, 3, 4});
	cpplab::vector<int> cpplab_vec_ints;
	cpplab_vec_ints.push_back(1);
	cpplab_vec_ints.push_back(2);
	cpplab_vec_ints.push_back(3);

	std::cout<<"\nScalar multiplication of: \n";
	std::cout<<"standard_vector_ints: "<<standard_vector_ints<<"\nand\n";
	std::cout<<"cpplab_vec_ints: "<<cpplab_vec_ints<<"\n";

	auto result = cpplab_vec_ints * standard_vector_ints;
	std::cout<<"\nresult of multiplification #1: "<<result<<std::endl;
	
	auto result_2 = standard_vector_ints * cpplab_vec_ints;
	std::cout<<"result of multiplification #2: "<<result_2<<std::endl;


	// Test for floats
	cpplab::vector<float> cpplab_vec_floats;

	// Appending new elements to vector
	cpplab_vec_floats.push_back(1.5f);
	cpplab_vec_floats.push_back(2.5f);
	cpplab_vec_floats.push_back(3.8f);
	std::cout<<"\ncpplab_vec_floats : "<<cpplab_vec_floats<<"\n";
    auto result_3 = standard_vector_ints * cpplab_vec_floats;
	std::cout<<"result of multiplification #3: "<<result_3<<std::endl;


	// Test for chars
	cpplab::vector<char> cpplab_vec_chars;

	// Appending new elements to vector
	cpplab_vec_chars.push_back('a');
	cpplab_vec_chars.push_back('c');
	cpplab_vec_chars.push_back('d');
	std::cout<<"\ncpplab_vec_chars : "<<cpplab_vec_chars<<"\n";
    auto result_4 = standard_vector_ints * cpplab_vec_chars;
	std::cout<<"result of multiplification #4: "<<result_4<<std::endl;

	// Test for vector of strings DOES NOT WORK!
	// cpplab::vector<std::string> my_vec_strings;
	// my_vec_strings.push_back("ala");
	// my_vec_strings.push_back("ma");
	// my_vec_strings.push_back("kota");
	// std::cout<<"my_vec_strings : "<<my_vec_strings<<"\n";
    // int result_5 = standard_vector_ints * my_vec_strings;
	// std::cout<<"result of multiplification #5: "<<result_5<<std::endl;

	// Test for strings DOES NOT WORK!
    // std::string str_1 = "abc";
    // std::string str_2 = "cda";
    // auto result_5 = str_1*str_2;
	// std::cout<<"result of multiplification #5: "<<result_5<<std::endl;



	// Exception test
	// std::vector<int>test_vector({99});
	// int result_3 = cpplab_vec_ints * test_vector;
	// std::cout<<"\nresult_3 of multiplification #1: "<<result_3<<std::endl;
	// std::cout<<"\nresult_4 of multiplification #1: "<<my_vec_1<<std::endl;
    
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
