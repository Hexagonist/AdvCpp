#include "L4_cpplab.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15


int main() 
{
	try
	{
	// Test for copy constructor
	cpplab::vector<int> vec_1;
	vec_1.push_back(1);
	vec_1.push_back(2);
	vec_1.push_back(3);

	std::cout<<"vec_1: "<<vec_1;
    cpplab::vector<int> vec_2(vec_1);
	std::cout<<"\nvec_2: "<<vec_2;

    // Test for copy operator=
    cpplab::vector<int> vec_3;
	vec_3.push_back(2);
	vec_3.push_back(3);
    vec_3.push_back(4);
	std::cout<<"\n\nvec_3: "<<vec_3;
    vec_3 = vec_1;
	std::cout<<"\nvec_3 after operator=: "<<vec_3;

    // Test for move constructor
    cpplab::vector<int> vec_4;
	vec_4.push_back(5);
	vec_4.push_back(6);
    vec_4.push_back(7);
	std::cout<<"\n\nvec_4: "<<vec_4;
    cpplab::vector<int> vec_5(std::move(vec_4));
	std::cout<<"\nvec_5: "<<vec_5;

    // Test for move operator=
    cpplab::vector<int> vec_6;
	vec_6.push_back(5);
	vec_6.push_back(6);
    vec_6.push_back(7);
    cpplab::vector<int> vec_7;
	std::cout<<"\n\nBefore move: ";
	std::cout<<"\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;
    vec_7 = std::move(vec_6);
	std::cout<<"\nAfter move: ";
	std::cout<<"\nvec_6: "<<vec_6;
	std::cout<<"\nvec_7: "<<vec_7;
    std::cout<<"\n";
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