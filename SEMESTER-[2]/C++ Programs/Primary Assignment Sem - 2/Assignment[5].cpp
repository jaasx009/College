/* Implement Circular Linked List. Include func ons for inser on, dele on and search 
of a number, reverse the list. */
#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
        T info;
        Node<T> *next;
        Node(T val){
            info = val;
            next = this;
        }
};
template<class T>
class CL{
    private:
        Node<T> *head;
    public:
        CL(){head = NULL;}
        void insertEnd(T val){
            Node<T> *ptr = new Node<T>(val);
            if(head==NULL) head = ptr;
            else{
                Node<T> *t = head;
                while(t->next!=head){
                    t = t->next;
                }
                t->next = ptr;
                ptr->next = head;
            }
            cout<<endl<<"Inserted "<<val<<" at the end.";
        }
        void deleteElement(T val){
            if(head==NULL){
                cout<<"List is empty.";
                return;
            }
            Node<T> *curr = head;
            if(curr->info==val){
                if(curr->next==head){
                    head = NULL;
                    delete curr;
                }
                else{
                    Node<T> *t = head;
                    while(t->next!=head){
                        t = t->next;
                    }
                    t->next = head->next;
                    head = head->next;
                    delete curr;
                }
                cout<<"Element deleted.";
                return;
            }
            do{
                Node<T> *prev = curr;
                curr = curr->next;
                if(curr->info==val){
                    prev->next = curr->next;
                    delete curr;
                    cout<<"Element deleted.";
                    return;
                }
            }while(curr!=head);
            cout<<"Element not found.";
        }
        void Search(T val){
            if(head==NULL){
                cout<<"List is empty.";
                return;
            }
            Node<T> *t = head;
            int pos = 1;
            do{
                if(t->info==val){
                    cout<<"Element found at position "<<pos<<".";
                    return;
                }
                t = t->next;
                pos++;
            }while(t->next!=head);
            cout<<"Element not found.";
        }
        void reverse(){
            if(head==NULL||head->next==head) return;
            Node<T> *prev = NULL;
            Node<T> *curr = head;
            Node<T> *next = NULL;
            do{
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }while(curr!=head);
            head->next = prev;
            head = prev;
            cout<<"List reversed.\n";
        }
        void display(){
            if(head==NULL){
                cout<<"List is empty.";
                return;
            }
            Node<T> *t = head;
            do{
                cout<<t->info<<"<->";
                t = t->next;
            }while(t!=head);
            cout<<"Back to head";
        }
        ~CL() {
            if (head == NULL) return; 
            Node<T> *t = head->next;
            Node<T> *p = NULL;
            do{
                p = t;
                t = t->next;
                delete p;
            }while(t != head);
            delete head; 
        }
};
int main() {
    CL<int> obj;
    int ch;
    int val;

    while (1) {
        cout << "\n===== CIRCULAR LINKED LIST =====";
        cout << "\n1. Insert at End";
        cout << "\n2. Delete Element";
        cout << "\n3. Search Element";
        cout << "\n4. Reverse List";
        cout << "\n5. Display List";
        cout << "\n0. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the value : ";
                cin >> val;
                obj.insertEnd(val);
                break;
            case 2:
                cout << "Enter the value to delete : ";
                cin >> val;
                obj.deleteElement(val);
                break;
            case 3:
                cout << "Enter the value to search : ";
                cin >> val;
                obj.Search(val);
                break;
            case 4:
                obj.reverse();
                break;
            case 5:
                obj.display();
                break;
            case 0:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}