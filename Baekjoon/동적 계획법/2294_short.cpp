#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coin, dp; // dp[k원] = 최소 동전수

int min_cnt(int n, int k) {
    dp[0] = 0;
    for(int i = 0; i < n; i++) { // n개의 동전
        // coin[i] : 동전 금액
        for(int j = coin[i]; j <= k; j++) {
            if(dp[j-coin[i]] == -1) continue; // j원을 만들 수 없는 경우 pass
            if(dp[j] == -1) dp[j] = dp[j-coin[i]] + 1; // 1. 이전에 j원을 만들지 못한 경우
            else dp[j] = min(dp[j], dp[j-coin[i]] + 1); // 2. 이전에 j원을 만든 이력이 있는 경우 최솟값 선택
        }
    }
    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    dp.assign(k+1, -1);
    coin.assign(n, 0);
    for(int i = 0; i < n; i++) // 동전 가치 입력
        cin >> coin[i];
    sort(coin.begin(), coin.end());

    cout << min_cnt(n, k);
    return 0;
}