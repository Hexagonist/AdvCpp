#include "L4_cpplab.h"

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

// Dlaczego nie używać memcpy?
// Ponieważ memcpy działa w przypadku gdy klasa posiada prymitywne typy danych
// np. int, float. W przypadku obiektów innych klas musimy upewnić się, że zostaną
// wywołane odpowiednie kostruktory tych klas - dlatego używamy std::move.

struct pixel
{
    int r;
    int g;
    int b;

    // default constructor
    pixel() : r(0), g(0), b(0)
    {
        // std::cout<<"pixel constructed by default!\n"; 
    }

    // move constructor
    pixel(int &&r, int &&g, int &&b) noexcept : r(std::move(r)), g(std::move(g)), b(std::move(b)) 
    {
        // std::cout<<"pixel constructed by move!\n";
    }

    ~pixel() 
    {
        // std::cout<<"pixel destroyed!\n";
    }
};

// << overload for pixel struct
std::ostream& operator<<(std::ostream& os, const pixel& pix)
{
    os <<"("<<pix.r<<", "<<pix.g<<", "<<pix.b<<")";   
    return os;
}



int main() 
{
	try
	{
    
    std::cout<<"\nZadanie 1:\n";

	// Test for copy constructor
	cpplab::vector<int> vec_1;
	vec_1.push_back(1);
	vec_1.push_back(2);
	vec_1.push_back(3);

	std::cout<<"vec_1: "<<vec_1;
    cpplab::vector<int> vec_1copy(vec_1);
	std::cout<<"\nvec_1copy: "<<vec_1copy<<"\n";

    // Test for copy operator=
    cpplab::vector<int> vec_3;
	vec_3.push_back(2);
	vec_3.push_back(3);
    vec_3.push_back(4);
	std::cout<<"\nvec_3: "<<vec_3;
    vec_3 = vec_1;
	std::cout<<"\nvec_3 after vec_3=vec_1: "<<vec_3<<"\n";

    // Test for move constructor
    cpplab::vector<int> vec_4;
	vec_4.push_back(5);
	vec_4.push_back(6);
    vec_4.push_back(7);
	std::cout<<"\nvec_4: "<<vec_4;
    cpplab::vector<int> vec_4dest(std::move(vec_4));
	std::cout<<"\nvec_4: "<<vec_4;
	std::cout<<"\nvec_4dest: "<<vec_4dest<<"\n";


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

    std::cout<<"\n\nDlaczego nie używać memcpy?\n";
    std::cout<<"Ponieważ memcpy działa w przypadku gdy klasa posiada prymitywne typy danych\n";
    std::cout<<"np. int, float. W przypadku obiektów innych klas musimy upewnić się, że zostaną\n";
    std::cout<<"wywołane odpowiednie kostruktory tych klas - dlatego używamy std::move.\n";


    // Zadanie 2
    std::cout<<"\nZadanie 2:\n";
    cpplab::vector<pixel> vec_pixels;
	vec_pixels.push_back(pixel(1, 2, 3));
	vec_pixels.push_back(pixel(2, 3, 4));
	vec_pixels.push_back(pixel(3, 4, 5));
	std::cout<<"vec_pixels before: "<<vec_pixels<<"\n";


    vec_pixels.emplace_back(1, 2, 3);
	std::cout<<"vec_pixels after: "<<vec_pixels<<"\n";
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
