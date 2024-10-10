#include "Zad3.h"


int main() 
{
	cpplab::vector<int> test;
	test.push_back(12);
	test.push_back(14);
	std::cout<<test[0]<<"\n"<<test[1]<<"\n"<<test[2]<<std::endl;

	test[0]=11;
	std::cout<<"Modified first el to 11: "<<test[0]<<std::endl;

	test.pop_back();
	std::cout<<test[0]<<"\n"<<test[1]<<"\n"<<test[2]<<std::endl;

	std::cout<<"size = "<< test.get_size()<<std::endl;




	return 0;
}