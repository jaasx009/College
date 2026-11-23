//WAP to perform circular queue operations using array.
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
            front = rear = -1;
        }
        void enqueue(int val){
            if((rear+1)%size==front){
                cout<<"Overflow.";
                return;
            }
            if(front==-1){
                front = (front+1)%size;
            }
            rear = (rear+1)%size;
            arr[rear] = val;
        }
        void dequeue(){
            if(front==-1||front>rear){
                cout<<"Underflow.";
                return;
            }
            cout<<"Deleted "<<arr[front]<<endl;
            front = (front+1)%size;
            if(front>rear){
                front = -1;
                rear = -1;
            }
        }
        void display(){
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
    q.enqueue(340);
    q.enqueue(23);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}





























