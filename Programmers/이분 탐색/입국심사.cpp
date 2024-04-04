#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool can_pass(ll k, int n, int m, vector<int> times) {
    ll cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += k / times[i];
        if(cnt >= n) {
            return true;
        }
    }
    return false;
}

ll solution(int n, vector<int> times) {
    ll answer = 0;
    int m = times.size();

    sort(times.begin(), times.end());

    ll left = times[0];
    ll right = (ll) times[m - 1] * n;

    while(left <= right) {
        ll mid = (left + right) / 2;
        bool pass = can_pass(mid, n, m, times);

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