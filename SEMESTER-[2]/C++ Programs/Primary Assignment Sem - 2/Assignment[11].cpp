/*Create and perform different operations on Double-ended Queues using Linked 
List implementation.*/
#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    T info;
    Node<T> *next;
    Node<T> *prev;    
    Node(T val) {
        info = val;
        next = NULL;
        prev = NULL;
    }
};
template <class T>
class Deque {
private:
    Node<T> *front;
    Node<T> *rear;
public:
    Deque() {
        front = NULL;
        rear = NULL;
    }
    void insertFront(T val) {
        Node<T> *ptr = new Node<T>(val);
        if (front == NULL) {
            front = rear = ptr;
        } else {
            ptr->next = front;
            front->prev = ptr;
            front = ptr;
        }
        cout << val << " inserted at the front.\n";
    }
    void insertRear(T val) {
        Node<T> *ptr = new Node<T>(val);
        if (front == NULL) {
            front = rear = ptr;
        } else {
            rear->next = ptr;
            ptr->prev = rear;
            rear = ptr;
        }
        cout << val << " inserted at the rear.\n";
    }
    void deleteFront() {
        if (front == NULL) {
            cout << "Deque Underflow! The deque is empty.\n";
            return;
        }
        Node<T> *temp = front;
        cout << temp->info << " deleted from the front.\n";   
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        delete temp;
    }
    void deleteRear() {
        if (rear == NULL) {
            cout << "Deque Underflow! The deque is empty.\n";
            return;
        }
        Node<T> *temp = rear;
        cout << temp->info << " deleted from the rear.\n";    
        rear = rear->prev;
        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }
        delete temp;
    }
    void display() {
        if (front == NULL) {
            cout << "Deque is empty.\n";
            return;
        }
        Node<T> *temp = front;
        cout << "Deque (Front <-> Rear): ";
        while (temp != NULL) {
            cout << "[ " << temp->info << " ] ";
            temp = temp->next;
        }
        cout << "\n";
    }
    ~Deque() {
        Node<T> *temp;
        while (front != NULL) {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};
int main() {
    Deque<int> obj;
    int ch;
    int val;
    while (1) {
        cout << "\n===== DOUBLE-ENDED QUEUE (DEQUE) =====";
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Display Deque";
        cout << "\n0. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the value to insert at front: ";
                cin >> val;
                obj.insertFront(val);
                break;
            case 2:
                cout << "Enter the value to insert at rear: ";
                cin >> val;
                obj.insertRear(val);
                break;
            case 3:
                obj.deleteFront();
                break;
            case 4:
                obj.deleteRear();
                break;
            case 5:
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