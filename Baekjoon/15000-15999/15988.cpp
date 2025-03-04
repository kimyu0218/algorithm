#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 9, MAX = 1e6;

vector<int> solution() {
    vector<int> dp (MAX+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= MAX; i++) {
        for(int j = 1; j <= 3; j++) { // 1, 2, 3 이어붙이기
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    return dp;
}

int main() {
    int t, n;
    vector<int> dp = solution();

    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}