#include <iostream>
#include <stack>

using namespace std;

const char LEFT = '(';

int solution(string s) {
    int answer = 0;
    int len = s.length();
    stack<char> st;

    for(int i = 0; i < len; i++) {
        char ch = s[i];
        if(ch == LEFT) {
            st.push(ch);
            continue;
        }

        if(st.empty()) {
            answer++;
        }
        else {
            st.pop();
        }
    }
    return answer + st.size();
}

int main() {
    string s;

    cin >> s;

    cout << solution(s);
    return 0;
}