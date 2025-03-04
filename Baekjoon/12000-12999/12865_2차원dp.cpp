#include <iostream>

using namespace std;

const int SIZE = 100, MAX = 100000;
int w[SIZE+1], v[SIZE+1], dp[SIZE+1][MAX+1]; // (dp[해당물품까지][무게] = 최대 가치합)

int max_value(int n, int k) { // 가치 최대합 계산
    for(int i = 1; i <= n; i++) { // (i : 물품 번호, j : 배낭 무게)
        for(int j = 1; j < w[i]; j++) dp[i][j] = dp[i-1][j]; // (가치 갱신이 일어나지 않는 부분 i-1행 옮기기)

        // 1. dp[i-1][j] : 현재 물건을 넣지 않은 경우
        // 2. dp[i-1][j-w[i]] + v[i] : 현재 물건 넣기
        for(int j = w[i]; j <= k; j++) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) // 무게, 가치 입력
        cin >> w[i] >> v[i];

    cout << max_value(n, k);
    return 0;
}