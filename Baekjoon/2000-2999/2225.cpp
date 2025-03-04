#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;

int cntCase(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0)); // dp[n][k] : n을 k개의 숫자로 만드는 경우의 수
    for(int i = 0; i <= k; i++) { // 1을 정수 i개를 사용하여 만드는 경우의 수는 항상 i
        dp[1][i] = i;
    }
    for(int i = 0; i <= n; i++) { // i를 정수 1개를 사용하여 만드는 경우의 수는 항상 1
        dp[i][1] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) { // i를 정수 j개를 사용하여 만드는 경우의 수
            // 1 사용하기, 0 사용하기
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << cntCase(n, k);
    return 0;
}