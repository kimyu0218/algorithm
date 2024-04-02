#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int cnt = 0;
    int len = number.length();
    stack<char> s;

    for(int i = 0; i < len; i++) {
        char num = number[i];

        while(!s.empty() && cnt < k && s.top() < num) {
            s.pop();
            cnt++;
        }
        s.push(num);
    }

    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer.substr(0, len - k);
}