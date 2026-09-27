/*WAP to reverse the order of the elements in the stack using additional stack.*/
#include <iostream>
using namespace std;

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
            if (top == -1) {
                return -1;
            }
            return arr[top--];
        }
        bool isEmpty() {
            return top == -1;
        }
        int getSize() {
            return top + 1;
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
        void reverse(Stack<T>& auxStack) {
            int n = this->getSize();
            
            for (int i = 0; i < n; i++) {
                T temp = this->pop();
                for (int j = 0; j < n - 1 - i; j++) {
                    auxStack.push(this->pop());
                }
                this->push(temp);
                for (int j = 0; j < n - 1 - i; j++) {
                    this->push(auxStack.pop());
                }
            }
            cout << "Stack reversed successfully!\n";
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
    Stack<int> auxStack(n);
    while (1) {
        cout << "\n===== STACK REVERSAL =====";
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
                    mainStack.reverse(auxStack);
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