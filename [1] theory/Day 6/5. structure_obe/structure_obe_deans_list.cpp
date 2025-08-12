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

    // Student data from screenshot
    s1[0].name = "Student 1";
    s1[0].studentID = 1001;
    s1[0].cgpa = 3.8;
    s1[0].lowestGradePoint = 3.5;
    s1[0].minCreditsTaken = 15;

    s1[1].name = "Student 2";
    s1[1].studentID = 1002;
    s1[1].cgpa = 3.5;
    s1[1].lowestGradePoint = 3.5;
    s1[1].minCreditsTaken = 15;

    s1[2].name = "Student 3";
    s1[2].studentID = 1003;
    s1[2].cgpa = 3.5;
    s1[2].lowestGradePoint = 3.5;
    s1[2].minCreditsTaken = 15;

    s1[3].name = "Student 4";
    s1[3].studentID = 1004;
    s1[3].cgpa = 4.0;
    s1[3].lowestGradePoint = 3.5;
    s1[3].minCreditsTaken = 15;

    s1[4].name = "Student 5";
    s1[4].studentID = 1005;
    s1[4].cgpa = 4.0;
    s1[4].lowestGradePoint = 3.5;
    s1[4].minCreditsTaken = 15;

    // Display all students and check Dean's List eligibility
    cout << "DEAN'S LIST ELIGIBILITY CHECK" << endl;
    cout << "=============================" << endl;
    cout << "Requirements: CGPA > 3.75, No grade below 3.5, Min 15 credits" << endl;
    cout << "=============================" << endl;

    int eligibleCount = 0;

    for(int i = 0; i < 5; i++) {
        cout << s1[i].name << " (ID: " << s1[i].studentID << ")" << endl;
        cout << "CGPA: " << s1[i].cgpa << endl;
        cout << "Lowest Grade Point: " << s1[i].lowestGradePoint << endl;
        cout << "Credits Taken: " << s1[i].minCreditsTaken << endl;

        // Simple if statement check for Dean's List eligibility
        if(s1[i].cgpa > 3.75 && s1[i].lowestGradePoint >= 3.5 && s1[i].minCreditsTaken >= 15) {
            cout << "Status: ✓ ELIGIBLE FOR DEAN'S LIST" << endl;
            eligibleCount++;
        } else {
            cout << "Status: ✗ NOT ELIGIBLE" << endl;
            // Show which criteria failed
            if(s1[i].cgpa <= 3.75) cout << "  - CGPA not above 3.75" << endl;
            if(s1[i].lowestGradePoint < 3.5) cout << "  - Has grade below 3.5" << endl;
            if(s1[i].minCreditsTaken < 15) cout << "  - Insufficient credits" << endl;
        }
        cout << "-------------------" << endl;
    }

    cout << "\nSUMMARY:" << endl;
    cout << "Total students: 5" << endl;
    cout << "Eligible for Dean's List: " << eligibleCount << endl;
    cout << "Not eligible: " << (5 - eligibleCount) << endl;

    return 0;
}
