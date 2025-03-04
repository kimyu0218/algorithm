#include <iostream>
#include <vector>

using namespace std;

const int MOD = 16769023;

int solution(int n) {
    if(n <= 2) {
        return 2;
    }
    
    vector<vector<int>> dp (n + 1, vector<int> (2, 0));
    
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = dp[2][1] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i - 2][1] * 2) % MOD;
        dp[i][1] = (dp[i - 2][0] * 2) % MOD;
    } 
    return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}