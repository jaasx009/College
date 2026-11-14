/* 
Implement Linked List. Include functions for insertion, deletion and search of a number, 
reverse the list and concatenate two linked lists (include a function and also overload operator +).
*/
#include <iostream>
using namespace std;

class Node {
    public:
        int info;
        Node* next;
        
        Node(int val) {
            info = val;
            next = NULL;
        }
};

class LinkedList {
    private:
        Node* head;
        
    public:
        LinkedList() {
            head = NULL;
        }
        void insert(int n) {
            Node* ptr = new Node(n);
            if (head == NULL) {
                head = ptr;
            } else {
                Node* t = head;
                while (t->next != NULL) {
                    t = t->next;
                }
                t->next = ptr;
            }
            cout << n << " inserted.\n";
        }
        void remove(int n) {
            if (head == NULL) {
                cout << "List is empty.\n";
                return;
            }
            if (head->info == n) {
                Node* t = head;
                head = head->next;
                delete t;
                cout << n << " deleted from the list.\n";
                return;
            }
            Node* prev = NULL;
            Node* curr = head;
            while (curr != NULL && curr->info != n) {
                prev = curr;
                curr = curr->next;
            }
            
            if (curr == NULL) {
                cout << n << " not found in the list.\n";
                return;
            }
            prev->next = curr->next;
            delete curr;
            cout << n << " deleted from the list.\n";
        }
        bool search(int n) const {
            Node* t = head;
            int pos = 1;
            while (t != NULL) {
                if (t->info == n) {
                    cout << "Number " << n << " found at position " << pos << ".\n";
                    return true;
                }
                t = t->next;
                pos++;
            }
            cout << "Number " << n << " not found in the list.\n";
            return false;
        }
        void reverse() {
            if (head == NULL || head->next == NULL) return;
            
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            cout << "List successfully reversed.\n";
        }
        void concatenate(LinkedList &list2) {
            if (head == NULL) {
                head = list2.head;
            } else {
                Node* t = head;
                while (t->next != NULL) {
                    t = t->next;
                }
                t->next = list2.head;
            }
            list2.head = NULL; 
            cout << "Lists concatenated successfully.\n";
        }
        LinkedList operator+(const LinkedList &list2) const {
            LinkedList newList;
            
            Node* t1 = this->head;
            while (t1 != NULL) {
                newList.insert(t1->info);
                t1 = t1->next;
            }
            
            Node* t2 = list2.head;
            while (t2 != NULL) {
                newList.insert(t2->info);
                t2 = t2->next;
            }
            return newList;
        }

        void display() const {
            if (head == NULL) {
                cout << "List is empty.\n";
                return;
            }
            Node* t = head;
            cout << "List: ";
            while (t != NULL) {
                cout << "[" << t->info << "] -> ";
                t = t->next;
            }
            cout << "NULL\n";
        }

        ~LinkedList() {
            Node* t;
            while (head != NULL) {
                t = head;
                head = head->next;
                delete t;
            }
        }
};

int main() {
    LinkedList list1;
    int ch, n;

    while (true) {
        cout << "\n--- LINKED LIST OPERATIONS ---\n";
        cout << "1. Insert a number\n";
        cout << "2. Delete a number\n";
        cout << "3. Search for a number\n";
        cout << "4. Reverse the list\n";
        cout << "5. Concatenate two lists (Using Function)\n";
        cout << "6. Concatenate two lists (Using Operator +)\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> n;
                list1.insert(n);
                break;
            case 2:
                cout << "Enter number to delete: ";
                cin >> n;
                list1.remove(n);
                break;
            case 3:
                cout << "Enter number to search: ";
                cin >> n;
                list1.search(n);
                break;
            case 4:
                list1.reverse();
                break;
            case 5: {
                LinkedList list2;
                int size, num;
                cout << "Enter the size of the second list: ";
                cin >> size;
                cout << "Enter " << size << " elements for the second list:\n";
                for (int i = 0; i < size; i++) {
                    cin >> num;
                    list2.insert(num);
                }
                list1.concatenate(list2);
                break;
            }
            case 6: {
                LinkedList list2;
                int size, num;
                cout << "Enter the size of the second list: ";
                cin >> size;
                cout << "Enter " << size << " elements for the second list:\n";
                for (int i = 0; i < size; i++) {
                    cin >> num;
                    list2.insert(num);
                }
                
                cout << "\n--- Generating Third List using (+) Operator ---\n";
                LinkedList list3 = list1 + list2;
                list3.display();
                break;
            }
            case 7:
                list1.display();
                break;
            case 0:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}