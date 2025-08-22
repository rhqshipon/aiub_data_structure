#include <iostream>
using namespace std;

int main() {
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int current_size = 10;

    cout << "Given array: ";
    for (int i = 0; i < current_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr[current_size] = 100;
    current_size++;

    for (int i = current_size; i > 4; i--) {
        arr[i] = arr[i - 1];
    }
    arr[4] = 200;
    current_size++;

    for (int i = current_size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = 300;
    current_size++;

    cout << "Output array after addition: ";
    for (int i = 0; i < current_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
