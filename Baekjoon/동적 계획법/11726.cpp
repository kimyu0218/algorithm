#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int tiling(int n) { // 2 x n 타일링
    if(n == 1 || n == 2) { // n이 1이거나 2인 경우, 답 바로 리턴
        return n;
    }
    vector<int> dp(n+1, 0);
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i = 4; i <= n; i++) {
        /*
         * 2 x i 만드는 방법
         * 1. 2 x (i-1) + 2 x 1
         * 2. 2 x (i-2) + 2 x 2
        */
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << tiling(n);
    return 0;
}