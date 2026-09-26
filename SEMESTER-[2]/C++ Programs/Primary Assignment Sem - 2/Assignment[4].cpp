/*. Implement Doubly Linked List. Include func ons for inser on, dele on and search of a 
number, reverse the list.*/
#include<iostream>
using namespace std;
template <class T>
class Node{
    public:
        T info;
        Node *prev;
        Node *next;
        Node (T val){
            info = val;
            prev = NULL;
            next = NULL;
        }
};
template <class T>
class DL{
    private:
        Node<T> *head;
    public:
        DL(){
            head = NULL;
        }
        void insertBegin(T val){
            Node<T> *ptr = new Node<T>(val);
            if(head==NULL) head = ptr;
            else{
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
            cout<<endl<<"\nInserted "<<val<<" at the begining.";
        }
        void insertEnd(T val){
            Node<T> *ptr = new Node<T> (val);
            if(head==NULL) head = ptr;
            else{
                Node<T> *t = head;
                while(t->next!=NULL){t = t->next;}
                t->next = ptr;
                ptr->prev = t;
            }
            cout<<endl<<"Inserted "<<val<<" at the end.";
        }
        void deleteElement(T val){
            Node<T> *ptr = head;
            while(ptr!=NULL&&ptr->info!=val){
                ptr = ptr->next;
            }
            if(ptr==NULL){
                cout<<"This list is empty.";
                return;
            }
            //At the begining.
            if(head==ptr){
                head = ptr->next;
                if(ptr->next!=NULL){
                    head->prev = NULL;
                }
                delete ptr;
                cout<<"Element deleted.";
                return;
            }
            //At any other position.
            ptr->prev->next = ptr->next;
            if(ptr->next!=NULL){
                ptr->next->prev = ptr->prev;
            }
            delete ptr;
            cout<<"Element deleted.";
            return;
        }
        void Search(T val){
            Node<T> *t = head;
            int pos = 1;
            while(t!=NULL){
                if(t->info==val){
                    cout<<"Element found at "<<pos<<" position.";
                    return;
                }
                t = t->next;
                pos++;
            }
            cout<<"Element not found.";
        }
        void reverse(){
            if((head==NULL)||(head->next==NULL)) return;
            Node<T> *current = head;
            Node<T> *t = NULL;
            while(current!=NULL){
                t = current->prev;
                current->prev = current->next;
                current->next = t;
                current = current->prev;
            }
            head = t->prev;
        }
        void displayFor(){
            if(head==NULL){
                cout<<"List is empty.";
                return;
            }
            Node<T> *t = head;
            cout<<"Forward : ";
            while(t!=NULL){
                cout<<t->info<<"<->";
                t = t->next;
            }
            cout<<"NULL"<<endl;
        }
        void displayBack(){
            if(head==NULL){
                cout<<"List is empty.";
                return;
            }
            Node<T> *t = head;
            while(t->next!=NULL){
                t = t->next;
            }
            cout<<"Backward : ";
            while(t!=NULL){
                cout<<t->info<<"<->";
                t = t->prev;
            }
            cout<<"NULL"<<endl;

        }
        ~DL(){
            Node<T> *t = head;
            while(head!=NULL){
                head = t->next;
                delete t;
                t = head;
            }
        }
};
int main(){
    DL<int> obj;
    int ch;
    int val;
    while(1){
        cout << "\n===== DOUBLY LINKED LIST =====";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete";
        cout << "\n4. Search";
        cout << "\n5. Reverse";
        cout << "\n6. Display Forward";
        cout << "\n7. Display Backward";
        cout << "\n0. Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the value : ";
                cin>>val;
                obj.insertBegin(val);
                break;
            case 2:
                cout<<"Enter the value : ";
                cin>>val;
                obj.insertEnd(val);
                break;
            case 3:
                cout<<"Enter the value to delete : ";
                cin>>val;
                obj.deleteElement(val);
                break;
            case 4:
                cout<<"Enter the value to search : ";
                cin>>val;
                obj.Search(val);
                break;
            case 5:
                obj.reverse();
                cout<<"List reversed."<<endl;
                break;
            case 6:
                obj.displayFor();
                break;
            case 7:
                obj.displayBack();
                break;
            case 0:
                cout<<"Program ended.";
                return 0;
            default:
                cout<<"Invalid choice.";
        }
    }
}