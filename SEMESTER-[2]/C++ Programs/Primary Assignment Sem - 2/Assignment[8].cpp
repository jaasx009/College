/* Perform Queues operations using Array. */
#include <iostream>
using namespace std;

template<class T>
class ArrayQueue {
    private:
        T *arr;
        int front;
        int rear;
        int size;

    public:
        ArrayQueue(int n = 100) {
            size = n;
            arr = new T[size];
            front = -1;
            rear = -1;
        }
        void enqueue(T val) {
            if (rear == size - 1) {
                cout << "Queue Overflow! Can't enqueue " << val << ".\n";
                return;
            }
            if (front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = val;
            cout << val << " enqueued to queue.\n";
        }
        void dequeue() {
            if (front == -1 || front > rear) {
                cout << "Queue Underflow! The queue is empty.\n";
                return;
            }
            cout << arr[front] << " dequeued from queue.\n";
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
        void peek() {
            if (front == -1 || front > rear) {
                cout << "Queue is empty.\n";
                return;
            }
            cout << "Front element is " << arr[front] << "\n";
        }
        void display() {
            if (front == -1 || front > rear) {
                cout << "Queue is empty.\n";
                return;
            }
            cout << "Queue (Front to Rear): ";
            for (int i = front; i <= rear; i++) {
                cout << "[ " << arr[i] << " ] ";
            }
            cout << "\n";
        }
        ~ArrayQueue() {
            delete[] arr;
        }
};

int main() {
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;

    ArrayQueue<int> obj(n);
    int ch;
    int val;

    while (1) {
        cout << "\n===== QUEUE (ARRAY) =====";
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