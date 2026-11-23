//WAP to perform queue operations using linked list.
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
class queue{
    private:
        Node* front;
        Node* rear;
    public:
        queue(){
            front = rear = NULL;
        }
        void enqueue(int val){
            Node* ptr = new Node(val);
            if(front==NULL) front = rear = ptr;
            rear->next = ptr;
            rear = ptr;
        }
        void dequeue(){
            if(front==NULL){
                cout<<"Underflow.";
                return;
            }
            cout<<"Deleted "<<front->info<<endl;
            Node* t = front;
            front = front->next;
            if(front==NULL) rear = NULL;
            delete t;
        }
        void display(){
            Node* t = front;
            while(t!=NULL){
                cout<<t->info<<" ";
                t = t->next;
            }
            cout<<endl;
        }
        ~queue(){
            Node* curr = front;
            while(curr!=NULL){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }
};
int main(){
    queue q;
    q.enqueue(12);
    q.enqueue(560);
    q.enqueue(45);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}






































