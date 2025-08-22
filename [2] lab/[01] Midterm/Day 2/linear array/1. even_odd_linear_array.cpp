#include <iostream>
using namespace std;


int main()  {
    int sizeOfArray;
    cout << "Enter the size of the arr: ";
    cin >> sizeOfArray;
    int arr[sizeOfArray];

    cout << "Enter data for the arr: " << endl;
    for (int i = 0; i < sizeOfArray; i++)   {
        cin >> arr[i];
    }

    int sumOfOddIndexElements = 0;
    int numOfAdditionOccurances = 0;
    for (int i = 0; i < sizeOfArray; i++)   {
        if (i%2 != 0)   {
            sumOfOddIndexElements += arr[i];
            numOfAdditionOccurances++;
        }
    }
    cout << "Summation of the odd-indexed elements in the array: " << sumOfOddIndexElements << endl;

    cout << "Average of the summation of the odd-indexed elements in the array: " << sumOfOddIndexElements/numOfAdditionOccurances << endl;

    cout << "Summation of the odd-indexed elements in the array is - ";
    if (sumOfOddIndexElements % 2 == 0) {
        cout << "even" << endl;
    }
    else{
        cout << "odd" << endl;
    }

    return 0;
}
