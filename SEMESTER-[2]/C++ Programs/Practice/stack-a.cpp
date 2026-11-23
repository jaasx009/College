//WAP to perform stack operation using array implementation.
#include<iostream>
using namespace std;
class stack{
    private:
        int* arr;
        int top;
        int size;
    public:
        stack(){
            top = -1;
            size = 100;
            arr = new int[size];
        }
        void push(int val){
            if(top==size-1){
                cout<<"Overflow";
                return;
            }
            top++;
            arr[top] = val;
        }
        void pop(){
            if(top==-1){
                cout<<"Underflow";
                return;
            }
            cout<<"Poped "<<arr[top]<<endl;
            top--;
        }
        void peek(){
            if(top==-1){
                cout<<"Underflow";
                return;
            }
            cout<<"The top element is : "<<arr[top]<<endl;
        }
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<endl;
            }
        }
        ~stack(){
            delete[] arr;
        }
};
int main(){
    stack s;
    s.push(12);
    s.push(340);
    s.push(34);
    s.display();
    s.pop();
    s.display();
    s.peek();
    return 0;
}





























