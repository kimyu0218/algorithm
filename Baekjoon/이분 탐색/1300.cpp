#include <iostream>

using namespace std;
typedef long long ll;

ll cntSmall(ll mid, ll n) { // mid보다 작거나 같은 수 세기
    ll cnt = 0;
    for(int i = 1; i <= n; i++) { // i : 행
        cnt += min(mid / i, n);
    }
    return cnt;
}

ll binarySearch(ll n, int k) {
    ll answer, left = 1, right = n * n;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = cntSmall(mid, n);

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
    cout << binarySearch(n, k);
    return 0;
}