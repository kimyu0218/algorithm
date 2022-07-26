#include <iostream>

using namespace std;

const int SIZE = 1000, DENOMINATOR = 10007;
int dp[SIZE+1];

int fill_tile(int n) {
    dp[1] = 1; // 2x1 1개
    dp[2] = 3; // 1x2 2개, 2x1 2개, 2x2 1개
    // 1. 2x(n-1) + 2x1 -> 1가지 경우의 수
    // 2. 2x(n-2) + 1x2*2개 / 2x(n-2) + 2x2*1개 -> 2가지 경우의 수
    for(int i = 3; i <= n; i++) { // (i : 타일 너비)
        dp[i] = dp[i-1] + 2 * dp[i-2];
        dp[i] %= DENOMINATOR;
    }
    return dp[n] % DENOMINATOR;
}

int main() {
    int n;
    cin >> n;

    cout << fill_tile(n);
    return 0;
}