//WAP to reverse the order of the elements in the stack using additional Queue.
#include<iostream>
using namespace std;
class queue{
    private:
        int*arr;
        int size;
        int front;
        int rear;
    public:
        queue(){
            size = 100;
            arr = new int[size];
            front = rear = -1;
        }
        ~queue(){ delete[] arr; }
        bool isEmpty(){
            return front==-1||front>rear;
        }
        void enqueue(int val){
            if(rear==size-1){
                cout<<"Overflow.";
                return;
            }
            if(front==-1) front = 0;
            arr[++rear] = val;
        }
        int dequeue(){
            if(front==-1||front>rear){
                cout<<"Underflow.";
                return -1;
            }
            int t = arr[front];
            front++;
            if(front>rear){
                front = rear = -1;
            }
            return t;
        }
};
class stack{
    private:
        int* arr;
        int size;
        int top;
    public:
        stack(){
            size = 100;
            arr = new int[size];
            top = -1;
        }
        ~stack(){
            delete[] arr;
        }
        void push(int val){
            if(top==size-1){
                cout<<"Overflow.";
                return;         
            }
            arr[++top] = val;
        }
        int pop(){
            if(top==-1){
                cout<<"Underflow.";
                return -1;
            }
            return arr[top--];
        }
        bool isEmpty(){
            return top==-1;
        }
        void reverse(){
            queue q;
            while(!this->isEmpty()){
                q.enqueue(this->pop());
            }
            while(!q.isEmpty()){
                this->push(q.dequeue());
            }
        }
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    stack s;
    s.push(12);
    s.push(55);
    s.push(76);
    s.push(90);
    cout<<"Original stack : \n";
    s.display();
    s.reverse();
    cout<<"Reversed stack : \n";
    s.display();
    return 0;
}
























