#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* nextNode;

    Node()
    {
        data = 0;
        nextNode = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->nextNode = NULL;
    }
};



class Linkedlist
{
    Node* head;

public:
    Linkedlist()
    {
        head = NULL;
    }

    void insertNode(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
            {
               head = newNode;
            }
        else
        {
            Node* currentNode = head;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
        }
    }

    void printList()
    {
        Node* currentNode = head;
        if (head == NULL)
            {
                cout << "List empty" << endl;
            }
        else
        {
            while (currentNode != NULL)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->nextNode;
            }
        }
    }

    void deleteNode(int node)
    {
        Node* temp1 = head, *temp2 = NULL;
        int ListLen = 0;

        if (head == NULL)
            {
                cout << "List empty." << endl;
                return;
            }

        while (temp1 != NULL)
            {
                temp1 = temp1->nextNode;
                ListLen++;
            }

        if (ListLen < node)
            {
                cout << "Index out of range" << endl;
                return;
            }

        temp1 = head;

        if (node == 1)
            {
                head = head->nextNode;
                delete temp1;
                return;
            }

        while (node-- > 1)
            {
                temp2 = temp1;
                temp1 = temp1->nextNode;
            }

        temp2->nextNode = temp1->nextNode;
        delete temp1;
    }
};

int main()
{
    Linkedlist l;
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);

    cout << "Elements of the list are: ";
    l.printList();
    cout << endl;

    return 0;
}

