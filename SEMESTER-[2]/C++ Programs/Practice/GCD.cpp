#include<iostream>
using namespace std;
class GCD{
    private:
        int x,y;
    public:
        GCD(){
            x = 0;
            y = 0;
        }
        void getdata(){
            cout<<"Enter two numbers : ";
            cin>>x>>y;
        }
        int gcd(int x,int y){
            if(y==0) return x;
            return gcd(y,x%y);
        }
        int gcdrec(){
            return gcd(x,y);
        }
        void display(){
            cout<<"GCD is "<<gcdrec()<<endl;
        }
};
int main(){
    GCD g;
    g.getdata();
    g.display();
    return 0;
}
