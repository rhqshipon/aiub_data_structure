#include <iostream>
using namespace std;

int searchData(int *arr, int sizeOfArray, int dataToSearch) {
    int i = 0;
    for (i; i < sizeOfArray; i++) {
        if (arr[i] == dataToSearch) {
            break;
        }
    }
    int position = ++i;
    return position;
}

void deleteElementByPosition(int *arr, int sizeOfArray, int position) {
    for (int i = position - 1; i < sizeOfArray - 1; i++) {
        arr[i] = arr[i+1];
    }
    for (int i = sizeOfArray - 1; i > position - 1; i--) {
        if (arr[i] == 0) {
            continue;
        }
        arr[i] = 0;
        break;
    }
}

void deleteElementByNumberSearch(int *arr, int sizeOfArray, int dataToDelete) {
    int position = searchData(arr, sizeOfArray, dataToDelete);
    deleteElementByPosition(arr, sizeOfArray, position);
}

int main() {
    int sizeOfArray = 6;
    int arr[sizeOfArray] = {5, 6, 7, 5, 8, 9};

    int input;
    cout << "Enter the number to move towards the end of the list: ";
    cin >> input;

    int occuranceOfExistance = 0;
    cout << "The array initially looks like: ";
    for (int i = 0; i < sizeOfArray; i++) {
        if (arr[i] == input) {
            occuranceOfExistance++;
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The occurance of found existance of the input: " << occuranceOfExistance << endl;
    if (occuranceOfExistance != 0) {
        for (int i = 0; i < occuranceOfExistance; i++) {
            deleteElementByNumberSearch(arr, sizeOfArray, input);
            arr[sizeOfArray - 1] = input;
        }
    }
    else {
        cout << "Error: Cannot perform this operation as the provided number is not in the provided array!" << endl;
    }

    cout << "The array finally looks like: ";
    for (int i = 0; i < sizeOfArray; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxValue = 0;
    int minValue = arr[0];
    for (int i = 0; i < sizeOfArray; i++) {
        if (arr[i] == input) {
            continue;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;
    cout << "Difference: " << maxValue - minValue << endl;

    return 0;
}
