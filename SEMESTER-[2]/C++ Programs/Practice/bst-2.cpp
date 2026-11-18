//Write a program to create a binary search tree and delete a node by copying.
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
        Node* InsertRec(Node* T,int val){
            if(T==NULL) return new Node(val);
            if(val<T->data){
                T->lc = InsertRec(T->lc, val);
            }
            else if(val>T->data){
                T->rc = InsertRec(T->rc,val);
            }
            return T;
        }
        Node* DeleteByCopying(Node* T,int val){
            if(T==NULL) return T;
            if(val<T->data){
                T->lc = DeleteByCopying(T->lc,val);
            }
            else if(val>T->data){
                T->rc = DeleteByCopying(T->rc,val);
            }
            else{
                if(T->lc==NULL){
                    Node* temp = T->rc;
                    delete T;
                    return temp;
                }
                else if(T->rc==NULL){
                    Node* temp = T->lc;
                    delete T;
                    return temp;
                }
                Node* temp = T->lc;
                while(temp->rc!=NULL){
                    temp = temp->rc;
                }
                T->data = temp->data;
                T->lc = DeleteByCopying(T->lc,temp->data);
            }
            return T;
        }
        void inorder(Node* T){
            if(T==NULL) return;
            inorder(T->lc);
            cout<<T->data<<" ";
            inorder(T->rc);
        }
        void destroy(Node* T){
            if(T==NULL) return;
            destroy(T->lc);
            destroy(T->rc);
            delete T;
        }
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            destroy(root);
        }
        void insert(int val){
            root = InsertRec(root,val);
        }
        void Delete(int val){
            root = DeleteByCopying(root,val);
        }
        void display(){
            inorder(root);
            cout<<endl;
        }
};
int main(){
    BST T;
    cout<<"Enter the number of elements : ";
    int n,val;
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>val;
        T.insert(val);
    }
    T.display();
    cout<<"Enter the element to delete : ";
    int e;
    cin>>e;
    T.Delete(e);
    cout<<"Element deleted.\n";
    T.display();
    return 0;
}















































