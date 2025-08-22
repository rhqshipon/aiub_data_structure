#include <iostream>
using namespace std;


int main()  {
    int sizeOfArray = 8;
    int arr[sizeOfArray];

    cout << "Enter data for the arr: " << endl;
    for (int i = 0; i < sizeOfArray; i++)   {
        cin >> arr[i];
    }

    int maxValue = 0;
    int minValue = arr[0];
    for (int i = 0; i < sizeOfArray; i++)   {
        if (arr[i] > maxValue)    {
            maxValue = arr[i];
        }
        if (arr[i] < minValue)    {
            minValue = arr[i];
        }
    }

    cout << "Smallest value in the array: " << minValue << endl;
    cout << "Largest value in the array: " << maxValue <<  endl;


    return 0;
}
