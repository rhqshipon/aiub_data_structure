#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string cppStr = "Hello, world!";

    cout << "Length using string length(): " << cppStr.length() << endl;

    const char* cStr = cppStr.c_str();

    cout << "Length using strlen(): " << strlen(cStr) << endl;

    const char* anotherStr = "Hello, world!";
    if (strcmp(cStr, anotherStr) == 0) {
       cout << "The strings are equal (using strcmp)" << endl;
    }
    return 0;
}

