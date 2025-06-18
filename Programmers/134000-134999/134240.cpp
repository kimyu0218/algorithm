#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int n = food.size();
    stack<char> s;

    for(int i = 1; i < n; i++) {
        char ch = i + '0';
        int cnt = food[i] / 2;
        for(int j = 0; j < cnt; j++) {
            answer += ch;
            s.push(ch);
        }
    }
    answer += '0';
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    return answer;
}