#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int data;        // Value stored in the node
    Node* nextNode;  // Pointer to the next node

    // Default constructor
    Node()
    {
        data = 0;
        nextNode = NULL;
    }

    // Parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->nextNode = NULL;
    }
};

// Linked list class
class Linkedlist {
    Node* head;  // Pointer to the first node of the list

public:
    // Constructor: initializes an empty list
    Linkedlist()
    {
        head = NULL;
    }

    // Insert a node at the end of the list
    void insertNode(int data)
    {
        Node* newNode = new Node(data);

        // If list is empty, new node becomes head
        if (head == NULL) {
            head = newNode;
        }
        else {
            // Traverse to the last node
            Node* currentNode = head;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            // Link new node at the end
            currentNode->nextNode = newNode;
        }
    }

    // Print all elements of the list
    void printList()
    {
        Node* currentNode = head;

        if (head == NULL) {
            cout << "List empty" << endl;
        }
        else {
            while (currentNode != NULL) {
                cout << currentNode->data << " ";
                currentNode = currentNode->nextNode;
            }
        }
    }

    // Delete node at a given position (1-based index)
    void deleteNode(int node)
    {
        Node *temp1 = head, *temp2 = NULL;
        int ListLen = 0;

        // Case: list is empty
        if (head == NULL) {
            cout << "List empty." << endl;
            return;
        }

        // Count total nodes
        while (temp1 != NULL) {
            temp1 = temp1->nextNode;
            ListLen++;
        }

        // If position is invalid
        if (ListLen < node) {
            cout << "Index out of range" << endl;
            return;
        }

        temp1 = head;

        // Case: deleting the first node
        if (node == 1) {
            head = head->nextNode;
            delete temp1;
            return;
        }

        // Traverse to the node to be deleted
        while (node-- > 1) {
            temp2 = temp1;
            temp1 = temp1->nextNode;
        }

        // Adjust links and delete node
        temp2->nextNode = temp1->nextNode;
        delete temp1;
    }
};

// Driver code
int main()
{
    Linkedlist l;

    // Insert elements
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);

    // Print list
    cout << "Elements of the list are: ";
    l.printList();
    cout << endl;

    return 0;
}
