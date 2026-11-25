#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;
class ItoP{
    private:
        string infix;
        string postfix;
        int prec(char ch){
            if(ch=='+'||ch=='-') return 1;
            if(ch=='*'||ch=='/') return 2;
            if(ch=='^') return 3;
            return 0;
        }
    public:
        ItoP(){
            infix = "";
            postfix = "";
        }
        void getInfix(){
            cout<<"Enter the string : ";
            getline(cin,infix);
        }
        void infix_postfix(){
            postfix = "";
            stack<char> s;
            for(int i=0;i<infix.length();i++){
                char ch = infix[i];
                if(ch==' ') continue;
                if(isalnum(ch))
                    postfix += ch;
                else if(ch=='(')
                    s.push('(');
                else if(ch==')'){
                    while(!s.empty()&&s.top()!='('){
                        postfix += s.top();
                        s.pop();
                    }
                    if(!s.empty()){
                        s.pop();
                    }
                }
                else{
                    while(!s.empty()&&prec(s.top())>=prec(ch)&&ch!='^'){
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(ch);
                }
            }
            while(!s.empty()){
                postfix += s.top();
                s.pop();
            }
        }
        void display(){
            cout<<postfix<<" ";
        }
};
int main(){
    ItoP e;
    e.getInfix();
    e.infix_postfix();
    e.display();
    return 0;
}
































