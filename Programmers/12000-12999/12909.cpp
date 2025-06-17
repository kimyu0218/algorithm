#include <string>
#include <iostream>
#include <stack>

using namespace std;

const char LBRACE = '(';

bool solution(string s) {
    stack<char> st;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(s[i] == LBRACE) {
            st.push(s[i]);
            continue;
        }

        if(st.empty()) {
            return false;
        }
        st.pop();
    }
    return st.empty();
}