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
        SL(){
            head = NULL;
        }
        ~SL(){
            Node* curr = head;
            Node* next;
            while(curr!=NULL){
                next = curr->next;
                delete curr;
                curr = next;
            }
        }
        void insert(int val){
            Node* ptr = new Node(val);
            if(head==NULL){
                head = ptr;
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
                t = t->next;
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
        cin>>val;
        L.insert(val);
    }
    L.display();
    return 0;
}


















































