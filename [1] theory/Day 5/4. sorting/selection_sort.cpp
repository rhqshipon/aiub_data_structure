#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        int minIndexValue = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndexValue])
            {
                minIndexValue = j;
            }
        }

        // Swap
        int temp = arr[minIndexValue];
        arr[minIndexValue] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};

    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    int sizeofArray = sizeof(arr) / sizeof(arr[0]);

    cout << sizeofArray << endl;

    cout << "Printing Before Sorting : ";
    for (int i = 0; i < sizeofArray; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << endl;

    selectionSort(arr, sizeofArray);

    cout << "Printing After Sorting : ";
    for (int i = 0; i < sizeofArray; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
