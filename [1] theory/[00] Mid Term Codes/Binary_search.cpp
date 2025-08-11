#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int first = 0;
    int last = n - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }

    return -1;
}

int main() {
    int sortedArr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int target = 99;

    int index = binarySearch(sortedArr, n, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << "." << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }

    return 0;
}
