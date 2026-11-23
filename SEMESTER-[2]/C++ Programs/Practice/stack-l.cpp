//Write a program to perform stack operations using linked list.
#include<iostream>
using namespace std;
struct Node{
    int info;
    Node* next;
    Node(int val){
        info = val;
        next = NULL;
    }
};
class stack{
    private:
        Node* top;
    public:
        stack(){
            top = NULL;
        }
        void push(int val){
            Node* ptr = new Node(val);
            ptr->next = top;
            top = ptr;
        }
        void pop(){
            if(top==NULL){
                cout<<"Underflow.";
                return;
            }
            Node* t = top;
            top = top->next;
            delete t;
        }
        void peek(){
            if(top==NULL){
                cout<<"Underflow.";
                return;
            }
            cout<<"The top element is : "<<top->info<<endl;
        }
        void display(){
            Node* t = top;
            while(t!=NULL){
                cout<<t->info<<endl;
                t = t->next;
            }
        }
        ~stack(){
            Node* curr = top;
            while(curr!=NULL){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }
};
int main(){
    stack s;
    s.push(12);
    s.push(130);
    s.push(45);
    s.display();
    s.pop();
    s.display();
    s.peek();
    return 0;
}





















