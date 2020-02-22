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

class Queue {
    Node *front=NULL, *rear=NULL;
    public:
        void insert(int data) {
            if(rear == NULL) {
                rear = new Node(data);
                front = rear;
                return;
            }
            rear->setNext(new Node(data));
            rear = rear->getNext();
        }
        void del() {
            if(front == NULL) {
                cout<<"Queue is empty";
                return;
            }
            int data = front->getData();
            front = front->getNext();
            cout<<"Successfully deleted "<<data<<endl;
        }
        void display() {
            if(front == NULL) {
                cout<<"Queue is empty";
                return;
            }
            Node *temp = front;
            while(temp != NULL) {
                cout<<temp->getData()<<" ";
                temp = temp->getNext();
            }
            cout<<endl;
        }
        int getRear() {
            return rear->getData();
        }
};

int main() {
    Queue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.display();
    q.del();
    q.del();
    q.del();
    q.display();
}