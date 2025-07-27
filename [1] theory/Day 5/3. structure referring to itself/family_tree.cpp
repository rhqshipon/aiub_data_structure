#include <iostream>
#include <string>
using namespace std;

struct Person   {
    string name;
    Person *child;
};

int main()  {
    Person p1;

    p1.name = "Mr. Arif";
    p1.child = new Person[2];
    p1.child[0].name = "Rahim";
    p1.child[1].name = "Ms. Sara";
    p1.child[0].child = new Person;
    p1.child[0].child->name = "Karim";

    cout << "Name: " << p1.name << endl;
    cout << "Name F1.1: " << p1.child[0].name << endl;
    cout << "Name F1.2: " << p1.child[1].name << endl;
    cout << "Name F1.1 -> 2: " << p1.child[0].child->name << endl;

    return 0;
}
