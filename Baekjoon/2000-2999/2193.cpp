#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll cntPinaryNumber(int n) {
    vector<vector<ll>> dp(n, {0, 0});
    dp[0] = {0, 1}; // 0으로 시작할 수 없으므로 dp[0][0] = 0
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0]; // 1이 연달아 등장할 수 없음
    }
    return dp[n-1][0] + dp[n-1][1];
}

int main() {
    int n;
    cin >> n;
    cout << cntPinaryNumber(n);
    return 0;
}