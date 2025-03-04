#include <iostream>

using namespace std;

const int MOD = 10007;
const int SIZE = 1000;
int dp[SIZE+1][SIZE+1];

int binomial_coefficient(int n, int k) { // 이항계수 구하기
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= SIZE; i++) {
        dp[i][0] = 1; dp[i][i] = 1;
        for(int j = 1; j < i; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << binomial_coefficient(n, k);
    return 0;
}