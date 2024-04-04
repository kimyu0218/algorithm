#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool can_pass(ll k, int m, int n, vector<int> t) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += k / t[i];
        if(cnt >= m) {
            return true;
        }
    }
    return false;
}

ll solution(int m, vector<int> t) {
    ll answer = 0;
    int n = t.size();

    sort(t.begin(), t.end());

    ll left = t[0];
    ll right = (ll) t[n - 1] * m;

    while(left <= right) {
        ll mid = (left + right) / 2;
        bool pass = can_pass(mid, m, n, t);

        if(pass) {
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
    int n, m;
    vector<int> t;

    cin >> n >> m;

    t.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    cout << solution(m, t);
    return 0;
}