//Write a program to create a binary tree and delete a node by merging.
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* lc;
    Node* rc;
    Node(int val){
        data = val;
        lc = NULL;
        rc = NULL;
    }
};
class BST{
    private:
        Node* root;
        Node* DeleteByMerging(Node* T,int val){
            if(T==NULL) return T;
            if(val<T->data){
                T->lc = DeleteByMerging(T->lc,val);
            }
            else if(val>T->data){
                T->rc = DeleteByMerging(T->rc,val);
            }
            else{
                if(T->lc==NULL){
                    Node* temp = T->rc;
                    delete T;
                    return temp;
                }
                else if(T->rc = NULL){
                    Node* temp = T->lc;
                    delete T;
                    return temp;
                }
                Node* temp = T->lc;
                while(temp->rc!=NULL){
                    temp = temp->rc;
                }
                temp->rc = T->rc;
                Node* NewRoot = T->lc;
                delete T;
            }
        }
}




































































