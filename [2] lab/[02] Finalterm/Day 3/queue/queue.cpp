#include <iostream>
using namespace std;

const int maxSize = 5;
int arrayy[maxSize];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == maxSize - 1);
}

bool enQueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert " << value << endl;
        return false;
    }

    if (isEmpty()) {
        front = 0;  // Set front to 0 when inserting first element
    }

    rear++;
    arrayy[rear] = value;
    cout << "Inserted " << value << " into queue" << endl;
    return true;
}

bool deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot delete" << endl;
        return false;
    }

    cout << "Deleted " << arrayy[front] << " from queue" << endl;
    front++;

    // Reset queue when it becomes empty
    if (front > rear) {
        front = rear = -1;
    }

    return true;
}

int frontValue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arrayy[front];
}

bool showQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return false;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << arrayy[i] << " ";
    }
    cout << endl;
    return true;
}

int main() {
    // Demonstrate queue operations
    cout << "=== Queue Operations Demo ===" << endl;

    // Try to dequeue from empty queue
    deQueue();

    // Insert elements
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    // Try to insert when full
    enQueue(60);

    // Display queue
    showQueue();
    cout << "Front element: " << frontValue() << endl;

    // Remove some elements
    deQueue();
    deQueue();

    // Display updated queue
    showQueue();
    cout << "Front element: " << frontValue() << endl;

    // Insert more elements
    enQueue(60);
    enQueue(70);

    showQueue();

    return 0;
}
