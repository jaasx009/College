/* Perform Stack operations using Array implementation.*/
#include <iostream>
using namespace std;

class Stack {
private:
    int top = -1;
    int arr[50];
public:
    void push(int value) {
        if (top < 49) { 
            arr[++top] = value;
        } else {
            cout << "Stack Overflow! Cannot add more elements." << endl;
        }
    }
    void pop() {
        if (top >= 0) {
            top--;
        }
    }
    int peek() {
        return (top >= 0) ? arr[top] : -1;
    }
    bool isEmpty() {
        return top == -1;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}