#include <iostream>

using namespace std;

typedef long long ll;
ll dp[101];

ll p(int n) { // 파도반 수열
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    dp[4] = 2; dp[5] = 2;
    for(int i = 6; i <= n; i++)
        dp[i] = dp[i-2] + dp[i-3];
    return dp[n];
}

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << p(n) << '\n';
    }
    return 0;
}