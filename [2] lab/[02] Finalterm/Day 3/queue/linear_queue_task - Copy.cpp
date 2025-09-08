#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // 1. Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // 2. Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* curr = head;
        cout << "List: ";
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }

    // 3. Search for an item
    bool search(int value) {
        Node* curr = head;
        int pos = 0;
        while (curr) {
            if (curr->data == value) {
                cout << "Found " << value << " at position " << pos << endl;
                return true;
            }
            curr = curr->next;
            pos++;
        }
        cout << "Value " << value << " not found." << endl;
        return false;
    }

    // 4a. Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 4b. Insert after a given node value
    void insertAfterValue(int target, int value) {
        Node* curr = head;
        while (curr && curr->data != target) {
            curr = curr->next;
        }
        if (!curr) {
            cout << "Target value " << target << " not found." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // 5a. Delete at beginning
    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning." << endl;
        delete temp;
    }

    // 5b. Delete at end
    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (!head->next) {
            cout << "Deleted " << head->data << " from end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }
        cout << "Deleted " << curr->next->data << " from end." << endl;
        delete curr->next;
        curr->next = nullptr;
    }

    // 5c. Delete by value (middle or anywhere)
    void deleteByValue(int value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted " << value << " from the list." << endl;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != value) {
            curr = curr->next;
        }
        if (!curr->next) {
            cout << "Value " << value << " not found." << endl;
            return;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        cout << "Deleted " << value << " from the list." << endl;
        delete temp;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n2. Display list\n3. Search\n4. Insert at beginning\n";
        cout << "5. Insert after a value\n6. Delete at beginning\n7. Delete at end\n";
        cout << "8. Delete by value\n9. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 4:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 5:
                cout << "Enter target value to insert after: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                list.insertAfterValue(target, value);
                break;
            case 6:
                list.deleteAtBeginning();
                break;
            case 7:
                list.deleteAtEnd();
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;
            case 9:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}
