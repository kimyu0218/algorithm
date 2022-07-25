#include <iostream>
#include <stack>

using namespace std;

int pri(char ch) { // 연산자 우선순위
    switch(ch) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void make_postfix(string &exp) { // 후위 표기식 만들기
    stack<char> temp; // 연산자 저장하는 스택

    for(int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        switch(ch) {
            case '(':
                temp.push(ch); break; // 여는 괄호 PUSH
            case '+': case '-': case '*': case '/': // 연산자 PUSH
                while(!temp.empty() && pri(temp.top()) >= pri(ch)) {
                    cout << temp.top();
                    temp.pop();
                }
                temp.push(ch);
                break;
            case ')': // 닫는 괄호 나온 경우 : 스택에 있는 연산자 출력 & POP
                while(temp.top() != '(') {
                    cout << temp.top();
                    temp.pop();
                }
                if(temp.top() == '(') temp.pop(); // 여는 괄호 POP
                break;
            default: cout << ch; // 피연산자 출력
        }
    }
    while(!temp.empty()) { // 스택에 남아있는 연산자 출력
        cout << temp.top();
        temp.pop();
    }
}

int main() {
    string exp;
    cin >> exp;

    make_postfix(exp);
    return 0;
}