#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string cppStr = "Hello, world!";
    //cout<<cppStr.length()<<endl;

    const char* cStr = cppStr.c_str();

    cout << "Length using strlen(): " << strlen(cStr) << endl;

    return 0;
}

