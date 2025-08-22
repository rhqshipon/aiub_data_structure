#include <iostream>
using namespace std;

class normal_stack {
    private:
        int stackk[100], top = 0, maxSize = 100;
    public:
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
};

int main() {
    normal_stack stack;

    cout << "=== Stack Demonstration ===" << endl;

    // Test isEmpty() on empty stack
    cout << endl;
    cout << "1. Testing isEmpty() on empty stack:" << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test isFull() on empty stack
    cout << endl;
    cout << "2. Testing isFull() on empty stack:" << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    // Test show() on empty stack
    cout << endl;
    cout << "3. Testing show() on empty stack:" << endl;
    stack.show();

    // Test pop() on empty stack
    cout << endl;
    cout << "4. Testing pop() on empty stack:" << endl;
    bool popResult = stack.pop();
    cout << "Pop successful? " << (popResult ? "Yes" : "No") << endl;

    // Test push() - adding elements
    cout << endl;
    cout << "5. Testing push() - adding elements:" << endl;
    cout << "Pushing 10: " << (stack.push(10) ? "Success" : "Failed") << endl;
    cout << "Pushing 20: " << (stack.push(20) ? "Success" : "Failed") << endl;
    cout << "Pushing 30: " << (stack.push(30) ? "Success" : "Failed") << endl;
    cout << "Pushing 40: " << (stack.push(40) ? "Success" : "Failed") << endl;
    cout << "Pushing 50: " << (stack.push(50) ? "Success" : "Failed") << endl;

    // Test isEmpty() on non-empty stack
    cout << endl;
    cout << "6. Testing isEmpty() on non-empty stack:" << endl;
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test topElement()
    cout << endl;
    cout << "7. Testing topElement():" << endl;
    cout << "Top element: " << stack.topElement() << endl;

    // Test show() on non-empty stack
    cout << endl;
    cout << "8. Testing show() on non-empty stack:" << endl;
    cout << "Stack contents (top to bottom):" << endl;
    stack.show();

    // Test pop() on non-empty stack
    cout << endl;
    cout << "9. Testing pop() operations:" << endl;
    cout << "Popping element: " << (stack.pop() ? "Success" : "Failed") << endl;
    cout << "New top element: " << stack.topElement() << endl;
    cout << "Popping element: " << (stack.pop() ? "Success" : "Failed") << endl;
    cout << "New top element: " << stack.topElement() << endl;

    // Show stack after pops
    cout << endl;
    cout << "10. Stack after popping 2 elements:" << endl;
    stack.show();

    // Demonstrate filling the stack (optional - for isFull() test)
    cout << endl;
    cout << "11. Filling stack to test isFull():" << endl;
    for(int i = 60; i < 160; i += 10) {
        if(!stack.push(i)) {
            cout << "Stack became full at element " << i << endl;
            break;
        }
    }

    cout << "Is stack full now? " << (stack.isFull() ? "Yes" : "No") << endl;

    return 0;
}
