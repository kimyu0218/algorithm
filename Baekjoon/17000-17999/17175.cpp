#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int solution(int n) {
    if(n <= 1) {
        return 1;
    }
    
    vector<int> dp (n + 1, 0);
    
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;
    }
    return dp[n];
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}