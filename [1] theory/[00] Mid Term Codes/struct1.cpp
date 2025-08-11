#include<iostream>>
using namespace std;

struct EmployeeRecord {
    char name[5];
    int age;
    float salary;
} a;

EmployeeRecord b, *c, d[5];

int main(){
    c = &a;
    c->age = 30;
    (*c).salary = 5000.0;
    cout << "Age: " << c->age << ", Salary: " << c->salary << endl;
}


