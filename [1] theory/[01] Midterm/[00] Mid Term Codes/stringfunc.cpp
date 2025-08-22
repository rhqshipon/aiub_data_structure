#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Length of str2: " << strlen(str2) << endl;

    char str3[20];
    strcpy(str3, str2);
    cout << "After strcpy, str3: " << str3 << endl;

    strcat(str1, str2);
    cout << "After strcat, str1: " << str1 << endl;

    if (strcmp(str2, str3) == 0) {
        cout << "str2 and str3 are equal." << endl;
    } else {
        cout << "str2 and str3 are NOT equal." << endl;
    }

    return 0;
}

