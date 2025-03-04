#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) {
    switch(ch) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
}

string solution(string input) {
    string result = "";
    stack<char> s;

    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }
        if(ch == '(') {
            s.push(ch);
            continue;
        }
        if(ch >= 'A' && ch <= 'Z') {
            result += ch;
            continue;
        }
        if(s.empty()) {
            s.push(ch);
            continue;
        }
        int curr = priority(ch);
        if(priority(s.top()) < curr) {
            s.push(ch);
            continue;
        }
        while(!s.empty() && priority(s.top()) >= curr) {
            result += s.top();
            s.pop();
        }
        s.push(ch);
    }
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    string input;

    cin >> input;

    cout << solution(input);
    return 0;
}