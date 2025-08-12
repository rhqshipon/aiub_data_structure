#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int studentID;
    float cgpa;
    float lowestGradePoint;
    int minCreditsTaken;
};

int main() {
    student s1[5];

    // Student 0 - First row from screenshot
    s1[0].name = "Student 1";           // Name from table
    s1[0].studentID = 1001;             // Student ID from table
    s1[0].cgpa = 3.8;                   // CGPA from table
    s1[0].lowestGradePoint = 3.5;       // Lowest Grade Point from table
    s1[0].minCreditsTaken = 15;         // Min Credits Taken from table

    // Student 1 - Second row from screenshot
    s1[1].name = "Student 2";
    s1[1].studentID = 1002;
    s1[1].cgpa = 3.5;
    s1[1].lowestGradePoint = 3.5;
    s1[1].minCreditsTaken = 15;

    // Student 2 - Third row from screenshot
    s1[2].name = "Student 3";
    s1[2].studentID = 1003;
    s1[2].cgpa = 3.5;
    s1[2].lowestGradePoint = 3.5;
    s1[2].minCreditsTaken = 15;

    // Student 3 - Fourth row from screenshot
    s1[3].name = "Student 4";
    s1[3].studentID = 1004;
    s1[3].cgpa = 4.0;
    s1[3].lowestGradePoint = 3.5;
    s1[3].minCreditsTaken = 15;

    // Student 4 - Fifth row from screenshot
    s1[4].name = "Student 5";
    s1[4].studentID = 1005;
    s1[4].cgpa = 4.0;
    s1[4].lowestGradePoint = 3.5;
    s1[4].minCreditsTaken = 15;

    // Display all students
    cout << "Student Information from Screenshot:" << endl;
    cout << "====================================" << endl;

    for(int i = 0; i < 5; i++) {
        cout << "Student " << (i+1) << ":" << endl;
        cout << "Name: " << s1[i].name << endl;
        cout << "Student ID: " << s1[i].studentID << endl;
        cout << "CGPA: " << s1[i].cgpa << endl;
        cout << "Lowest Grade Point: " << s1[i].lowestGradePoint << endl;
        cout << "Min Credits Taken: " << s1[i].minCreditsTaken << endl;
        cout << "-------------------" << endl;
    }



    return 0;
}
