//WAP to create and perform different operations on Double-ended Queues using Linked List implementation.
#include<iostream>
using namespace std;
struct Node{
    int info;
    Node* prev;
    Node* next;
    Node(int val){
        info = val;
        prev = next = NULL;
    }
};
class deque{
    private:
        Node* front;
        Node* rear;
    public:
        deque(){
            front = NULL;
            rear = NULL;
        }
        void insertfront(int val){
            Node* ptr = new Node(val);
            if(front==NULL){
                front = rear = ptr;
                return;
            }
            ptr->next = front;
            front->prev = ptr;
            front = ptr;
        }
        void deletefront(){
            if(front==NULL){
                cout<<"Underflow.";
                return;
            }
            Node* t = front;
            front = front->next;
            front->prev = NULL;
            delete t;
        }
        void insertrear(int val){
            Node* ptr = new Node(val);
            if(rear==NULL){
                front = rear = ptr;
                return;
            }
            rear->next = ptr;
            ptr->prev = rear;
            rear = ptr;
        }
        void deleterear(){
            if(rear==NULL){
                cout<<"Underflow.";
                return;
            }
            Node* t = rear;
            rear = rear->prev;
            rear->next = NULL;
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
        ~deque(){
            Node* curr = front;
            while(curr!=NULL){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }
};
int main(){
    deque d;
    d.insertfront(12);
    d.insertfront(34);
    d.insertfront(25);
    d.insertfront(450);
    d.display();
    d.deletefront();
    d.deletefront();
    d.display();
    d.insertrear(56);
    d.insertrear(78);
    d.insertrear(98);
    d.insertrear(23);
    d.display();
    d.deleterear();
    d.deleterear();
    d.display();
    return 0;
}






































