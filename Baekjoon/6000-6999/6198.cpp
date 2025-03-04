#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

ll cntBenchmarking(int n, vector<int> &h) {
    ll cnt = 0;
    stack<int> s;

    for(int i = 0; i < n; i++) {
        // h[i] 집어넣기 전, 건물 높이 확인
        while(!s.empty() && h[i] >= s.top()) {
            s.pop();
        }
        cnt += s.size();
        s.push(h[i]); // h[i] 집어넣기
    }
    return cnt;
}

int main() {
    int n;
    vector<int> h; // 빌딩 높이

    cin >> n;
    h.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cout << cntBenchmarking(n, h);
    return 0;
}