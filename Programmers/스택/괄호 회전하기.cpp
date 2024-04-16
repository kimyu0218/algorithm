#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_left_brace(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool is_pair(char right, char left) {
    switch(right) {
        case ')':
            return left == '(';
        case ']':
            return left == '[';
        case '}':
            return left == '{';
    }
}

bool is_correct_string(string s, int x, int len) {
    int idx = x;
    stack<char> st;

    st.push(s[idx]);
    idx = (idx + 1) % len;

    while(idx != x) {
        char ch = s[idx];
        if(is_left_brace(ch)) {
            st.push(ch);
            idx = (idx + 1) % len;
            continue;
        }
        if(!st.empty() && is_pair(ch, st.top())) {
            st.pop();
            idx = (idx + 1) % len;
            continue;
        }
        return false;
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int len = s.length();

    for(int i = 0; i < len; i++) {
        if(!is_left_brace(s[i])) {
            continue;
        }
        answer += is_correct_string(s, i, len);
    }
    return answer;
}