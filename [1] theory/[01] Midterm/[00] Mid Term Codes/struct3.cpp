#include <iostream>
using namespace std;

struct EmployeeRecord {
    char name[5];
    int age;
    float salary;
};

int main() {
    EmployeeRecord a = {"John", 30, 5000.0};
    EmployeeRecord b;

    b = a;

    cout<<b.name;
}

