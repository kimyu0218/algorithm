#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll tiling(int n) {
    if(n % 2) { // 3 X 홀수의 경우의 수는 항상 0
        return 0;
    }
    if(n == 0) {
        return 0;
    }
    if(n == 2) {
        return 3;
    }

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        dp[i] = dp[i-2] * dp[2];
        for(int j = i-4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << tiling(n);
    return 0;
}