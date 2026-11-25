#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

class PostfixEval {
    private:
        string postfix;
        int result;

    public:
        PostfixEval() {
            postfix = "";
            result = 0;
        }

        void getdata() {
            cout << "Enter postfix expression (single-digit operands): ";
            getline(cin, postfix);
        }

        void evaluate() {
            stack<int> s;

            for (int i = 0; i < postfix.length(); i++) {
                char ch = postfix[i];

                if (ch == ' ') continue;

                if (isdigit(ch)) {
                    s.push(ch - '0');
                }
                else {
                    int op2 = s.top(); s.pop();
                    int op1 = s.top(); s.pop();

                    switch (ch) {
                        case '+': s.push(op1 + op2); break;
                        case '-': s.push(op1 - op2); break;
                        case '*': s.push(op1 * op2); break;
                        case '/': s.push(op1 / op2); break;
                        case '^': s.push(pow(op1, op2)); break;
                    }
                }
            }

            if (!s.empty()) {
                result = s.top();
            }
        }

        void display() {
            cout << "Evaluated Result: " << result << endl;
        }
};

int main() {
    PostfixEval p;
    p.getdata();
    p.evaluate();
    p.display();
    return 0;
}
