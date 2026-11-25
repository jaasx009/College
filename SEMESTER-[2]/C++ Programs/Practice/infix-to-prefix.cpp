#include<iostream>
#include<string>
#include<stack>
#include<cctype>
#include<algorithm>
using namespace std;
class ItoP{
    private:
        string infix;
        string prefix;
    public:
        ItoP(){
            infix = "";
            prefix = "";
        }
        void getdata(){
            cout<<"Enter the string : ";
            getline(cin,infix);
        }
        int prec(char ch){
            if(ch=='+'||ch=='-') return 1;
            if(ch=='*'||ch=='/') return 2;
            if(ch=='^') return 3;
            return 0;
        }
        void infix_prefix(){
            prefix = "";
            stack<char> s;
            for(int i=infix.length()-1;i>=0;i--){
                char ch = infix[i];
                if(ch==' ') continue;
                if(isalnum(ch))
                    prefix += ch;
                else if(ch==')')
                    s.push(')');
                else if(ch=='('){
                    while(!s.empty()&&s.top()!=')'){
                        prefix += s.top();
                        s.pop();
                    }
                    if(!s.empty())
                        s.pop();
                }
                else{
                    while(!s.empty()&&(prec(s.top())>prec(ch)||(prec(s.top())==prec(ch)&&ch=='^'))){
                        prefix += s.top();
                        s.pop();
                    }
                        s.push(ch);
                }
            }
            while(!s.empty()){
                prefix += s.top();
                s.pop();
            }
            reverse(prefix.begin(),prefix.end());
        }
        void display(){
            cout<<prefix<<" "<<endl;
        }
};
int main(){
    ItoP p;
    p.getdata();
    p.infix_prefix();
    p.display();
    return 0;
}































