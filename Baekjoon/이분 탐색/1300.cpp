#include <iostream>

using namespace std;

typedef long long ll;

ll cnt_small(ll k, ll n) {
    ll answer = 0;
    for(int i = 1; i <= n; i++) {
        answer += min(k / i, n);
    }
    return answer;
}

ll solution(int n, int k) {
    ll answer = 0;
    ll left = 1;
    ll right = (ll) n * n;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = cnt_small(mid, n);

        if(cnt >= k) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, k;

    cin >> n >> k;

    cout << solution(n, k);
    return 0;
}