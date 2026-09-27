/* Perform Queues operations using linklist. */
#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    T info;
    Node<T> *next;
    
    Node(T val) {
        info = val;
        next = NULL;
    }
};
template <class T>
class LinkedQueue {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(T val) {
        Node<T> *ptr = new Node<T>(val);
        if (front == NULL) {
            front = ptr;
            rear = ptr;
        } else {
            rear->next = ptr;
            rear = ptr;
        }
        cout << val << " enqueued to the queue.\n";
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! The queue is empty.\n";
            return;
        }
        
        Node<T> *temp = front;
        cout << temp->info << " dequeued from the queue.\n";
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
    }
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element is: " << front->info << "\n";
    }
    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        
        Node<T> *temp = front;
        cout << "Queue (Front to Rear): ";
        while (temp != NULL) {
            cout << "[ " << temp->info << " ] ";
            temp = temp->next;
        }
        cout << "\n";
    }
    ~LinkedQueue() {
        Node<T> *temp;
        while (front != NULL) {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    LinkedQueue<int> obj;
    int ch;
    int val;
    while (1) {
        cout << "\n===== QUEUE (LINKED LIST) =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display Queue";
        cout << "\n0. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> val;
                obj.enqueue(val);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                obj.display();
                break;
            case 0:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}