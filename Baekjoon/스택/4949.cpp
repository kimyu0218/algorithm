#include <iostream>
#include <stack>

using namespace std;

bool checkParen(string input) {
    stack<char> s;
    char top;

    for(char & i : input) {
        switch(i) {
            // 여는 괄호 : 무조건 push
            case '(':
            case '[':
                s.push(i);
                break;
            // 닫는 괄호 : 균형 check
            case ')':
                if(s.empty() || s.top() != '(') return false;
                s.pop(); break;
            case ']':
                if(s.empty() || s.top() != '[') return false;
                s.pop(); break;
        }
    }
    // 여는 괄호와 닫는 괄호 수 일치 여부 확인
    if(s.empty()) return true;
    else return false;
}

int main() {
    string input;
    bool balance;

    while(true) {
        getline(cin, input);
        if(input == ".") break; // 입력 종료 조건

        balance = checkParen(input);
        if(balance) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}