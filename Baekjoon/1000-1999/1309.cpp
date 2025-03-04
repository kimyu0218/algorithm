#include <iostream>
#include <vector>

using namespace std;

const int MOD = 9901;

int solution(int n) {
    if(n == 1) {
        return 3;
    }
    vector<vector<int>> dp(n, vector<int> (3, 0));

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for(int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    int answer = 0;
    for(int i = 0; i < 3; i++) {
        answer = (answer + dp[n - 1][i]) % MOD;
    }
    return answer;
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}