#include<iostream>
using namespace std;
class Node{
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
        void insert(int val){
            Node* ptr = new Node(val);
            if(head==NULL) head = ptr;
            else{ 
                while(head->next==NULL){
                ptr->prev = head;
                head->next = ptr;
            }
        }
        void reverse(){
            if(head==NULL)return;
            Node* curr = head;
            Node* t;
            while(curr!=NULL){
                t = curr->prev;
                curr->prev = curr->next;
                curr->next = t;
                curr = curr->prev;
            }
            head = t->prev
        }
}






























