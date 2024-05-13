#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cnt_balloon(ll k, int n, vector<int> a) {
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (k / a[i]);
    }
    return answer;
}

ll solution(int m, vector<int> a) {
    ll answer = 0;
    int n = a.size();

    sort(a.begin(), a.end());

    ll left = a[0];
    ll right = (ll) a[n - 1] * m;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll balloon = cnt_balloon(mid, n, a);

        if(balloon >= m) {
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
    vector<int> a;

    cin >> n >> m;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(m, a);
    return 0;
}