//WAP to display Fibonacci series (i) using recursion, (ii) using iteration
#include<iostream>
using namespace std;
class Fib{
    public:
        //Iteration
        void Ifibonacci(int n){
            int a = 0;
            int b = 1;
            cout<<a<<" ";
            while(n>1){
                cout<<b<<" ";
                int c = a + b;
                a = b;
                b = c;
                n--;
            }
            cout<<endl;
        }
        //Recursion
        void Rfibonacci(int n,int a=0,int b=1){
            if(n<=0){
                cout<<endl;
                return;
            }
            cout<<a<<" ";
            Rfibonacci(n-1,b,a+b);
        }
};
int main(){
    Fib f;
    cout<<"Enter the number : ";
    int n;
    cin>>n;
    f.Rfibonacci(n);
    return 0;
}
























