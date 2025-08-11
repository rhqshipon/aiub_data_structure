#include <iostream>
using namespace std;

int main() {
    char name[50];
    char fullname[50];

    cout << "Enter your first name: ";
    cin >> name;
    cout << "You entered: " << name << endl;

    cin.ignore();

    cout << "Enter your full name: ";
    cin.get(fullname, 50);
    cout << "You entered full name: " << fullname << endl;

    return 0;
}

