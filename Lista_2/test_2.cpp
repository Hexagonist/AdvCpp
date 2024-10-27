#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    char three_char = '3';
    int three_int = three_char - '0';
    int result = three_int + 1;
    cout << three_char << " + 1 is " << result << endl;
    cout << three_char << "converted:  " << static_cast<int>(three_char) << endl;
    cout << isdigit(three_char)  << endl;


    cout << "test:  " << ('3' - '0') * std::pow(10, 2) << endl;
    cout << "test:  " << stoi("123") << endl;
    string a = "1";
    string b = "2";
    string res = a+b;
    res = a+b+b+'7';
    res += '8';

    cout << "test:  " << res << endl;
    cout << "test:  " << ('a' > 'b') << endl;


    return 0;
}