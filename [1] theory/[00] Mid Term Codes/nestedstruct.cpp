#include <iostream>
#include <cstring>

using namespace std;

struct Appointment {
    struct AppDate {
        int day, month, year;
    } dt;
    struct AppTime {
        int hour, minute;
    } tm;

    char venue[100];
};

int main() {
    Appointment a;

    a.dt.day = 25;
    a.dt.month = 7;
    a.dt.year = 2025;

    a.tm.hour = 10;
    a.tm.minute = 16;

    strcpy(a.venue, "Community Hall, Main Street");

    cout << "Appointment Details:" << endl;
    cout << "Date: " << a.dt.day << "/" << a.dt.month << "/" << a.dt.year << endl;

    cout << "Time: " << a.tm.hour << ":";
    if (a.tm.minute < 10) {
        cout << "0";
    }
    cout << a.tm.minute << endl;

    cout << "Venue: " << a.venue << endl;

    return 0;
}

