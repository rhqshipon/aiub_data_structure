#include <iostream>
using namespace std;

int Search(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target)
            return i;     }
    return -1;
}

int main() {
    int array[] = { 2, 5, 8, 10, 14, 20 };
    int target = 5;
    int size = sizeof(array) / sizeof(array[0]);

    int index = Search(array, size, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}

