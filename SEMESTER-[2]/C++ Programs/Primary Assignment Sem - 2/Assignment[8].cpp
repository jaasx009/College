/* Perform Stack opera ons using Linked List implementa on.*/
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack." << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack." << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();
    cout << "Top element is: " << myStack.peek() << endl;
    myStack.pop();
    myStack.display();
    return 0;
}