#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class nodes {
    private:
        Node *head;
    public:
        nodes()    {
            head = new Node(0);
            //head.next = nullptr;
        }
        nodes(int value)    {
            head = new Node(value);
        }

        bool push(int value)    {
            head->next = new Node(value);
        }
        bool pop()  {
            if (head == nullptr)    {
                cout << "List is empty!" << endl;
                return false;
            }

            head = head->next;
            return true;
        }
        void display()  {
            if (head == nullptr)    {
                cout << "List is empty!" << endl;
                return;
            }
            Node *current = head;
            while (current != NULL) {
                cout << current -> data << endl;
                current = current -> next;
            }
        }

};

int main()  {
    //Node* head = new Node(0);
    //head->next = new Node(1);
    //head->next->next = new Node(2);
    //head->next->next->next = new Node(3);
    //head->next->next->next->next = new Node(4);
    //head->next->next->next->next->next = new Node(5);
    //head->next->next->next->next->next->next = new Node(6);
    //head->next->next->next->next->next->next->next = new Node(7);
    //head->next->next->next->next->next->next->next->next = new Node(8);
    //head->next->next->next->next->next->next->next->next->next = new Node(9);
    //head->next->next->next->next->next->next->next->next->next->next = new Node(10);

    //Node *current = head;

    //while (current != NULL) {
        //cout << current -> data << endl;
        //current = current -> next;
    //}

    //int valToFind = 5;
    //while (current != NULL) {
    //    if (current->data == valToFind) {
    //        cout << "Found the value: " << valToFind << endl;
    //        break;
    //    }
    //    current = current -> next;
    //}
    nodes n;
    n.push(9);

    return 0;
}
