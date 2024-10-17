#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;

const int N = 1e6;
const int MOD = 1e9;

int dp[2 * N + 1];

void set_dp(int n) {
    dp[0 + N] = 0;
    dp[1 + N] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i + N] = (dp[i - 1 + N] + dp[i - 2 + N]) % MOD;
    }
    for(int i = -1; i >= -n; i--) {
        dp[i + N] = (dp[i + 2 + N] - dp[i + 1 + N]) % MOD;
    }
}

pi solution(int n) {
    set_dp(abs(n));
    
    int fn = dp[n + N];
    if(fn > 0) {
        return { 1, fn };
    }
    if(fn == 0) {
        return { 0, 0 };
    }
    return { -1, abs(fn) };
}

int main() {
    int n;
    
    cin >> n;
    
    pi result = solution(n);
    
    cout << result.first << '\n' << result.second;
    return 0;
}