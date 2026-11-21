//Write a program to implement linked list and insert a node in the list.
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
class SL{
    private:
        Node* head;
    public:
        Node(){
            head = NULL;
        }
        void insert(int val){
            NOde* ptr = new Node(val);
            if(head==NULL){
                ptr = head;
            }
            else if(head->next==NULL){
                head->next = ptr;
            }
            else{
                Node* t = head;
                while(t->next!=NULL){
                    t = t->next;
                }
                t->next = ptr;
            }
        }
        void display(){
            Node* t = head;
            while(t!=NULL){
                cout<<t->info<<" ";
            }
            cout<<endl;
        }
};
int main(){
    SL L;
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        int val;
        L.insert(val);
    }
    L.display();
    return 0;
}


















































