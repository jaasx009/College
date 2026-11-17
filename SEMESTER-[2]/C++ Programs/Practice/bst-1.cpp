//Write a program to create a binary search tree and insert a node using itteration and recursion.
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
        void inorder(Node* T){
            if(T==NULL)
                return;
            inorder(T->lc);
            cout<<T->data<<" ";
            inorder(T->rc);
        }
        void destroy(Node* T){
            if(T==NULL)
                return;
            destroy(T->lc);
            destroy(T->rc);
            delete T;
        }
    public:
        BST(){
            root = NULL;
        }
        Node* InsertRecursive(Node* T, int val){
            if(T==NULL){
                return new Node(val);
            }
            if(val<T->data)
                T->lc = InsertRecursive(T->lc,val);
            else if(val>T->data)
                T->rc = InsertRecursive(T->rc,val);
            return T;
        }
        void insert(int val){
            root = InsertRecursive(root,val);
        }
        void display(){
            inorder(root);
            cout<<endl;
        }
        ~BST(){
            destroy(root);
        }
};
int main(){
    BST tree;
    tree.insert(23);
    tree.insert(45);
    tree.insert(57);
    cout<<"Tree in inorder."<<endl;
    tree.display();
    return 0;
}





















































