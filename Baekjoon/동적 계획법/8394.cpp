#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10;

int solution(int n) {
    if(n < 2) {
        return 0;
    }
    if(n < 4) {
        return n;
    }
    
    vector<int> dp (n + 1, 0);
    
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0; 
}