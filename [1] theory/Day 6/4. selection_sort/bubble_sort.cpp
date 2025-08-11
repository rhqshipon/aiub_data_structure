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


    int temp;
    for(int i = 0; i < filled_until; i++)   {
        for(int j = 0; j < filled_until - i; j++)   {
            if(arr[j] > arr[j+1])   {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Print after operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;
}
