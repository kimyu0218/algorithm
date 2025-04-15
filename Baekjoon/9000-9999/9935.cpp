#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const string FRULA = "FRULA";

void bomb_or_not(int len, string bomb, stack<char> &s) {
    stack<char> backup;

    int idx = len;
    while(idx-- && s.size() > 0) {
        if(s.top() != bomb[idx]) {
            break;
        }
        backup.push(s.top());
        s.pop();
    }

    if(backup.size() == len) {
        return;
    }
    while(!backup.empty()) {
        s.push(backup.top());
        backup.pop();
    }
}

string solution(string s1, string s2) {
    if(s2.length() > s1.length()) {
        return FRULA;
    }

    string answer = "";
    int len = s2.length();
    stack<char> s;

    for(int i = 0; i < s1.length(); i++) {
        s.push(s1[i]);
        bomb_or_not(len, s2, s);
    }

    if(s.empty()) {
        return FRULA;
    }
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    cout << solution(s1, s2);
    return 0;
}