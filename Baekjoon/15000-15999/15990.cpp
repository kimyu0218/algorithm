#include <iostream>

using namespace std;

typedef long long ll;

const int N = 3;
const int MOD = 1e9 + 9;
const int MAX = 1e5;

int dp[MAX + 1][N + 1];

int solution(int n) {
    ll result = 0;
    
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    
    for(int i = 1; i <= N; i++) {
        result += dp[n][i];
    }
    return result % MOD;
}

int main() {
    int t, n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        cout << solution(n) << '\n';
    }
    return 0;
}