#include <iostream>
using namespace std;

class Node {
    int data;
    Node *next;
    public:
    Node(int d) {
        data = d;
        this->next = NULL;
    }
    Node* getNext() {
        return this->next;
    }
    void setNext(Node *n) {
        this->next = n;
    }
    int getData() {
        return this->data;
    }
};

class LinkedList {
    Node *head=NULL;
    public:
    void setHead(Node *h) {
        head = h;
    }
    void insert(int data) {
        if(head == NULL) {
            head = new Node(data);
            return;
        }
        Node *temp = head;
        while(temp->getNext()!=NULL) {
            temp = temp->getNext();
        }
        temp->setNext(new Node(data));
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->getData()<<" ";
            temp = temp->getNext();
        }
        cout<<endl;
    }
    Node* insertAtPosition(LinkedList l, int position) {
        Node *temp = head;
        while(--position) {
            temp = temp->getNext();
        }
        Node *end = temp->getNext();
        temp->setNext(l.head);
        while(temp->getNext() != NULL)
            temp = temp->getNext();
        temp->setNext(end);
        return head;
    }
};

int main() {
    LinkedList l1, l2; 
    int size1=3, size2=5;       
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l2.insert(1);
    l2.insert(2);
    l2.insert(3);
    l2.insert(4);
    l2.insert(5);
    int position;
    cout<<"Position ";
    cin>>position;
    if(position > 0)
        l1.setHead(l1.insertAtPosition(l2, position));
    else 
        l1.setHead(l2.insertAtPosition(l1, size2));
    l1.display();
}