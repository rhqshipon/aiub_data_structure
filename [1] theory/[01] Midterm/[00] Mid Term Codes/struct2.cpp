#include <iostream>
using namespace std;

struct EmployeeRecord {
    char name[5];
    int age;
    float salary;
};

int main() {
    EmployeeRecord b;
    EmployeeRecord* c;
    EmployeeRecord d[5];

    b.age = 25;
    b.salary = 4000.5;

    c = &b;

    cout << "Age from pointer: " << c->age << endl;

    d[0].age = 30;

    return 0;
}

