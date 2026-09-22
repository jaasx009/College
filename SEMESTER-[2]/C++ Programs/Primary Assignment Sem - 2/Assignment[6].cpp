 /*WAP to display Fibonacci series (i) using recursion, (ii) using iteration*/
#include <iostream>
using namespace std;
void displayFibonacciIterative(int n) {
    long first = 0, second = 1, next;

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << " ";
    }
    cout << endl;
}
long fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
void displayFibonacciRecursiveSeries(int terms) {
    for (int i = 0; i < terms; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    cout << "\n========== ITERATIVE METHOD ==========\n";
    cout << "Fibonacci Series up to " << n << " terms: \n";
    displayFibonacciIterative(n);
    cout << "\n========== RECURSIVE METHOD ==========\n";
    cout << "Fibonacci Series up to " << n << " terms: \n";
    displayFibonacciRecursiveSeries(n);
    return 0;
}