#include <iostream>
#include <set>

using namespace std;

set<string> solution(string s) {
    set<string> answer;

    int len = s.length();
    for(int i = 0; i < len; i++) {
        string prefix = s.substr(i, len);
        answer.insert(prefix);
    }
    return answer;
}

int main() {
    string s;

    cin >> s;

    set<string> answer = solution(s);

    for(auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << '\n';
    }
    return 0;
}