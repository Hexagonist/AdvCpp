#include "mymath.h"
#include <iostream>
using namespace std;

// rozwiazanie listy w folderze wyslij i test_z_...._2 w Zad2.cpp komentarz

int main()
{
    int a = 10;
    int b = 4;

    // calling functions defined inside header mymath.h
    cout << "Value of add(a, b): " << add(a, b) << endl;

    // calling function defined inside header mymath.h
    cout << "Value of multiply(a, b): " << multiply(a, b)
         << endl;

    return 0;
}
