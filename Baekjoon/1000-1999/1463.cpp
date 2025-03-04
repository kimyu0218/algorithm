#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6;

int make_one(int n) {
    vector<int> dp(n+1, INF); // dp[i] : i에서 1이 되기 위해 필요한 최소 연산 횟수
    
    dp[0] = 0; dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        dp[i] = min(dp[i], dp[i-1] + 1);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << make_one(n);
    return 0;
}