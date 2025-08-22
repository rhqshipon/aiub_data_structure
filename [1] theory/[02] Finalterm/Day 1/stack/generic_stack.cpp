#include <iostream>
#include <string>
using namespace std;

template<typename t> // Template Parameters
class dynamic_stack {
    private:
        t *stackk;
        int top, maxSize;  // Fixed: these should be int, not template type
    public:
        dynamic_stack(int size = 1) {
            maxSize = size;
            stackk = new t[maxSize];
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

        bool push(t element) {  // Fixed: use template type t instead of int
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

        t topElement() {  // Fixed: return template type t instead of int
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
            t *tmpStack = new t[maxSize + size];
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
    cout << "===== COMPLETE TEMPLATE DYNAMIC STACK DEMONSTRATION =====" << endl;

    // =================== PART 1: INTEGER STACK ===================
    cout << endl;
    cout << "=================== INTEGER STACK ===================" << endl;

    dynamic_stack<int> intStack(3);

    cout << endl;
    cout << "1. Initial integer stack (capacity 3):" << endl;
    cout << "Capacity: " << intStack.getCapacity() << endl;
    cout << "Size: " << intStack.getSize() << endl;
    cout << "Is empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full? " << (intStack.isFull() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "2. Testing empty stack operations:" << endl;
    cout << "Showing empty stack:" << endl;
    intStack.show();
    cout << "Trying to pop empty stack:" << endl;
    intStack.pop();

    cout << endl;
    cout << "3. Filling integer stack:" << endl;
    cout << "Pushing 100: " << (intStack.push(100) ? "Success" : "Failed") << endl;
    cout << "Pushing 200: " << (intStack.push(200) ? "Success" : "Failed") << endl;
    cout << "Pushing 300: " << (intStack.push(300) ? "Success" : "Failed") << endl;
    cout << "Size: " << intStack.getSize() << " | Is full? " << (intStack.isFull() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "4. Integer stack contents:" << endl;
    intStack.show();
    cout << "Top element: " << intStack.topElement() << endl;

    cout << endl;
    cout << "5. Testing full stack:" << endl;
    cout << "Trying to push 400: " << (intStack.push(400) ? "Success" : "Failed") << endl;

    cout << endl;
    cout << "6. Resizing integer stack (+2):" << endl;
    cout << "Before resize - Capacity: " << intStack.getCapacity() << endl;
    intStack.resize(2);
    cout << "After resize - Capacity: " << intStack.getCapacity() << endl;
    cout << "Is full? " << (intStack.isFull() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "7. Adding more integers after resize:" << endl;
    cout << "Pushing 400: " << (intStack.push(400) ? "Success" : "Failed") << endl;
    cout << "Pushing 500: " << (intStack.push(500) ? "Success" : "Failed") << endl;
    cout << "Final integer stack:" << endl;
    intStack.show();

    // =================== PART 2: DOUBLE STACK ===================
    cout << endl;
    cout << "=================== DOUBLE STACK ===================" << endl;

    dynamic_stack<double> doubleStack(2);

    cout << endl;
    cout << "8. Double stack operations:" << endl;
    cout << "Initial capacity: " << doubleStack.getCapacity() << endl;
    cout << "Pushing 3.14159: " << (doubleStack.push(3.14159) ? "Success" : "Failed") << endl;
    cout << "Pushing 2.71828: " << (doubleStack.push(2.71828) ? "Success" : "Failed") << endl;
    cout << "Is full? " << (doubleStack.isFull() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "9. Double stack contents:" << endl;
    doubleStack.show();
    cout << "Top element: " << doubleStack.topElement() << endl;

    cout << endl;
    cout << "10. Expanding double stack:" << endl;
    doubleStack.resize(3);
    cout << "New capacity: " << doubleStack.getCapacity() << endl;
    cout << "Pushing 1.41421: " << (doubleStack.push(1.41421) ? "Success" : "Failed") << endl;
    cout << "Pushing 9.80665: " << (doubleStack.push(9.80665) ? "Success" : "Failed") << endl;
    cout << "Pushing 1.61803: " << (doubleStack.push(1.61803) ? "Success" : "Failed") << endl;
    cout << "Updated double stack:" << endl;
    doubleStack.show();

    // =================== PART 3: CHARACTER STACK ===================
    cout << endl;
    cout << "=================== CHARACTER STACK ===================" << endl;

    dynamic_stack<char> charStack(4);

    cout << endl;
    cout << "11. Character stack operations:" << endl;
    cout << "Pushing 'A': " << (charStack.push('A') ? "Success" : "Failed") << endl;
    cout << "Pushing 'B': " << (charStack.push('B') ? "Success" : "Failed") << endl;
    cout << "Pushing 'C': " << (charStack.push('C') ? "Success" : "Failed") << endl;
    cout << "Pushing 'D': " << (charStack.push('D') ? "Success" : "Failed") << endl;

    cout << endl;
    cout << "12. Character stack contents:" << endl;
    charStack.show();
    cout << "Top element: " << charStack.topElement() << endl;
    cout << "Size: " << charStack.getSize() << " | Capacity: " << charStack.getCapacity() << endl;

    cout << endl;
    cout << "13. Pop operations on character stack:" << endl;
    cout << "Popping: " << (charStack.pop() ? "Success" : "Failed") << endl;
    cout << "New top: " << charStack.topElement() << endl;
    cout << "Popping: " << (charStack.pop() ? "Success" : "Failed") << endl;
    cout << "New top: " << charStack.topElement() << endl;
    cout << "Current size: " << charStack.getSize() << endl;

    // =================== PART 4: STRING STACK ===================
    cout << endl;
    cout << "=================== STRING STACK ===================" << endl;

    dynamic_stack<string> stringStack(2);

    cout << endl;
    cout << "14. String stack operations:" << endl;
    cout << "Initial capacity: " << stringStack.getCapacity() << endl;
    cout << "Pushing \"Hello\": " << (stringStack.push("Hello") ? "Success" : "Failed") << endl;
    cout << "Pushing \"World\": " << (stringStack.push("World") ? "Success" : "Failed") << endl;
    cout << "Is full? " << (stringStack.isFull() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "15. String stack contents:" << endl;
    stringStack.show();
    cout << "Top element: " << stringStack.topElement() << endl;

    cout << endl;
    cout << "16. Expanding string stack:" << endl;
    cout << "Trying to push \"C++\": " << (stringStack.push("C++") ? "Success" : "Failed") << endl;
    stringStack.resize(3);
    cout << "After resize - Capacity: " << stringStack.getCapacity() << endl;
    cout << "Pushing \"C++\": " << (stringStack.push("C++") ? "Success" : "Failed") << endl;
    cout << "Pushing \"Templates\": " << (stringStack.push("Templates") ? "Success" : "Failed") << endl;
    cout << "Pushing \"Amazing\": " << (stringStack.push("Amazing") ? "Success" : "Failed") << endl;

    cout << endl;
    cout << "17. Final string stack:" << endl;
    stringStack.show();
    cout << "Size: " << stringStack.getSize() << " | Capacity: " << stringStack.getCapacity() << endl;

    // =================== PART 5: COMPREHENSIVE POP TESTING ===================
    cout << endl;
    cout << "=================== POP OPERATIONS TEST ===================" << endl;

    cout << endl;
    cout << "18. Pop testing across all stacks:" << endl;

    cout << "Integer stack - Before pop:" << endl;
    intStack.show();
    cout << "Popping: " << (intStack.pop() ? "Success" : "Failed") << endl;
    cout << "New top: " << intStack.topElement() << endl;

    cout << endl;
    cout << "Double stack - Before pop:" << endl;
    doubleStack.show();
    cout << "Popping: " << (doubleStack.pop() ? "Success" : "Failed") << endl;
    cout << "New top: " << doubleStack.topElement() << endl;

    cout << endl;
    cout << "String stack - Before pop:" << endl;
    stringStack.show();
    cout << "Popping: " << (stringStack.pop() ? "Success" : "Failed") << endl;
    cout << "New top: " << stringStack.topElement() << endl;

    // =================== PART 6: EDGE CASE TESTING ===================
    cout << endl;
    cout << "=================== EDGE CASE TESTING ===================" << endl;

    cout << endl;
    cout << "19. Testing stack until empty:" << endl;
    dynamic_stack<int> testStack(2);
    testStack.push(10);
    testStack.push(20);

    cout << "Test stack contents:" << endl;
    testStack.show();

    cout << "Emptying stack:" << endl;
    while (!testStack.isEmpty()) {
        cout << "Popping element: " << testStack.topElement() << endl;
        testStack.pop();
        cout << "Size now: " << testStack.getSize() << endl;
    }

    cout << "Is empty? " << (testStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Trying to pop empty stack:" << endl;
    testStack.pop();

    // =================== PART 7: FINAL SUMMARY ===================
    cout << endl;
    cout << "=================== FINAL SUMMARY ===================" << endl;

    cout << endl;
    cout << "20. Final state of all stacks:" << endl;
    cout << "Integer stack   - Size: " << intStack.getSize() << "/" << intStack.getCapacity()
         << " | Top: " << intStack.topElement() << endl;
    cout << "Double stack    - Size: " << doubleStack.getSize() << "/" << doubleStack.getCapacity()
         << " | Top: " << doubleStack.topElement() << endl;
    cout << "Character stack - Size: " << charStack.getSize() << "/" << charStack.getCapacity()
         << " | Top: " << charStack.topElement() << endl;
    cout << "String stack    - Size: " << stringStack.getSize() << "/" << stringStack.getCapacity()
         << " | Top: " << stringStack.topElement() << endl;

    cout << endl;
    cout << "===== DEMONSTRATION COMPLETE =====" << endl;
    cout << "Template stack successfully tested with:" << endl;
    cout << "- int, double, char, and string data types" << endl;
    cout << "- All basic operations (push, pop, show, top)" << endl;
    cout << "- Dynamic resizing functionality" << endl;
    cout << "- Edge cases (empty/full stack conditions)" << endl;
    cout << "- Memory management (automatic via destructor)" << endl;

    return 0;
}
