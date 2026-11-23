//WAP to calculate factorial and to compute the factors of a given no. (i) using recursion, (ii) using itteration.
#include<iostream>
using namespace std;
class Fact{
    public:
        //itteration.
        int Ifactorial(int n){
            int fact = 1;
            int m = n;
            while(m>0){
                fact *= m;
                m--;
            }
            return fact;
        }
        void Ifactor(int n){
            int m = n;
            for(int i=1;i<=m;i++){
                if(m%i==0){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
        //recursion
        int Rfactorial(int n,int f=1){
            if(n==0)
                return f;
            else
                return Rfactorial(n-1,f*n);
        }
        void Rfactor(int n, int i=1){
            if(i>n){
                cout<<endl;
                return;
            }
            if(n%i==0)
                cout<<i<<" ";
            Rfactor(n,i+1);
        }
};
int main(){
    Fact f;
    cout<<"Enter the number : ";
    int n;
    cin>>n;
    int fact = f.Rfactorial(n);
    cout<<"Factorial : "<<fact<<endl;
    f.Rfactor(n);
    return 0;
}
































