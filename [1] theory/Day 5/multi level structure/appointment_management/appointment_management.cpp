#include <iostream>
using namespace std;


struct AppointmentManagement    {
    struct AppDate  {
        int date, month, year;
    }ad;

    struct AppTime  {
        int hour, minute;
    }ati;
    char name[100];
};

int main()  {
    AppointmentManagement a1;

    a1.ad.date = 28;
    a1.ad.month = 10;
    a1.ad.year = 2024;
    a1.ati.hour = 9;
    a1.ati.minute = 9;

    cout << "Appointment Information," << endl;
    cout << "Date: " << a1.ad.date << "/" << a1.ad.month << "/" << a1.ad.year << endl;
    cout << "Time: ";
    if (a1.ati.hour < 10)   {
        cout << "0";
    }
    cout << a1.ati.hour << ":";
    if (a1.ati.minute < 10)   {
        cout << "0";
    }
    cout << a1.ati.minute << endl;
}
