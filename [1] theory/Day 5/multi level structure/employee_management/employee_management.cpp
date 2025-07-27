#include <iostream>
#include <string>
using namespace std;


struct DateOfBirth    {
    int date, month, year;
};

struct EmployeeManagement {
    string EmployeeName;
    DateOfBirth dob;
};


int main()  {
    EmployeeManagement e1;

    e1.dob.date = 28;
    e1.dob.month = 10;
    e1.dob.year = 2004;
    e1.EmployeeName = "Anisul Hoque";

    cout << "Employee Information," << endl;
    cout << "Employee Name: " << e1.EmployeeName << endl;
    cout << "Date of Birth: " << e1.dob.date << "/" << e1.dob.month << "/" << e1.dob.year << endl;

    return 0;
}
