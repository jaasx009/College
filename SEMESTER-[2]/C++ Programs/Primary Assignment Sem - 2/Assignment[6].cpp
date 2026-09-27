/* Perform Stack operations using Linked List implementation. */
#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
        T info;
        Node<T> *next;
        Node(T val){
            info = val;
            next = NULL;
        }
};
template<class T>
class Stack{
    private:
        Node<T> *top;
    public:
        Stack(){
            top = NULL;
        }
        void push(T val){
            Node<T> *ptr = new Node<T>(val);
            ptr->next = top;
            top = ptr;
            cout<<val<<" pushed to stack\n";
        }
        void pop(){
            if(top==NULL){
                cout<<"Stack underflow.";
                return;
            }
            Node<T> *t = top;
            top = top->next;
            cout<<t->info<<" popped from stack.\n";
            delete t;
        }
        void peek(){
            if(top==NULL){
                cout<<"Stack underflow.";
                return;
            }
            cout<<"Top element is "<<top->info<<endl;
        }
        void display(){
            if(top==NULL){
                cout<<"Stack underflow.";
                return;
            }
            Node<T> *t = top;
            cout<<"Stack top to bottom.\n";
            while(t!=NULL){
                cout<<"| "<<t->info<<" |\n";
                t = t->next;
            }
            cout<<"|___|\n";
        }
        ~Stack(){
            Node<T> *t = top;
            while(top!=NULL){
                t = top;
                top = top->next;
                delete t;
            }
        }
};
int main() {
    Stack<int> obj;
    int ch;
    int val;

    while (1) {
        cout << "\n===== STACK (LINKED LIST) =====";
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