#include <iostream>
using namespace std;


static int stackk[10];

bool isEmpty(int &top) {
    if(top == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull(int &top, int maxSize) {
    if(top == maxSize) {
        return true;
    }
    else {
        return false;
    }
}

void push(int element, int stackk[], int &top, int maxSize) {
    if(isFull(top, maxSize)) {
        cout << "Error: Stack overflowed!" << endl;
        return;
    }
    stackk[top++] = element;
    cout << "Element pushed successfully!" << endl;
}

void pop(int stackk[], int &top) {
    if(isEmpty(top)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Element " << stackk[top - 1] << " popped successfully!" << endl;
    top--;
}

void show(int stackk[], int &top) {
    if(isEmpty(top)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom):" << endl;
    for (int i = top - 1; i >= 0; i--) {
        cout << stackk[i] << endl;
    }
}

int choice() {
    int choicee;
    cout << endl;
    cout << "What you want to do?" << endl;
    cout << "1. Push element in the stack" << endl;
    cout << "2. Pop element from the stack" << endl;
    cout << "3. Display the stack" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choicee;

    if (choicee >= 1 && choicee <= 4) {
        return choicee;
    }
    else {
        return 0;
    }
}

int main() {
    int top = 0;
    int maxSize = 10;
    int input_value;
    int chosen;

    while(chosen != 4)  {
        chosen = choice();

        switch(chosen) {
            case 1:
                cout << "Insert the value: ";
                cin >> input_value;
                push(input_value, stackk, top, maxSize);
                break;

            case 2:
                pop(stackk, top);
                break;

            case 3:
                show(stackk, top);
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
