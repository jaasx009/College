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
        Node* InsertIterative(Node* T,int val){
            if(T==NULL){
                return new Node(val);
            }
            else{
                Node* ptr = T;
                Node* pre_ptr = NULL;
                while(ptr!=NULL){
                    pre_ptr = ptr;
                    if(val<ptr->data)
                        ptr = ptr->lc;
                    else if(val>ptr->data)
                        ptr = ptr->rc;
                    else
                        return T;
                }
                if(val<pre_ptr->data)
                    pre_ptr->lc = new Node(val);
                else
                    pre_ptr->rc = new Node(val);
            }
            return T;
        }
        
        void InsertRec(int val){
            root = InsertRecursive(root,val);
        }
        void InsertIt(int val){
            root = InsertIterative(root,val);
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
    int ch,n,val;
    while(1){
        BST tree;
        cout<<"1. Insert Recursive."<<endl;
        cout<<"2. Insert Iterative."<<endl;
        cout<<"3. Exit.\n";
        cout<<"Enter the choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the number of elements : \n";
                cin>>n;
                cout<<"Enter the elements : \n";
                for(int i=0;i<n;i++){
                    cin>>val;
                    tree.InsertRec(val);
                }
                tree.display();
                break;
            case 2:
                cout<<"Enter the number of elements : \n";
                cin>>n;
                cout<<"Enter the elements : \n";
                for(int i=0;i<n;i++){
                    cin>>val;
                    tree.InsertIt(val);
                }
                tree.display();
                break;
            case 3:
                cout<<"You have Exited the program.\n";
                return 0;
            default:
                cout<<"Invalid choice.\n";
        }
    }
    return 0;
}

















        



































