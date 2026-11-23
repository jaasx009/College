//WAP to reverse the order of the elements in the stack using additional stack.
#include<iostream>
using namespace std;
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
        bool empty(){
            return (top==-1);
        }
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void reverse(){
            stack s;
            while(!empty()){
                s.push(pop());
            }
            *this = s;
        }
        ~stack(){
            delete[] arr;
        }
};
int main(){
    stack s;
    s.push(12);
    s.push(45);
    s.push(76);
    s.push(34);
    cout<<"Original stack : \n";
    s.display();
    s.reverse();
    cout<<"Reversed stack : \n";
    s.display();
    return 0;
}




























