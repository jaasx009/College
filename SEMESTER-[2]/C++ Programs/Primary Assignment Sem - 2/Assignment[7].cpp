/* Implement Doubly Linked List. Include functions for insertion, deletion and search of a 
number, reverse the list.*/

#include<iostream>
using namespace std;
class Node{
    public:
        int info;
        Node* prev;
        Node* next;
        Node(int val){
            info = val;
            prev = NULL;
            next = NULL;
        }
};
class DL{
    private:
        Node* head;
    public:
        DL(){
            head = NULL;
        }
        void insertBegin(int val){
            Node* ptr = new Node(val);
            if(head==NULL) head = ptr;
            else{
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
            cout<<endl<<"Inserted "<<val<<" at the begining.";
        }
        void insertEnd(int val){
            Node* ptr = new Node(val);
            if(head==NULL) head = ptr;
            else{
                Node* t = head;
                while(t->next!=NULL){t = t->next;}
                t->next = ptr;
                ptr->prev = t;
            }
            cout<<endl<<"Inserted "<<val<<" at the end.";
        }
}