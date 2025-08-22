#include <iostream>
using namespace std;

class dynamic_stack {
    private:
        int *stackk, top, maxSize;
    public:
        dynamic_stack(int size = 1) {
            maxSize = size;
            stackk = new int[maxSize];
            top = 0;
        }

        ~dynamic_stack() {
            delete[] stackk;
        }

        bool isEmpty() {
            if(top == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        bool isFull() {
            if(top == maxSize) {
                return true;
            }
            else {
                return false;
            }
        }

        bool push(int element) {
            if(isFull()) {
                cout << "Error: stack is full!" << endl;
                return false;
            }
            stackk[top++] = element;
            return true;
        }

        bool pop() {
            if(isEmpty()) {
                cout << "Error: stack is empty!" << endl;
                return false;
            }
            top--;
            return true;
        }

        int topElement() {
            return stackk[top - 1];
        }

        void show() {
            if(isEmpty()) {
                cout << "Error: stack is empty!" << endl;
                return;
            }
            for (int i = top - 1; i > -1; i--) {
                cout << stackk[i] << endl;
            }
        }

        void resize(int size = 1) {
            int *tmpStack = new int[maxSize + size];
            for (int i = 0; i < top; i++) {
                tmpStack[i] = stackk[i];
            }
            maxSize += size;
            delete[] stackk;
            stackk = tmpStack;
        }

        int getCapacity() {
            return maxSize;
        }

        int getSize() {
            return top;
        }
};

int main() {
    cout << "=== Dynamic Stack Demonstration ===" << endl;

    // Create a small stack with initial size 3
    dynamic_stack stack(3);

    cout << endl;
    cout << "1. Initial stack created with size 3:" << endl;
    cout << "Stack capacity: " << stack.getCapacity() << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    // Test show() on empty stack
    cout << endl;
    cout << "2. Testing show() on empty stack:" << endl;
    stack.show();

    // Test pop() on empty stack
    cout << endl;
    cout << "3. Testing pop() on empty stack:" << endl;
    bool popResult = stack.pop();
    cout << "Pop successful? " << (popResult ? "Yes" : "No") << endl;

    // Fill the initial stack
    cout << endl;
    cout << "4. Filling the stack to capacity:" << endl;
    cout << "Pushing 10: " << (stack.push(10) ? "Success" : "Failed") << endl;
    cout << "Pushing 20: " << (stack.push(20) ? "Success" : "Failed") << endl;
    cout << "Pushing 30: " << (stack.push(30) ? "Success" : "Failed") << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    // Try to push when full
    cout << endl;
    cout << "5. Trying to push when stack is full:" << endl;
    cout << "Pushing 40: " << (stack.push(40) ? "Success" : "Failed") << endl;

    // Show current stack
    cout << endl;
    cout << "6. Current stack contents:" << endl;
    stack.show();

    // Test topElement()
    cout << endl;
    cout << "7. Testing topElement():" << endl;
    cout << "Top element: " << stack.topElement() << endl;

    // Demonstrate resize functionality
    cout << endl;
    cout << "8. Resizing stack by 2 more positions:" << endl;
    cout << "Before resize - Capacity: " << stack.getCapacity() << endl;
    stack.resize(2);
    cout << "After resize - Capacity: " << stack.getCapacity() << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    // Push more elements after resize
    cout << endl;
    cout << "9. Adding more elements after resize:" << endl;
    cout << "Pushing 40: " << (stack.push(40) ? "Success" : "Failed") << endl;
    cout << "Pushing 50: " << (stack.push(50) ? "Success" : "Failed") << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    // Show expanded stack
    cout << endl;
    cout << "10. Stack after expansion:" << endl;
    stack.show();

    // Test pop operations
    cout << endl;
    cout << "11. Testing pop operations:" << endl;
    cout << "Popping element: " << (stack.pop() ? "Success" : "Failed") << endl;
    cout << "New top element: " << stack.topElement() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    cout << "Popping element: " << (stack.pop() ? "Success" : "Failed") << endl;
    cout << "New top element: " << stack.topElement() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    // Final stack state
    cout << endl;
    cout << "12. Final stack state:" << endl;
    cout << "Stack capacity: " << stack.getCapacity() << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    stack.show();

    // Test another resize
    cout << endl;
    cout << "13. Another resize demonstration (adding 3 more positions):" << endl;
    cout << "Before resize - Capacity: " << stack.getCapacity() << endl;
    stack.resize(3);
    cout << "After resize - Capacity: " << stack.getCapacity() << endl;

    return 0;
}
