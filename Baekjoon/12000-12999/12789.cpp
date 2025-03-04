#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const string NICE = "Nice";
const string SAD = "Sad";

string solution(vector<int> students) {
    int n = students.size();
    int last = 0;
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        if(s.empty() || students[i] < s.top()) {
            s.push(students[i]);
        }
        else {
            return SAD;
        }
        while(!s.empty() && s.top() == last + 1) {
            last = s.top();
            s.pop();
        }
    }
    return NICE;
}

int main() {
    int n;
    vector<int> students;
    
    cin >> n;
    
    students.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> students[i];
    }
    
    cout << solution(students);
    return 0;
}