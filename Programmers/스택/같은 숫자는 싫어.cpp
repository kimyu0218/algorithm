#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer, rev;

    stack<int> s;
    for(int i = 0; i < arr.size(); i++) {
        // 스택이 비어있거나 이전 수와 다른 수가 들어왔을 때
        if(s.empty() || arr[i] != s.top()) s.push(arr[i]);
    }

    while(!s.empty()) {
        rev.push_back(s.top());
        s.pop();
    }
    for(int i = rev.size()-1; i >= 0; i--)
        answer.push_back(rev[i]);
    return answer;
}