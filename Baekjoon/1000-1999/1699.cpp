#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cntSquare(int n) {
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = i; // (1^2를 i개 사용하여 i를 만든다)
        for(int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << cntSquare(n);
    return 0;
}