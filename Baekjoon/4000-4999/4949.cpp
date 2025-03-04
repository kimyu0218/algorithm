#include <iostream>
#include <stack>

using namespace std;

bool solution(string input) {
    stack<char> s;
    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if(ch == '(' || ch == '[') {
            s.push(ch);
        }
        else if(ch == ')') {
            if(s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
        else if(ch == ']') {
            if(s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string input;

    while(true) {
        getline(cin, input);

        if(input == ".") {
            break;
        }
        string result = solution(input) ? "yes" : "no";

        cout << result << '\n';
    }
    return 0;
}