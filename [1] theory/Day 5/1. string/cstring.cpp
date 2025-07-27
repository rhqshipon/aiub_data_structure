#include <iostream>
#include <cstring>

const int MAX_STRING_LEN = 50;

using namespace std;

void setStrings(char* dest1, char* dest2) {
    strcpy(dest1, "Hello");
    strcpy(dest2, "World");
}

int main() {
    char str1[MAX_STRING_LEN];
    char str2[MAX_STRING_LEN];

    setStrings(str1, str2);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Length of str2: " << strlen(str2) << endl;

    setStrings(str1, str2);
    cout << "Result of strcat: "<< strcat(str1, str2) << endl;

    setStrings(str1, str2);
    cout << "Result of strncat: "<< strncat(str1, str2, 2) << endl;

    setStrings(str1, str2);
    cout << "Result of str1lwr: " << strlwr(str1) << endl;

    setStrings(str1, str2);
    cout << "Result of str2lwr: " << strlwr(str2) << endl;

    setStrings(str1, str2);
    cout << "Result of str1upr: " << strupr(str1) << endl;

    setStrings(str1, str2);
    cout << "Result of str2upr: " << strupr(str2) << endl;

    setStrings(str1, str2);
    cout << "Result of strcpy: "<< strcpy(str1, str2) << endl;

    return 0;
}
