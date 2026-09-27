/* WAP to calculate factorial and to compute the factors of a given no. (i) using recursion, 
(ii) using iteration*/
#include <iostream>
using namespace std;
class Number {
    private:
        long long num;
        long long calcFactRec(long long n, long long p) {
            if (n == 0 || n == 1) return p;
            return calcFactRec(n - 1, n * p); 
        }        
        void calcFactorsRec(long long n, long long i) {
            if (i > n) {
                cout << "\n";
                return;
            }
            if (n % i == 0) {
                cout << i << " ";
            }
            calcFactorsRec(n, i + 1); 
        }
    public:
        Number(long long val) {
            num = val;
        }        
        void showRecursive() {
            cout << "\n--- (i) RECURSION ---";
            cout << "\nFactorial of " << num << ": " << calcFactRec(num, 1);
            cout << "\nFactors of " << num << ": ";
            calcFactorsRec(num, 1); 
        }        
        void showIterative() {
            cout << "\n--- (ii) ITERATION ---";
            long long fact = 1;
            for (long long i = 1; i <= num; i++) {
                fact *= i;
            }
            cout << "\nFactorial of " << num << ": " << fact;
            cout << "\nFactors of " << num << ": ";
            for (long long i = 1; i <= num; i++) {
                if (num % i == 0) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
};
int main() {
    long long input;
    cout << "Enter a positive integer: ";
    cin >> input;
    
    if (input < 0) {
        cout << "Factorial is not defined for negative numbers.\n";
        return 1;
    }    
    Number obj(input);
    obj.showRecursive();
    obj.showIterative();
    return 0;
}