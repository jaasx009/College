//WAP to implement linked list and delete a node.
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
        void insert(int val){
            Node* ptr = new Node(val);
            if(head==NULL){
                head = ptr;
            }
            else if(head->next == NULL){
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
        void Delete(){
            if(head==NULL) {cout<<"Deletion not possible."; return;}
            else if(head->next == NULL){
                Node* t = head;
                head = NULL;
                delete t;
            }
            else{
                Node* t1 = head;
                Node* t2 = NULL;
                while(t1->next!=NULL){
                    t2 = t1;
                    t1 = t1->next;
                }
                t2->next = NULL;
                delete t1;
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
        ~SL(){
            Node* curr = head;
            Node* next = NULL;
            while(curr!=NULL){
                next = curr->next;
                delete curr;
                curr = next;
            }
        }
};
int main(){
    SL L;
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : ";
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        L.insert(val);
    }
    L.display();
    cout<<"Delete ? 0/1";
    int num;
    cin>>num;
    if(num){
        L.Delete();
        L.display();
    }
    return 0;
}











































