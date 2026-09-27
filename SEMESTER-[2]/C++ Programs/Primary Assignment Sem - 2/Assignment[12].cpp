/* WAP to scan a polynomial using linked list and add two polynomials. */
#include <iostream>
using namespace std;
class Node {
public:
    int coeff;
    int exp;
    Node *next;
    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};
class Polynomial {
private:
    Node *head;
public:
    Polynomial() {
        head = NULL;
    }
    void insertTerm(int c, int e) {
        if (c == 0) return;
        Node *ptr = new Node(c, e);
        if (head == NULL || head->exp < e) {
            ptr->next = head;
            head = ptr;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && temp->exp >= e) {
            if (temp->exp == e) {
                temp->coeff += c;
                delete ptr; 
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        ptr->next = temp;
        prev->next = ptr;
    }
    void create() {
        int n, c, e;
        cout << "How many terms in this polynomial? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Term " << (i + 1) << " (Format: Coefficient Exponent): ";
            cin >> c >> e;
            insertTerm(c, e);
        }
    }
    void add(Polynomial p1, Polynomial p2) {
        Node *t1 = p1.head;
        Node *t2 = p2.head;
        while (t1 != NULL && t2 != NULL) {
            if (t1->exp == t2->exp) {
                insertTerm(t1->coeff + t2->coeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            } 
            else if (t1->exp > t2->exp) {
                insertTerm(t1->coeff, t1->exp);
                t1 = t1->next;
            } 
            else {
                insertTerm(t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }
        while (t1 != NULL) {
            insertTerm(t1->coeff, t1->exp);
            t1 = t1->next;
        }
        while (t2 != NULL) {
            insertTerm(t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "0\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp;
            temp = temp->next;
            if (temp != NULL) {
                if (temp->coeff > 0) cout << " + ";
                else cout << " ";
            }
        }
        cout << "\n";
    }
    ~Polynomial() {
        Node *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    Polynomial poly1, poly2, result;
    cout << "\n--- Enter First Polynomial ---\n";
    poly1.create();
    cout << "\n--- Enter Second Polynomial ---\n";
    poly2.create();
    cout << "\nPolynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();
    result.add(poly1, poly2);
    cout << "\nResultant Polynomial: ";
    result.display();
    cout << "\n";
    return 0;
}