#include <iostream>
#include <string>
using namespace std;

int main() {
   string greeting = "Hello";

    greeting.append(", world!");

    cout << "Length: " << greeting.length() << endl;

    greeting.replace(7, 5, "C++");

    cout << "Modified string: " << greeting << endl;

    return 0;
}

