#include <iostream>
using namespace std;

int main()  {
    int sizeOfArray = 6;
    int arr[sizeOfArray] = {5, 10, 7, 6, 8, 9};
    int filled_until = sizeOfArray - 1;

    cout << "Print before operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;

    int min_index;
    int temp;
    for(int i = 0; i < filled_until; i++)   {
        min_index = i;
        for(int j = i; j < sizeOfArray; j++)    {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    cout << "Print after operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;

    int the_index;
    int input = 9;
    int first = 0;
    int last = filled_until;

    while(first <= last)    {
        int middle = (first + last) / 2;
        if(arr[middle] == input) {
            the_index = middle;
            break;
        }
        else if(arr[middle] < input)    {
            first = middle + 1;
        }
        else    {
            last = middle - 1;
        }
    }
    cout << "Found the value " << input << " at index " << the_index << " or, position " << the_index + 1 << endl;


}
