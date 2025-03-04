#include <iostream>
#include <stack>

using namespace std;

bool checkParen(string paren) {
    stack<char> s;
    for(char & i : paren) {
        if(i == '(') s.push(i); // 여는 괄호 : 무조건 push
        else {                  // 닫는 괄호 : pop or false
            if(!s.empty()) s.pop();
            else return false;
        }
    }
    // 여는 괄호와 닫는 괄호 수 일치 확인
    if(s.empty()) return true;
    else return false;
}

int main() {
    int t;
    cin >> t;

    string input;
    bool correct;

    while(t--) {
        cin >> input;
        correct = checkParen(input);
        if(correct) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}