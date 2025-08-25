#include <iostream>
using namespace std;

struct Student  {
    int uniqueID;
    int numOfCreditsCompleted;
    float cgpa;
};

int main()  {
    Student s1[10];

    s1[0].uniqueID = 1001;
    s1[0].numOfCreditsCompleted = 135;
    s1[0].cgpa = 4.0;

    s1[1].uniqueID = 1002;
    s1[1].numOfCreditsCompleted = 30;
    s1[1].cgpa = 3.90;

    s1[2].uniqueID = 1003;
    s1[2].numOfCreditsCompleted = 40;
    s1[2].cgpa = 3.50;

    s1[3].uniqueID = 1004;
    s1[3].numOfCreditsCompleted = 55;
    s1[3].cgpa = 3.78;

    s1[4].uniqueID = 1005;
    s1[4].numOfCreditsCompleted = 70;
    s1[4].cgpa = 3.40;

    s1[5].uniqueID = 1006;
    s1[5].numOfCreditsCompleted = 80;
    s1[5].cgpa = 3.76;

    s1[6].uniqueID = 1007;
    s1[6].numOfCreditsCompleted = 95;
    s1[6].cgpa = 3.75;

    s1[7].uniqueID = 1008;
    s1[7].numOfCreditsCompleted = 110;
    s1[7].cgpa = 3.60;

    s1[8].uniqueID = 1009;
    s1[8].numOfCreditsCompleted = 120;
    s1[8].cgpa = 3.80;

    s1[9].uniqueID = 1010;
    s1[9].numOfCreditsCompleted = 15;
    s1[9].cgpa = 3.77;

    cout << "Unique ID of students who have CGPA above 3.75:" << endl;
    for (int i = 0; i < 10; i++)    {
        if(s1[i].cgpa > 3.75)    {
            cout << s1[i].uniqueID << endl;
        }
    }

    cout << endl;
    cout << endl;

    cout << "Unique ID of students who has completed credits above 50:" << endl;
    for (int i = 0; i < 10; i++)    {
        if(s1[i].numOfCreditsCompleted > 50)    {
            cout << s1[i].uniqueID << endl;
        }
    }

    return 0;
}
