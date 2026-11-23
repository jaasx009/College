//WAP perform queue operations using array.
#include<iostream>
using namespace std;
class queue{
    private:
        int* arr;
        int size;
        int front;
        int rear;
    public:
        queue(){
            size = 100;
            arr = new int[size];
            front = -1;
            rear = -1;
        }
        void enqueue(int val){
            if(rear==size-1){
                cout<<"Overflow.";
                return;
            }
            if(front==-1) front = 0;
            rear++;
            arr[rear] = val;
        }
        void dequeue(){
            if(front==-1||front>rear){
                cout<<"Underflow.";
                return;
            }
            cout<<arr[front]<<endl;
            front++;
            if(front>rear){
                front = -1;
                rear = -1;
            }
        }
        void display(){
            if(front==-1||front>rear){
                cout<<"Underfolw.";
                return;
            }
            cout<<"Front to Rear---"<<endl;
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        ~queue(){
            delete[] arr;
        }
};
int main(){
    queue q;
    q.enqueue(12);
    q.enqueue(350);
    q.enqueue(34);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

































