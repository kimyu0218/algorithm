#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> len; // 랜선 길이 저장

ll cnt_cable(int mid, int k) { // 길이가 mid인 랜선 개수
    ll cnt = 0;
    for(int i = 0; i < k; i++)
        cnt += (len[i] / mid);
    return cnt;
}

ll binary_search(ll left, ll right, int k, int n) {
    ll ans;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cable = cnt_cable(mid, k);

        if(cable >= n) { // n개의 랜선 만들기 성공 -> 최대 길이 늘리기
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1; // n개의 랜선 만들기 실패 -> 최대 길이 줄이기
    }
    return ans;
}

int main() {
    int k, n;
    ll max_len = 0;
    cin >> k >> n;

    len.assign(k, 0);
    for(int i = 0; i < k; i++) { // 랜선 길이 입력
        cin >> len[i];
        max_len = max(max_len, len[i]);
    }

    cout << binary_search(1, max_len, k, n);
    return 0;
}