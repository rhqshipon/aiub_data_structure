#include <iostream>
using namespace std;

int main()  {
    int sizeOfArray = 6;
    int arr[sizeOfArray] = {5, 6, 7, 8, 9, 10};
    int filled_until = sizeOfArray - 1;

    cout << "Print before operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;

    int number = 8;

    int i;

    for (i = 0; i <= filled_until; i++)   {
        if(number == arr[i]) {
            break;
        }
    }

    cout << "Element found at index: " << i << endl;


    cout << "Print after operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;
}
