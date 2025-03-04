#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;

vector<int> nge(int n, vector<int> &a) {
    vector<int> answer (n, -1);
    stack<pi> s; // (first : a[i], second : i)

    for(int i = 0; i < n; i++) {
        // a[i] 넣기 전, i-1전까지 오큰수 세팅
        while(!s.empty() && a[i] > s.top().first) {
            int idx = s.top().second;
            s.pop();
            answer[idx] = a[i]; // == idx번째 오큰수는 a[i]가 된다
        }
        s.push({a[i], i}); // a[i] 집어넣기
    }
    return answer;
}

int main() {
    int n;
    vector<int> a;

    cin >> n;
    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> answer = nge(n, a);
    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}