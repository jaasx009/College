/* Write a program to implement linked list.
Include functions for insertion, deletion and search of a number,
reverse the list and concatenate two linked lists (include a function
and also overload operator +) */
#include<iostream>
using namespace std;
class Node{
    public:
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
        SL(int n){
            head = NULL;
            for(int i=1;i<=n;i++){
                this->insertEnd(i*10);
            }
        }
        void insertBegin(int n){
            Node* ptr = new Node(n);
            ptr->next = head;
            head = ptr;
        }
        void insertBeforeN(int n,int pos){
            pos = pos - 1;
            Node* prev = NULL;
            Node* t = head;
            if(pos<1){
                cout<<"Can't insert before 1, use option ONE instead.\n";
                return;
            }
            if(pos==1){
                Node* ptr = new Node(n);
                ptr->next = head;
                head = ptr;
                return;
            }
            for(int i = 1; i<pos && t!=NULL;i++){
                prev = t;
                t = t->next;
            }
            if(t==NULL){
                cout<<"Out of bound.";
                return;
            }
            else{
                Node* ptr = new Node(n);
                ptr->next = t;
                prev->next = ptr;
            }
        }
        void insertAtN(int n, int pos){
            Node* ptr = new Node(n);
            if(pos<1){
                cout<<"Invalid Input.";
                return;
            }
            else if(pos==1){
                ptr->next = head;
                head = ptr;
            }
            else{
                Node* t = head;
                for(int i = 1; i<pos-1 && t!=NULL; i++){
                    t = t->next;
                }
                if(t==NULL){
                    cout<<"Out of bound.";
                    return;
                }
                else{
                    ptr->next = t->next;
                    t->next = ptr;
                }
            }
        }
        void insertAfterN(int n,int pos){
            if(pos<1){
                cout<<"Invalid input.";
                return;
            }
            
            else{
                Node* t = head;
                for(int i=1;i<pos && t!=NULL;i++){
                    t = t->next;
                }
                if(t==NULL){
                    cout<<"Out of bound or the list is empty.";
                    return;
                }
                Node* ptr = new Node(n);
                ptr->next = t->next;
                t->next = ptr;
            }
        }
        void insertEnd(int n){
            Node* ptr = new Node(n);
            if(head == NULL)
                head = ptr;
            else{
                Node* t = head;
                while(t->next!=NULL){
                    t = t->next;
                }
                t->next = ptr;
            }
        }
        void deleteBegin(){
            if(head==NULL) cout<<"List is empty deletion not possible.";
            else{
                Node* t = head;
                head = head->next;
                delete t;
            }
        }
        void deleteBeforeN(int pos){
            if(pos<=1){
                cout<<"Invalid input.";
                return;
            }
            if(head==NULL){
                cout<<"The list is empty, deletion not possible.";
                return;
            }
            if(pos==2){
                Node* t = head;
                head = head->next;
                delete t;
                cout<<"Node deleted.";
                return;
            }
            else{
                Node* prev2 = NULL;
                Node* prev1 = NULL;
                Node* curr = head;
                for(int i=1;i<pos && curr!=NULL;i++){
                    prev2 = prev1;
                    prev1 = curr;
                    curr = curr->next;
                }
                if(curr==NULL){
                    cout<<"Out of bound.";
                    return;
                }
                prev2->next = curr;
                delete prev1;
            }
        }
        void deleteAtN(int pos){
            if(pos<1){
                cout<<"Invalid input.";
                return;
            }
            if(head==NULL){
                cout<<"List is empty deletion not possible.";
                return;
            }
            if(pos==1){
                Node* t = head;
                head = head->next;
                delete t;
                cout<<"Node deleted.";
                return;
            }
            else{
                Node* prev = NULL;
                Node* t = head;
                for(int i=1;i<pos && t!=NULL;i++){
                    prev = t;
                    t = t->next;
                }
                if(t==NULL){
                        cout<<"Out of bound.";
                        return;
                }
                prev->next = t->next;
                delete t;
                cout<<"Node deleted.";
            }
        }
        void deleteAfterN(int pos){
            if(pos<1){
                cout<<"Out of bound.";
                return;
            }
            if(head==NULL){
                cout<<"List is empty deletion not possible.";
                return;
            }
            Node* curr = head;
            for(int i=1;i<pos && curr!=NULL;i++){
                curr = curr->next;
            }
            if(curr==NULL){
                cout<<"Out of bound";
                return;
            }
            Node* n1 = curr->next;
            if(n1==NULL){
                cout<<"The end of the list, deletion not possible.";
                return;
            }
            curr->next = n1->next;
            delete n1;
            cout<<"Node deleted.";
        }
        void deleteEnd(){
            if(head==NULL) cout<<"List is empty deletion not possible.";
            else if(head->next==NULL){
                Node* t = head;
                head = t->next;
                delete t;
            }
            else{
                Node* t;
                Node* prev;
                while(t->next!=NULL){
                    prev = t;
                    t = t->next;
                }
                prev->next = NULL;
                delete t;
            }
        }
        bool Search(int n){
            Node* t = head;
            for(int i=1;t!=NULL;i++){
                if(t->info==n){
                    cout<<"Found at position "<<i<<endl;
                    return true;
                }
                t = t->next;
            }
            cout<<"Not found.";
            return false;
        }
        void reverse(){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            while(curr!=NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            cout<<"List reversed.";
        }
        void concatenate(SL &list2){
            if(head==NULL){
                head = list2.head;
                list2.head = NULL;
                return;
            }
            Node* t = head;
            while(t->next!=NULL){
                t = t->next;
            }
            t->next = list2.head;
            list2.head = NULL;
        }
        SL operator+(SL const &list2)const{
            SL newList;
            Node* t1 = this->head;
            while(t1!=NULL){
                newList.insertEnd(t1->info);
                t1 = t1->next;
            }
            Node* t2 = list2.head;
            while(t2!=NULL){
                newList.insertEnd(t2->info);
                t2 = t2->next;
            }
            return newList;
        }
        void display()const{
            Node* t = head;
            if(t==NULL){
                cout<<"The list is empty";
                return;
            }
            cout<<"\nThe list : \n\n";
            while(t!=NULL){
                cout<<"["<<t->info<<"]"<<" ";
                t = t->next;
            }
            cout<<endl;
        }
};
int main(){
    SL list1(5),list2;
    list1.display();
    int ch,n,pos;
    while(1){
        cout<<"\n---LINKED LIST OPERATIONS---\n"<<endl;
        cout<<"1. INSERTION AT THE BEGINNING."<<endl;
        cout<<"2. INSERTION BEFORE A POSITION."<<endl;
        cout<<"3. INSERTION AT A POSITION."<<endl;
        cout<<"4. INSERTION AFTER A POSITION."<<endl;
        cout<<"5. INSERTION AT THE END."<<endl;
        cout<<"6. DELETION AT THE BEGINNING."<<endl;
        cout<<"7. DELETION BEFORE A POSITION."<<endl;
        cout<<"8. DELETION AT A POSITION."<<endl;
        cout<<"9. DELETION AFTER A POSITION."<<endl;
        cout<<"10. DELETION AT THE END."<<endl;
        cout<<"11. SEARCH A NUMBER."<<endl;
        cout<<"12. REVERSE THE LINKED LIST."<<endl;
        cout<<"13. CONCATINATION OF TWO LINKED LIST USING FUNCTION."<<endl;
        cout<<"14. CONCATINATION OF TWO LINKED LIST USING + OPERATOR."<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the number : ";
                cin>>n;
                list1.insertBegin(n);
                list1.display();
                break;
            case 2:
                cout<<"Enter the position : ";
                cin>>pos;
                cout<<"Enter the number : ";
                cin>>n;
                cout<<endl;
                list1.insertBeforeN(n,pos);
                list1.display();
                break;
            case 3:
                cout<<"Enter the position : ";
                cin>>pos;
                cout<<"Enter the number : ";
                cin>>n;
                cout<<endl;
                list1.insertAtN(n,pos);
                list1.display();
                break;
            case 4:
                cout<<"Enter the position : ";
                cin>>pos;
                cout<<"Enter the number : ";
                cin>>n;
                cout<<endl;
                list1.insertAfterN(n,pos);
                list1.display();
                break;
            case 5:
                cout<<"Enter the number : ";
                cin>>n;
                list1.insertEnd(n);
                list1.display();
                break;
            case 6:
                
        }
    }
}