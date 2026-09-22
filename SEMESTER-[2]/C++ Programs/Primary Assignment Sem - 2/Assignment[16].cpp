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
            cout << "Stack Overflow!" << endl;
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
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack originalStack;
    Stack extraStack; 
    int num, value;
    cout << "How many elements do you want to add to the stack? (Max 50): ";
    cin >> num;
    if (num > 50) {
        cout << "Maximum size is 50. Limiting input to 50 elements." << endl;
        num = 50;
    }
    cout << "Enter " << num << " numbers:" << endl;
    for (int i = 0; i < num; i++) {
        cin >> value;
        originalStack.push(value);
    }
    cout << "\nOriginal Stack (top to bottom): ";
    originalStack.display(); 
    while (!originalStack.isEmpty()) {
        extraStack.push(originalStack.peek());
        originalStack.pop();
    }
    originalStack = extraStack; 
    cout << "Reversed Stack (top to bottom): ";
    originalStack.display(); 
    return 0;
}