#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int n) {
    if(n == 1) {
        return 4;
    }
    
    vector<ll> dp (n, 0);
    
    dp[0] = dp[1] = 1;
    for(int i = 2; i < n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n - 1] * 4 + dp[n - 2] * 2;
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}