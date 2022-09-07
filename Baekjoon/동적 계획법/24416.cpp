#include <iostream>
#include <vector>

using namespace std;

int fib_recur(int n) {
    if(n == 1 || n == 2) return 1;
    return fib_recur(n-1) + fib_recur(n-2);
}

int fib_dp(int n) {
    int cnt = 0;
    vector<int> dp(n+1, 0);
    dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        cnt++;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << fib_recur(n) << ' ' << fib_dp(n);
    return 0;
}