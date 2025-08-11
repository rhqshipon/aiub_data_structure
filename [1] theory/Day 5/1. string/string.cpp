#include <iostream>
#include <string>

using namespace std;

void setStrings(string& dest1, string& dest2) {
    dest1 = "Hello";
    dest2 = "World";
}

int main() {
    string str1, str2;

    setStrings(str1, str2);
    cout << "str1: " << str1 << endl;                    // Output: Hello
    cout << "str2: " << str2 << endl;                    // Output: World
    cout << "Length of str1: " << str1.length() << endl; // Output: 5
    cout << "Length of str2: " << str2.length() << endl; // Output: 5

    setStrings(str1, str2);
    cout << "Result of concatenation: " << str1 + str2 << endl; // Output: HelloWorld

    setStrings(str1, str2);
    cout << "Result of partial concatenation: " << str1 + str2.substr(0, 2) << endl; // Output: HelloWo

    setStrings(str1, str2);
    cout << "Result of str1 (no case conversion available): " << str1 << endl; // Output: Hello

    setStrings(str1, str2);
    cout << "Result of str2 (no case conversion available): " << str2 << endl; // Output: World

    setStrings(str1, str2);
    cout << "Result of str1 (no case conversion available): " << str1 << endl; // Output: Hello

    setStrings(str1, str2);
    cout << "Result of str2 (no case conversion available): " << str2 << endl; // Output: World

    setStrings(str1, str2);
    str1 = str2;
    cout << "Result of assignment: " << str1 << endl;    // Output: World

    return 0;
}
