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

    for(int i = 1; i < sizeOfArray; i++)    {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp)  {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Print after operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;
}
