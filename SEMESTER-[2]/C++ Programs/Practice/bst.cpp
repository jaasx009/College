#include<iostream>
#include<stack>
#include<queue>
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
        Node* InsertIt(Node* T,int val){
            if(T==NULL){
                return new Node(val);
            }
            Node* ptr = T;
            Node* pre_ptr = NULL;
            while(ptr!=NULL){
                pre_ptr = ptr;
                if(val<ptr->data){
                    ptr = ptr->lc;
                }
                else if(val>ptr->data){
                    ptr = ptr->rc;
                }
                else
                    return T;
            }
            if(val<pre_ptr->data){
                pre_ptr->lc = new Node(val);
            }
            else if(val>pre_ptr->data){
                pre_ptr->rc = new Node(val);
            }
            return T;
        }
        Node* InsertRec(Node* T,int val){
            if(T==NULL) return new Node(val);
            if(val<T->data){
                T->lc = InsertRec(T->lc,val);
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
                    Node* t = T->rc;
                    delete T;
                    return t;
                }
                if(T->rc==NULL){
                    Node* t = T->lc;
                    delete T;
                    return t;
                }
                Node* t = T->lc;
                while(t->rc!=NULL){
                    t = t->rc;
                }
                T->data = t->data;
                T->lc = DeleteByCopying(T->lc,t->data);
            }
            return T;
        }
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
                    Node* t = T->rc;
                    delete T;
                    return t;
                }
                if(T->rc==NULL){
                    Node* t = T->lc;
                    delete T;
                    return t;
                }
                Node* t = T->lc;
                while(t->rc!=NULL){
                    t = t->rc;
                }
                t->rc = T->rc;
                Node* newNode = T->lc;
                delete T;
                return newNode;
            }
            return T;
        }
        bool Search(Node* T, int val){
            if(T==NULL) return false;
            if(T->data==val) return true;
            if(val<T->data){
                return Search(T->lc,val);
            }
            else{
                return Search(T->rc,val);
            }
        }
        void InorderIt(Node* T){
            Node* ptr = T;
            bool flag=true;
            stack<Node*> s;
            while(flag){
                while(ptr!=NULL){
                    s.push(ptr);
                    ptr = ptr->lc;
                }
                if(!s.empty()){
                    ptr = s.top();
                    s.pop();
                    cout<<ptr->data<<" ";
                    ptr = ptr->rc;
                }
                else
                    flag = false;
            }
        }
        void PreorderIt(Node* T){
            Node* ptr = T;
            stack<Node*> s;
            bool flag = true;
            while(flag){
                while(ptr!=NULL){
                    s.push(ptr);
                    cout<<ptr->data<<" ";
                    ptr = ptr->lc;
                }
                if(!s.empty()){
                    ptr = s.top();
                    s.pop();
                    ptr = ptr->rc;
                }
                else
                    flag = false;
            }
        }
        void PostorderIt(Node* T){
            Node* ptr = T;
            bool flag = true;
            stack<Node*> s1,s2;
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
                cout<<s2.top()->data<<" ";
                s2.pop();
            }
        }
        void InorderRec(Node* T){
            if(T==NULL) return;
            InorderRec(T->lc);
            cout<<T->data<<" ";
            InorderRec(T->rc);
        }
        void PreorderRec(Node* T){
            if(T==NULL) return;
            cout<<T->data<<" ";
            PreorderRec(T->lc);
            PreorderRec(T->rc);
        }
        void PostorderRec(Node* T){
            if(T==NULL) return;
            PostorderRec(T->lc);
            PostorderRec(T->rc);
            cout<<T->data<<" ";
        }
        void LevelByLevel(Node* T){
            if(T==NULL) return;
            queue<Node*> q;
            q.push(T);
            while(!q.empty()){
                Node* ptr = q.front();
                q.pop();
                cout<<ptr->data<<" ";
                if(ptr->lc!=NULL) q.push(ptr->lc);
                if(ptr->rc!=NULL) q.push(ptr->rc);
            }
        }
        int CountLeaf(Node* T){
            if(T==NULL) return 0;
            else if(T->lc==NULL&&T->rc==NULL) return 1;
            else return CountLeaf(T->lc)+CountLeaf(T->rc);
        }
        int CountNonLeaf(Node* T){
            if(T==NULL) return 0;
            else if(T->lc==NULL&&T->rc==NULL) return 0;
            else return 1+CountNonLeaf(T->lc)+CountNonLeaf(T->rc);
        }
        int Height(Node* T){
            if(T==NULL) return 0;
            int lh = Height(T->lc);
            int rh = Height(T->rc);
            return ((lh>rh)?lh:rh)+1;
        }
        void Mirror(Node* T){
            if(T==NULL) return;
            queue<Node*> q;
            q.push(T);
            while(!q.empty()){
                Node* ptr = q.front();
                q.pop();
                Node* t = ptr->lc;
                ptr->lc = ptr->rc;
                ptr->rc = t;
                if(ptr->lc!=NULL) q.push(ptr->lc);
                if(ptr->rc!=NULL) q.push(ptr->rc);
            }
        }
        int EqualBst(Node* T1,Node* T2){
            if(T1==NULL&&T2==NULL) return true;
            if(T1==NULL||T2==NULL) return false;
            return (T1->data==T2->data)&&EqualBst(T1->lc,T2->lc)&&EqualBst(T1->rc,T2->rc);
        }
        void insertIt(int val)        { root = InsertIt(root, val); }
        void insertRec(int val)       { root = InsertRec(root, val); }
        void delCopy(int val)         { root = DeleteByCopying(root, val); }
        void delMerge(int val)        { root = DeleteByMerging(root, val); }
        bool searchVal(int val)       { return Search(root, val); }

        void displayRec() {
            cout << "Preorder (Rec):  "; PreorderRec(root);  cout << endl;
            cout << "Inorder (Rec):   "; InorderRec(root);   cout << endl;
            cout << "Postorder (Rec): "; PostorderRec(root); cout << endl;
        }

        void displayIt() {
            cout << "Preorder (It):   "; PreorderIt(root);   cout << endl;
            cout << "Inorder (It):    "; InorderIt(root);    cout << endl;
            cout << "Postorder (It):  "; PostorderIt(root);  cout << endl;
        }

        void displayLevel() {
            cout << "Level-by-Level:  "; LevelByLevel(root); cout << endl;
        }

        int getLeafCount()            { return CountLeaf(root); }
        int getNonLeafCount()         { return CountNonLeaf(root); }
        int getHeight()               { return Height(root); }
        void createMirror()           { Mirror(root); }
        bool isEqual(BST& other)      { return EqualBst(root, other.root); }
};
int main() {
    BST tree;
    int ch, n, val;

    while (1) {
        cout << "\n--- BST MENU ---\n";
        cout << "1.  Insert (Iterative)\n";
        cout << "2.  Insert (Recursive)\n";
        cout << "3.  Delete by Copying\n";
        cout << "4.  Delete by Merging\n";
        cout << "5.  Search an Element\n";
        cout << "6.  Traversals (Recursive)\n";
        cout << "7.  Traversals (Iterative)\n";
        cout << "8.  Level-by-Level Traversal\n";
        cout << "9.  Count Leaf & Non-Leaf Nodes\n";
        cout << "10. Height of Tree\n";
        cout << "11. Mirror Image of Tree\n";
        cout << "12. Check if Two BSTs are Equal\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> val;
                    tree.insertIt(val);
                }
                break;

            case 2:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> val;
                    tree.insertRec(val);
                }
                break;

            case 3:
                cout << "Enter element to delete (Copying): ";
                cin >> val;
                tree.delCopy(val);
                cout << "Done.\n";
                break;

            case 4:
                cout << "Enter element to delete (Merging): ";
                cin >> val;
                tree.delMerge(val);
                cout << "Done.\n";
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> val;
                if (tree.searchVal(val))
                    cout << val << " is found in the BST.\n";
                else
                    cout << val << " is NOT found in the BST.\n";
                break;

            case 6:
                tree.displayRec();
                break;

            case 7:
                tree.displayIt();
                break;

            case 8:
                tree.displayLevel();
                break;

            case 9:
                cout << "Leaf nodes:     " << tree.getLeafCount() << endl;
                cout << "Non-leaf nodes: " << tree.getNonLeafCount() << endl;
                break;

            case 10:
                cout << "Height of BST: " << tree.getHeight() << endl;
                break;

            case 11:
                tree.createMirror();
                cout << "Tree mirrored. Inorder now:\n";
                tree.displayRec();
                break;

            case 12: {
                BST tree2;
                cout << "Enter number of elements for 2nd BST: ";
                cin >> n;
                cout << "Enter elements for 2nd BST: ";
                for (int i = 0; i < n; i++) {
                    cin >> val;
                    tree2.insertRec(val);
                }
                if (tree.isEqual(tree2))
                    cout << "Both BSTs are equal.\n";
                else
                    cout << "The BSTs are NOT equal.\n";
                break;
            }

            case 13:
                cout << "Exited the program.\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
































