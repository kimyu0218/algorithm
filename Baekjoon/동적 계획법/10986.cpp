#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, m, num;
    cin >> n >> m;

    vector<int> sum (n+1, 0); // sum[i] : 1부터 i까지 누적합
    vector<ll> remain (m, 0); // mod로 나눈 나머지
    for(int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = (sum[i-1] + num) % m; // 누적합 계산
        remain[sum[i]]++;
    }

    ll cnt = 0;
    for(int i = 0; i < m; i++) { // 조합 개수 세기
        if(!i) cnt += remain[i];
        cnt += (remain[i] * (remain[i]-1) / 2);
    }
    cout << cnt;
    return 0;
}