/* Perform Stack operations using Array implementation. */
#include<iostream>
using namespace std;
template<class T>
class AStack{
    private:
        T *arr;
        int top,size;
    public:
        AStack(int n = 100){
            size = n;
            arr = new T[size];
            top = -1;
        }
        void push(T val){
            if(top == size-1){
                cout<<"Stack overfloaw. "<<val<<" can't be pushed.";
                return;
            }
            top++;
            arr[top] = val;
            cout<<val<<" pushed into stack.";
        }
        void pop(){
            if(top==-1){
                cout<<"Stack underflow.";
                return;
            }
            cout<<arr[top]<<" popped form the stack.";
            top--;
        }
        void peek(){
            if(top==-1){
                cout<<"Stack underflow.";
                return;
            }
            cout<<"Top element is "<<arr[top]<<endl;
        }
        void display(){
            if(top==-1){
                cout<<"Stack underflow.";
                return;
            }
            for(int i=top;i>=0;i--){
                cout<<"| "<<arr[i]<<" |\n";
            }
            cout<<"|___|\n";
        }
        ~AStack(){
            delete[] arr;
        }
};
int main() {
    int n;
    cout<<"Enter the size of the stack : ";
    cin>>n;
    AStack<int> obj(n); 
    int ch;
    int val;

    while (1) {
        cout << "\n===== STACK (ARRAY) =====";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display Stack";
        cout << "\n0. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> val;
                obj.push(val);
                break;
            case 2:
                obj.pop();
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