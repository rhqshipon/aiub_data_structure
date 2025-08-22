#include <iostream>
using namespace std;

class linear_array {
    private:
        int sizeOfArray;
        int *arr;

    public:
        // Fixed: Proper initialization
        linear_array() : sizeOfArray(0), arr(nullptr) {}

        // Copy constructor (Rule of Three)
        linear_array(const linear_array &other) : sizeOfArray(other.sizeOfArray) {
            if (other.arr != nullptr) {
                arr = new int[sizeOfArray];
                for (int i = 0; i < sizeOfArray; i++) {
                    arr[i] = other.arr[i];
                }
            } else {
                arr = nullptr;
            }
        }

        // Assignment operator (Rule of Three)
        linear_array& operator=(const linear_array &other) {
            if (this != &other) {
                if (arr != nullptr) {
                    delete[] arr;
                }
                sizeOfArray = other.sizeOfArray;
                if (other.arr != nullptr) {
                    arr = new int[sizeOfArray];
                    for (int i = 0; i < sizeOfArray; i++) {
                        arr[i] = other.arr[i];
                    }
                } else {
                    arr = nullptr;
                }
            }
            return *this;
        }

        // Fixed: Safe destructor
        ~linear_array() {
            if (arr != nullptr) {
                delete[] arr;
            }
        }

        // Fixed: Handle existing memory
        void init_array() {
            if (arr != nullptr) {
                delete[] arr;
            }
            cout << "Enter the size for the array:" << endl;
            cin >> sizeOfArray;
            arr = new int[sizeOfArray];

            cout << "Enter the values for the array:" << endl;
            for (int i = 0; i < sizeOfArray; i++) {
                int input = 0;
                cin >> input;
                arr[i] = input;
            }
            cout << "Done!" << endl;
        }

        // Fixed: Handle element not found case
        int searchData(int dataToSearch) {
            int i = 0;
            for (i; i < sizeOfArray; i++) {
                if (arr[i] == dataToSearch) {
                    break;
                }
            }
            if (i == sizeOfArray) {
                return -1;  // Element not found
            }
            int position = ++i;
            return position;
        }

        // Fixed: Dynamic array resizing for insertion
        void addElementByPosition(int data, int position) {
            if (position < 1 || position > sizeOfArray + 1) {
                cout << "Error: Invalid position for insertion! Operation will not be performed." << endl;
                return;
            }

            // Create new array with increased size
            int *newArr = new int[sizeOfArray + 1];

            // Copy elements before insertion point
            for (int i = 0; i < position - 1; i++) {
                newArr[i] = arr[i];
            }

            // Insert new element
            newArr[position - 1] = data;

            // Copy remaining elements
            for (int i = position - 1; i < sizeOfArray; i++) {
                newArr[i + 1] = arr[i];
            }

            // Replace old array
            delete[] arr;
            arr = newArr;
            sizeOfArray++;
        }

        // Fixed: Handle search failure
        void addElementByNumberSearch(int data, int dataToReplace) {
            int position = searchData(dataToReplace);
            if (position == -1) {
                cout << "Error: Element to replace not found! Operation will not be performed." << endl;
                return;
            }
            addElementByPosition(data, position);
        }

        // Fixed: Validate position and proper array handling
        void deleteElementByPosition(int position) {
            if (position < 1 || position > sizeOfArray) {
                cout << "Error: Invalid position for deletion! Operation will not be performed." << endl;
                return;
            }

            // Shift elements left
            for (int i = position - 1; i < sizeOfArray - 1; i++) {
                arr[i] = arr[i + 1];
            }

            // Create new smaller array
            sizeOfArray--;
            if (sizeOfArray > 0) {
                int *newArr = new int[sizeOfArray];
                for (int i = 0; i < sizeOfArray; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
            } else {
                delete[] arr;
                arr = nullptr;
            }
        }

        // Fixed: Handle search failures and edge cases
        void deleteElementByNumberSearch(int dataToDelete) {
            int occuranceOfExistance = 0;
            for (int i = 0; i < sizeOfArray; i++) {
                if (arr[i] == dataToDelete) {
                    occuranceOfExistance++;
                }
            }
            cout << "The occurance of found existance of the input: " << occuranceOfExistance << endl;

            if (occuranceOfExistance != 0) {
                for (int i = 0; i < occuranceOfExistance; i++) {
                    int position = searchData(dataToDelete);
                    if (position != -1) {
                        deleteElementByPosition(position);
                    } else {
                        cout << "Error: Element not found during deletion! Operation will not be performed." << endl;
                    }
                }
            } else {
                cout << "Error: Cannot perform this operation as the provided number is not in the provided array!" << endl;
            }
        }

        void printArray() {
            if (arr == nullptr || sizeOfArray == 0) {
                cout << "Array is empty" << endl;
                return;
            }
            for (int i = 0; i < sizeOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    linear_array l1;
    l1.init_array();
    l1.printArray();

    l1.addElementByPosition(200, 2);
    l1.printArray();

    l1.deleteElementByPosition(0);  // This will now print error message and not perform operation
    l1.deleteElementByNumberSearch(5);
    l1.printArray();

    return 0;
}
