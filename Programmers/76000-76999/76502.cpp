#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

bool is_lbrace(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool is_correct_string(queue<char> q) {
    stack<char> s;
    map<char, char> lbrace = {
        { ')', '(' }, { ']', '[' }, { '}', '{' }
    };

    while(!q.empty()) {
        char ch = q.front();
        q.pop();

        if(is_lbrace(ch)) {
            s.push(ch);
            continue;
        }

        if(s.empty() || s.top() != lbrace[ch]) {
            return false;
        }
        s.pop();
    }
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        int idx = i;
        queue<char> q;

        do {
            q.push(s[idx]);
            idx = (idx + 1) % n;
        } while(idx != i);

        answer += is_correct_string(q);
    }
    return answer;
}