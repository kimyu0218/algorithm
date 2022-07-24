#include <iostream>

using namespace std;

const int SIZE = 100, MAX = 100000;
int w[SIZE+1], v[SIZE+1], dp[MAX+1]; // (dp[무게] = 최대 가치합)

int max_value(int n, int k) { // 가치 최대합 계산
    for(int i = 1; i <= n; i++) { // (i : 물품 번호, j : 배낭 무게)
        // 1. dp[j] : 이전 최대 가치합
        // 2. dp[j-w[i]] + v[i] : 현재 물건 넣기
        for(int j = k; j >= w[i]; j--) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) // 무게, 가치 입력
        cin >> w[i] >> v[i];

    cout << max_value(n, k);
    return 0;
}