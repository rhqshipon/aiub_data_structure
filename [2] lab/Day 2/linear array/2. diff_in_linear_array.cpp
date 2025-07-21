#include <iostream>
using namespace std;


int main()  {
    // Initializing the array
    int sizeOfArray = 8;
    int array[sizeOfArray];

    // Take user input for the array
    cout << "Enter data for the array: " << endl;
    for (int i = 0; i < sizeOfArray; i++)   {
        cin >> array[i];
    }

    int maxValue = 0;
    int minValue = array[0];
    for (int i = 0; i < sizeOfArray; i++)   {
        if (array[i] > maxValue)    {
            maxValue = array[i];
        }
        if (array[i] < minValue)    {
            minValue = array[i];
        }
    }

    cout << "Smallest value in the array: " << minValue << endl;
    cout << "Largest value in the array: " << maxValue <<  endl;


    return 0;
}
