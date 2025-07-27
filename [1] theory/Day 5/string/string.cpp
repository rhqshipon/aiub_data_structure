#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void setStrings(char* dest1, char* dest2) {
    dest1 = "Hello";
    dest2 = "World";
}

int main() {
    string str1 = "Hello";
    string str2 = "World";
    string input;
    getline(cin, input);

    //setStrings(str1, str2);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "input: " << input << endl;
    cout << "Length of str1: " << str1.length() << endl;
    cout << "Length of str2: " << str2.length() << endl;




    cout << "Result of strncat: "<< "" << endl;


    cout << "Result of str1lwr: " << "" << endl;


    cout << "Result of str2lwr: " << "" << endl;


    cout << "Result of str1upr: " << "" << endl;


    cout << "Result of str2upr: " << "" << endl;


    cout << "Result of strcpy: "<< "" << endl;

    return 0;
}
