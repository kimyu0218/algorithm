#include <iostream>
#include <vector>

using namespace std;

vector<int> wine;

int max_wine(int n) {
    if(n == 1) return wine[1];

    vector<int> dp(n+1, 0);
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    // 1. i-2 마시지 않기
    // 2. i-1 마시지 않기
    // 3. i 마시지 않기
    for(int i = 3; i <= n; i++)
        dp[i] = max(dp[i-3] + wine[i-1] + wine[i], max(dp[i-2] + wine[i], dp[i-1]));
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    wine.assign(n+1, 0);
    for(int i = 1; i <= n; i++) // 포두주 양 입력
        cin >> wine[i];

    cout << max_wine(n);
    return 0;
}