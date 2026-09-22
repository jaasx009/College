 /*WAP to calculate factorial and to compute the factors of a given no. (i) using recursion, 
(ii) using iteration*/
#include <iostream>
using namespace std;
long factorialIterative(int n) {
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
void factorsIterative(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}
long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}
void factorsRecursive(int n, int i) {
    if (i > n) {
        cout << endl;
        return;
    }
    if (n % i == 0) {
        cout << i << " ";
    }
    factorsRecursive(n, i + 1);
}
int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial and factors are generally calculated for positive integers." << endl;
        return 1;
    }
    cout << "\n========== ITERATIVE METHOD ==========\n";
    cout << "Factorial of " << num << " is: " << factorialIterative(num) << "\n";
    cout << "Factors of " << num << " are: ";
    factorsIterative(num);
    cout << "\n========== RECURSIVE METHOD ==========\n";
    cout << "Factorial of " << num << " is: " << factorialRecursive(num) << "\n";
    cout << "Factors of " << num << " are: ";
    factorsRecursive(num, 1); 
    return 0;
}