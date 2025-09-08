#include <iostream>
using namespace std;


const int maxSize = 5;
static int queueArray[maxSize];
int front = -1, rear = -1;

bool isEmpty()  {
    return (front == -1 && rear == -1);
}

bool isFull()   {
    return (rear == maxSize);
}

bool enQueue(int value) {
    if(isFull())  {
        cout << "Queue overflowed!" << endl;
        return false;
    }
    if(isEmpty())   {
        front = 0;
    }
    queueArray[++rear] = value;
    cout << "Insertion " << value << " successful!" << endl;
    return true;
}

bool deQueue()  {
    if(isEmpty())   {
        cout << "Queue is underflowed!" << endl;
        return false;
    }
    cout << "Dequeued " << queueArray[front++] << " successfully" << endl;

    if (front > rear)   {
        front = -1;
        rear = -1;
    }
    return true;
}

void showQueue()    {
    if(isEmpty())   {
        cout << "Queue is underflowed, nothing to show!" << endl;
        return;
    }
    cout << "Showing queue (left to right): ";
    for (int i = front; i <= rear; i++) {
        cout << queueArray[i] << " ";
    }
    cout << endl;
}

int operationMenu()    {
    int option;
    cout << "[1] Enqueue element in the queue" << endl;
    cout << "[2] Dequeue element in the queue" << endl;
    cout << "[3] Display the queue" << endl;
    cout << "[4] Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> option;
    if (option >=1 && option <=4)   {
        return option;
    }
    else {
        return 0;
    }
}

int main()  {
    int option = 0;
    int insertedValue;

    while(option != 4)  {
        option = operationMenu();

        switch(option)  {
            case 1:
                cout << "Enter your value: ";
                cin >> insertedValue;
                enQueue(insertedValue);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                showQueue();
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
