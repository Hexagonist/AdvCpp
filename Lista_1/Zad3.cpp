#include "Zad3.h"


int main() 
{
	// cpplab::vector<int> test;
	// test.push_back(12);
	// test.push_back(14);
	// std::cout<<test[0]<<"\n"<<test[1]<<"\n"<<test[2]<<std::endl;

	// test[0]=11;
	// std::cout<<"Modified first el to 11: "<<test[0]<<std::endl;

	// test.pop_back();
	// std::cout<<test[0]<<"\n"<<test[1]<<"\n"<<test[2]<<std::endl;

	// std::cout<<"size = "<< test.get_size()<<std::endl;

	std::vector<int> standard_vector({2, 3, 4});

	for(auto i = 0; i < standard_vector.size(); i++)
	{
		std::cout<<"standard vector ["<<i<<"] : "<<standard_vector[i]<<std::endl;
	}


	cpplab::vector<int> my_vec;
	my_vec.push_back(1);
	my_vec.push_back(2);
	my_vec.push_back(3);

	std::cout<<my_vec.get_size()<<std::endl;
	for(size_t i = 0; i < my_vec.get_size(); i++)
	{
		std::cout<<"my_vec["<<i<<"] : "<<my_vec[i]<<std::endl;
	}

	int result = my_vec * standard_vector;
	std::cout<<"result of multiplification: "<<result<<std::endl;
	
	int result_2 = standard_vector * my_vec;
	std::cout<<"result of multiplification #2: "<<result_2<<std::endl;

	my_vec[0] = 99;
	std::cout<<my_vec[0]<<std::endl;




	return 0;
}