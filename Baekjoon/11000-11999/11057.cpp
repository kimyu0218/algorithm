#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int increasingNum(int n) { // 오르막 수 세기
    // dp[i][j] : i번째 자리에 j가 올 수 있는 경우의 수
    vector<vector<int>> dp (n, vector<int> (10, 0));
    for(int i = 0; i < 10; i++) dp[n-1][i] = 1; // n-1번째 자리에 i가 올 수 있는 경우의 수

    for(int i = n-2; i >= 0; i--) { // i : 자리
        for(int j = 0; j < 10; j++) { // j : i번째 자릿수
            for(int k = j; k < 10; k++)
                dp[i][j] += dp[i+1][k];
            dp[i][j] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++) ans += dp[0][i];
    return ans % MOD;
}

int main() {
    int n;
    cin >> n;

    cout << increasingNum(n);
    return 0;
}