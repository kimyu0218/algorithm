#include <iostream>
#include <vector>

using namespace std;

typedef long long ll; // 교시의 최댓값이 50이므로 int(32bit)는 부족함

int solution(ll q, int n, vector<ll> &t) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        ll all = q | t[i];
        if(all == q) { // q가 수업 커버 가능
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m, k, p;
    ll q, x;
    vector<ll> t;

    cin >> n;
    t.assign(n, 0);
    for(int i = 0; i < n; i++) { // 과목 정보 입력
        cin >> k;
        for(int j = 0; j < k; j++) { // 과목 수업시간 입력
            cin >> x;
            t[i] |= ((ll) 1 << x); // (== x교시에 강의 있음)
        }
    }

    cin >> m;
    while(m--) { // 학생 정보 입력
        cin >> p;
        q = 0;
        for(int i = 0; i < p; i++) { // 학생들의 비어있는 교시 입력
            cin >> x;
            q |= ((ll) 1 << x); // (== x교시에 공강임)
        }
        cout << solution(q, n, t) << '\n';
    }
    return 0;
}