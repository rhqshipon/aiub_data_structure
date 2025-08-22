#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // input array
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // conditions when bubblesort happens
            if (arr[j] > arr[j + 1]) {
                // bubblesort
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // output sorted array
    }
    cout << endl;

    return 0;
}
