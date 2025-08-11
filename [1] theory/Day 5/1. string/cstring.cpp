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
    cout << "str1: " << str1 << endl;                    // Output: Hello
    cout << "str2: " << str2 << endl;                    // Output: World
    cout << "Length of str1: " << strlen(str1) << endl;  // Output: 5
    cout << "Length of str2: " << strlen(str2) << endl;  // Output: 5

    setStrings(str1, str2);
    cout << "Result of strcat: "<< strcat(str1, str2) << endl;  // Output: HelloWorld

    setStrings(str1, str2);
    cout << "Result of strncat: "<< strncat(str1, str2, 2) << endl;  // Output: HelloWo

    setStrings(str1, str2);
    cout << "Result of str1lwr: " << strlwr(str1) << endl;  // Output: hello

    setStrings(str1, str2);
    cout << "Result of str2lwr: " << strlwr(str2) << endl;  // Output: world

    setStrings(str1, str2);
    cout << "Result of str1upr: " << strupr(str1) << endl;  // Output: HELLO

    setStrings(str1, str2);
    cout << "Result of str2upr: " << strupr(str2) << endl;  // Output: WORLD

    setStrings(str1, str2);
    cout << "Result of strcpy: "<< strcpy(str1, str2) << endl;  // Output: World

    setStrings(str1, str2);
    cout << "Result of strncpy: "<< strncpy(str1, str2, 2) << endl;
    // Output: DANGEROUS! - prints "Wo" + garbage characters or undefined behavior
    // because strncpy doesn't null-terminate when n < source length

    return 0;
}
