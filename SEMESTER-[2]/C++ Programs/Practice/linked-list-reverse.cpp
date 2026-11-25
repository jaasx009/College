#include<iostream>
using namespace std;
template<class T>
class Node{
    T info;
    Node<T>* next;
    Node(T val){
        info = val;
        next = NULL;
    }
};
template<class T>
class LS{
    private:
        Node<T>* head;
    public:
        LS(){
            head = NULL;
        }
        void insert(T val){
            Node<T>* ptr = new Node<T>(val);
            if(head==NULL) head = ptr;
            else if(head->next==NULL){
                head->next = ptr;
            }
            else{
                Node<T>* t = head;
                while(t->next!=NULL){
                    t = t->next;
                }
                t->next = ptr;
            }
        }
        void reverse(){
            Node<T>* curr = head;
            Node<T>* next = NULL;
            Node<T>* prev = NULL;
            if(curr==NULL) return;
            while(curr!=NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
        void concat(LS &l2){
            if(head==NULL) head = l2.head;
            else{
                Node<T>* t = head;
                while(t->next!=NULL){
                    t = t->next;
                }
                t->next = l2.head;
            }
            l2.head = NULL;
        }
        LS operator+(const LS &l2) const{
            LS<T> newNode;
            Node<T>* t = this->head;
            while(t!=NULL){
                newNode.insert(t->info);
                t = t->next;
            }
            Node<T>* t2 = l2.head;
            while(t2!=NULL){
                newNode.insert(t2->info);
                t2 = t2->next;
            }
            return newNode;
        }
}






























