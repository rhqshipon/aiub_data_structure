#include <iostream>
using namespace std;

int main()  {
    int sizeOfArray = 6;
    int arr[sizeOfArray] = {5, 6, 7, 8, 9};
    int filled_until = sizeOfArray - 1 - 1;

    cout << "Print before operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;

    int position = 2;

    for (int i = filled_until; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = 69;
    filled_until++;


    cout << "Print after operation: ";
    for (int i = 0; i <= filled_until; i++)   {
        cout << arr[i] << " ";
    }
    cout << endl;
}
