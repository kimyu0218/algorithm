#include <iostream>
#include <stack>

using namespace std;

void backspace(stack<char> &s) {
    if(!s.empty()) s.pop();
}

void leftCursor(stack<char> &s, stack<char> &t) {
    if(!s.empty()) {
        t.push(s.top());
        s.pop();
    }
}

void rightCursor(stack<char> &s, stack<char> &t) {
    if(!t.empty()) {
        s.push(t.top());
        t.pop();
    }
}

string findPassword(string input) {
    string pw; // 패스워드 저장

    stack<char> s, t;
    for(int i = 0; i < input.length(); i++) {
        switch(input[i]) {
            case '-': // 백스페이스
                backspace(s); break;
            case '<': // 왼쪽 커서
                leftCursor(s, t); break;
            case '>': // 오른쪽 커서
                rightCursor(s, t); break;
            default:
                s.push(input[i]);
        }
    }

    while(!s.empty()) { // 순서가 거꾸로 된 패스워드 다른 스택으로 옮기기
        t.push(s.top());
        s.pop();
    }

    while(!t.empty()) { // 패스워드 순서대로 재정렬
        pw += t.top();
        t.pop();
    }
    return pw;
}

int main() {
    int t;
    cin >> t;

    string input;
    while(t--) {
        cin >> input;
        cout << findPassword(input) << '\n';
    }
    return 0;
}