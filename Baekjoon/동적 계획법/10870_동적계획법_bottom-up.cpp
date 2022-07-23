#include <iostream>

using namespace std;

const int MAX = 20;
int dp[MAX+1];

// 피보나치 점화식 : f(n) = f(n-1) + f(n-2)
int fibo(int n) {
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}