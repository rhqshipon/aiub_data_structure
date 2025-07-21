#include <iostream>
using namespace std;


int main()  {
    // Initializing the array
    int sizeOfArray;
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray;
    int array[sizeOfArray];

    // Take user input for the array
    cout << "Enter data for the array: " << endl;
    for (int i = 0; i < sizeOfArray; i++)   {
        cin >> array[i];
    }

    // Calculate the sum of the odd-indexed elements in the array.
    int sumOfOddIndexElements = 0;
    int numOfAdditionOccurances = 0;
    for (int i = 0; i < sizeOfArray; i++)   {
        if (i%2 != 0)   {
            sumOfOddIndexElements += array[i];
            numOfAdditionOccurances++;
        }
    }
    cout << "Summation of the odd-indexed elements in the array: " << sumOfOddIndexElements << endl;

    // Calculate the average of the odd-indexed elements.
    cout << "Average of the summation of the odd-indexed elements in the array: " << sumOfOddIndexElements/numOfAdditionOccurances << endl;

    // Determine whether the sum of the odd-indexed elements is even or odd.
    cout << "Summation of the odd-indexed elements in the array is: ";
    if (sumOfOddIndexElements % 2 == 0) {
        cout << "even" << endl;
    }
    else{
        cout << "odd" << endl;
    }

    return 0;
}
