#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> t; // 심사 시간

// m명의 사람이 심사를 마치는데 걸리는 최소 시간은?
// == 심사 시간이 k일 때 m명의 사람의 사람을 심사할 수 있는가?
ll cnt_pass(ll k, int n) {
    ll cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += k/t[i];
    return cnt;
}

ll min_time(ll left, ll right, int n, int m) {
    ll ans = 0;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll pass = cnt_pass(mid, n);

        if(pass >= m) { // 1. m명 이상의 사람 통과 -> 총 심사 시간 줄이기
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1; // 2. m명의 사람 통과 불가 -> 총 심사 시간 늘리기
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    t.assign(n, 0);
    for(int i = 0; i < n; i++) // 심사 시간 입력
        cin >> t[i];
    sort(t.begin(), t.end());

    cout << min_time((ll) t[0], (ll) t[n-1] * m, n, m);
    return 0;
}