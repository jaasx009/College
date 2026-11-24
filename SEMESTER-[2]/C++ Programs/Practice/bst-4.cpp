//WAP to create a binary tree and use the inorder traversal.
#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int info;
    Node* lc;
    Node* rc;
    Node(int val){
        info = val;
        lc = NULL;
        rc = NULL;
    }
};
class BST{
    private:
        Node* root;
        Node* InsertIt(Node* T, int val){
            if(T==NULL){
                return new Node(val);
            }
            if(val<T->info){
                T->lc = InsertIt(T->lc,val);
            }
            else if(val>T->info){
                T->rc = InsertIt(T->rc,val);
            }
            return T;
        }
        void Inorder(Node* T){
            stack<Node*> s;
            Node* ptr = T;
            bool flag = true;
            while(flag){
                while(ptr!=NULL){
                    s.push(ptr);
                    ptr = ptr->lc;
                }
                if(!s.empty()){
                    ptr = s.top();
                    s.pop();
                    cout<<ptr->info<<" ";
                    ptr = ptr->rc;
                }
                else flag = false;
            }
        }
        void preorder(Node* T){
            stack<Node*> s;
            Node* ptr = T;
            bool flag = true;
            while(flag){
                while(ptr!=NULL){
                    cout<<ptr->info<<" ";
                    s.push(ptr);
                    ptr = ptr->lc;
                }
                if(!s.empty()){
                    ptr = s.top();
                    s.pop();
                    ptr = ptr->rc;
                }
                else flag = false;
            }
        }
        void postorder(Node* T){
            stack<Node*> s1,s2;
            Node* ptr = T;
            bool flag = true;
            while(flag){
                while(ptr!=NULL){
                    s1.push(ptr);
                    s2.push(ptr);
                    ptr = ptr->rc;
                }
                if(!s1.empty()){
                    ptr = s1.top();
                    s1.pop();
                    ptr = ptr->lc;
                }
                else flag = false;
            }
            while(!s2.empty()){
                cout<<s2.top()->info<<" ";
                s2.pop();
            }
        }
    public:
        BST(){
            root = NULL;
        }
        void insert(int val){
            root = InsertIt(root,val);
        }
        void display(){
            cout<<"Inorder traversal."<<endl;
            Inorder(root);
            cout<<endl;
            cout<<"Preorder traversal."<<endl;
            preorder(root);
            cout<<endl;
            cout<<"Postorder traversal."<<endl;
            postorder(root);
            cout<<endl;
        }
};
int main(){
    BST t;
    t.insert(12);
    t.insert(45);
    t.insert(56);
    t.insert(89);
    t.insert(23);
    t.display();
    return 0;
}
































        







































