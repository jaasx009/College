#include <iostream>
#include <stack>
#include <queue>

using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }
    Node* insertRecursive(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    void insertRec(int val) {
        root = insertRecursive(root, val);
    }
    void insertIterative(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        Node* curr = root;
        Node* parent = nullptr;
        
        while (curr != nullptr) {
            parent = curr;
            if (val < curr->data) {
                curr = curr->left;
            } else if (val > curr->data) {
                curr = curr->right;
            } else {
                return;
            }
        }
        
        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    void deleteByCopying(int val) {
        Node* curr = root;
        Node* prev = nullptr;
        
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            if (val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        
        if (curr == nullptr) {
            cout << "Value not found in the tree.\n";
            return;
        }

        if (curr->left == nullptr || curr->right == nullptr) {
            Node* temp = (curr->left != nullptr) ? curr->left : curr->right;
            
            if (prev == nullptr) { 
                root = temp;
            } else if (prev->left == curr) {
                prev->left = temp;
            } else {
                prev->right = temp;
            }
            delete curr;
        } 
        else {
            Node* tmp = curr->left;
            Node* prevTmp = curr;
            
            while (tmp->right != nullptr) {
                prevTmp = tmp;
                tmp = tmp->right;
            }
            
            curr->data = tmp->data; 
            
            if (prevTmp == curr) {
                prevTmp->left = tmp->left;
            } else {
                prevTmp->right = tmp->left;
            }
            delete tmp;
        }
        cout << "Node deleted successfully.\n";
    }
    void deleteByMerging(int val) {
        Node* curr = root;
        Node* prev = nullptr;
        
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            if (val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        
        if (curr == nullptr) {
            cout << "Value not found in the tree.\n";
            return;
        }

        Node* temp = curr;
        if (curr->left != nullptr && curr->right != nullptr) {
            Node* pred = curr->left;
            while (pred->right != nullptr) {
                pred = pred->right;
            }
            pred->right = curr->right; 
            curr = curr->left;
        } else if (curr->left != nullptr) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        if (prev == nullptr) {
            root = curr;
        } else if (prev->left == temp) {
            prev->left = curr;
        } else {
            prev->right = curr;
        }
        delete temp;
        cout << "Node deleted successfully.\n";
    }
    bool search(int val) {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->data == val) return true;
            if (val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }
    void preorderRecursive(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void inorderRecursive(Node* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void postorderRecursive(Node* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }
    void preorderIterative() {
        if (root == nullptr) return;
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();
            cout << curr->data << " ";
            
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }
    }

    void inorderIterative() {
        stack<Node*> s;
        Node* curr = root;
        
        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void postorderIterative() {
        if (root == nullptr) return;
        stack<Node*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);
            
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
        
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
    void levelOrder() {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    int countLeaves(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int countNonLeaves(Node* node) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) return 0;
        return 1 + countNonLeaves(node->left) + countNonLeaves(node->right);
    }
    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    void mirror(Node* node) {
        if (node == nullptr) return;
        
        mirror(node->left);
        mirror(node->right);
        
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    bool isEqual(Node* root1, Node* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 != nullptr && root2 != nullptr) {
            return (root1->data == root2->data) &&
                   isEqual(root1->left, root2->left) &&
                   isEqual(root1->right, root2->right);
        }
        return false;
    }
};

int main() {
    BST tree;
    int choice, val, n;

    while (true) {
        cout << "\n===============================";
        cout << "\n      BST OPERATIONS MENU      ";
        cout << "\n===============================\n";
        cout << "1. Insert (Recursive)\n";
        cout << "2. Insert (Iterative)\n";
        cout << "3. Delete by copying\n";
        cout << "4. Delete by Merging\n";
        cout << "5. Search a number\n";
        cout << "6. Display Traversals (Recursive)\n";
        cout << "7. Display Traversals (Iterative)\n";
        cout << "8. Display Level-by-level traversal\n";
        cout << "9. Count non-leaf and leaf nodes\n";
        cout << "10. Display height of tree\n";
        cout << "11. Create a mirror image of tree\n";
        cout << "12. Check whether two BSTs are equal\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insertRec(val);
                cout << val << " inserted.\n";
                break;
                
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insertIterative(val);
                cout << val << " inserted.\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteByCopying(val);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteByMerging(val);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                if (tree.search(val))
                    cout << val << " is found in the BST.\n";
                else
                    cout << val << " is NOT found in the BST.\n";
                break;

            case 6:
                cout << "\nPreorder: "; tree.preorderRecursive(tree.root);
                cout << "\nInorder: "; tree.inorderRecursive(tree.root);
                cout << "\nPostorder: "; tree.postorderRecursive(tree.root);
                cout << "\n";
                break;

            case 7:
                cout << "\nPreorder: "; tree.preorderIterative();
                cout << "\nInorder: "; tree.inorderIterative();
                cout << "\nPostorder: "; tree.postorderIterative();
                cout << "\n";
                break;

            case 8:
                cout << "\nLevel-by-level: "; 
                tree.levelOrder();
                cout << "\n";
                break;

            case 9:
                cout << "Number of Leaf nodes: " << tree.countLeaves(tree.root) << "\n";
                cout << "Number of Non-leaf nodes: " << tree.countNonLeaves(tree.root) << "\n";
                break;

            case 10:
                cout << "Height of the tree: " << tree.height(tree.root) << "\n";
                break;

            case 11:
                tree.mirror(tree.root);
                cout << "Mirror image created successfully. (Use traversal options to view)\n";
                break;
            case 12: {
                BST tree2;
                cout << "Enter the number of elements for the second tree: ";
                cin >> n;
                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> val;
                    tree2.insertIterative(val);
                }
                if (tree.isEqual(tree.root, tree2.root))
                    cout << "The two BSTs are EQUAL.\n";
                else
                    cout << "The two BSTs are NOT EQUAL.\n";
                break;
            }
            case 13:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
