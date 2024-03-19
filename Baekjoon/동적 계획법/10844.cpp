#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
const int MOD = 1e9;

int solution(int n) {
    int result = 0;
    vector<vector<int>> dp(n, vector<int> (SIZE, 0));

    for(int i = 1; i < SIZE; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j- 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][9] = dp[i-1][8];
    }

    for(int i = 0; i < SIZE; i++) {
        result = (result + dp[n - 1][i]) % MOD;
    }
    return result;
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}