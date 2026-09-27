/*WAP to reverse the order of the elements in the stack using additional Queue. */
#include <iostream>
using namespace std;
template <class T>
class Queue {
    private:
        T *arr;
        int front;
        int rear;
        int size;
    public:
        Queue(int n = 100) {
            size = n;
            arr = new T[size];
            front = -1;
            rear = -1;
        }
        void enqueue(T val) {
            if (rear == size - 1) return;
            if (front == -1) front = 0;
            arr[++rear] = val;
        }
        T dequeue() {
            if (front == -1 || front > rear) return -1;
            return arr[front++];
        }
        bool isEmpty() {
            return (front == -1 || front > rear);
        }
        ~Queue() {
            delete[] arr;
        }
};
template <class T>
class Stack {
    private:
        T *arr;
        int top;
        int size;

    public:
        Stack(int n = 100) {
            size = n;
            arr = new T[size];
            top = -1;
        }
        void push(T val) {
            if (top == size - 1) {
                cout << "Stack Overflow!\n";
                return;
            }
            arr[++top] = val;
        }
        T pop() {
            if (top == -1) return -1; 
            return arr[top--];
        }
        bool isEmpty() {
            return top == -1;
        }
        void display() {
            if (top == -1) {
                cout << "Stack is empty.\n";
                return;
            }
            cout << "Stack (Top to Bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << "[ " << arr[i] << " ] ";
            }
            cout << "\n";
        }
        void reverseUsingQueue(Queue<T>& auxQueue) {
        while (!this->isEmpty()) {
                auxQueue.enqueue(this->pop());
            }
            while (!auxQueue.isEmpty()) {
                this->push(auxQueue.dequeue());
            }
            cout << "Stack reversed successfully using a Queue!\n";
        }

        ~Stack() {
            delete[] arr;
        }
};
int main() {
    int n, ch, val;
    cout << "Enter the size of the stack: ";
    cin >> n;
    Stack<int> mainStack(n);
    Queue<int> auxQueue(n);
    while (1) {
        cout << "\n===== STACK REVERSAL (QUEUE METHOD) =====";
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Display Stack";
        cout << "\n4. Reverse Stack";
        cout << "\n0. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                mainStack.push(val);
                cout << val << " pushed.\n";
                break;
            case 2:
                val = mainStack.pop();
                if (val != -1) {
                    cout << val << " popped.\n";
                } else {
                    cout << "Stack Underflow!\n";
                }
                break;
            case 3:
                mainStack.display();
                break;
            case 4:
                if (mainStack.isEmpty()) {
                    cout << "Stack is empty, nothing to reverse.\n";
                } else {
                    mainStack.reverseUsingQueue(auxQueue);
                }
                break;
            case 0:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}