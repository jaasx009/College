/* WAP to display Fibonacci series (i) using recursion, (ii) using iteration */
#include <iostream>
using namespace std;
class Fibonacci {
    private:
        int terms;
        long long fibRecursive(int n) {
            if (n <= 1) {
                return n;
            }
            return fibRecursive(n - 1) + fibRecursive(n - 2);
        }

    public:
        Fibonacci(int n) {
            terms = n;
        }
        void showRecursive() {
            cout << "\n--- (i) RECURSION ---\n";
            for (int i = 0; i < terms; i++) {
                cout << fibRecursive(i) << " ";
            }
            cout << "\n";
        }
        void showIterative() {
            cout << "\n--- (ii) ITERATION ---\n";
            long long a = 0;
            long long b = 1;
            long long nextTerm;
            for (int i = 0; i < terms; i++) {
                cout << a << " ";
                nextTerm = a + b;
                a = b;
                b = nextTerm;
            }
            cout << "\n";
        }
};
int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0.\n";
        return 1;
    }
    Fibonacci obj(n);
    obj.showRecursive();
    obj.showIterative();
    cout << "\n";
    return 0;
}