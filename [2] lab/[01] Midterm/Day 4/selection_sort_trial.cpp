#include <iostream>
using namespace std;

int main() {
    int arr[] = {50, 60, 44, 222, 15, 24, 63, 57, 59, 88};

    int sizeOfArray = sizeof(arr)/sizeof(arr[0]);

    cout << "Size of array: " << sizeOfArray << endl;
    cout << "Print before sorting: ";
    for (int i = 0; i < sizeOfArray; i++)   {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << endl;

    cout << "Performing selection sort operation..." << endl;

    for (int i = 0; i < sizeOfArray - 1; i++)   {
        int minIndexValue = i;
        for (int j = i; j < sizeOfArray; j++)   {
            if (arr[j] < arr[minIndexValue])    {
                minIndexValue = j;
            }
        }
        int temp = arr[minIndexValue];
        arr[minIndexValue] = arr[i];
        arr[i] = temp;
    }

    cout << endl;

    cout << "Print after sorting: ";
    for (int i = 0; i < sizeOfArray; i++)   {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
