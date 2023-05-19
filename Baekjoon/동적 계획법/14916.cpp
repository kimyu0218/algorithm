#include <iostream>
#include <vector>

using namespace std;

int cntCoin(int n) {
    if(n == 1 || n == 3) { // 1원과 3원은 2원이나 5원으로 만들 수 없음
        return -1;
    }
    if(n == 2 || n == 5) {
        return 1;
    }
    if(n == 4) {
        return 2;
    }
    vector<int> dp (n+1, -1);
    dp[2] = dp[5] = 1;
    dp[4] = 2;
    for(int i = 6; i <= n; i++) {
        if(dp[i-2] != -1) {
            dp[i] = dp[i-2] + 1;
        }
        if(dp[i-5] != -1) {
            dp[i] = min(dp[i], dp[i-5] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << cntCoin(n);
    return 0;
}