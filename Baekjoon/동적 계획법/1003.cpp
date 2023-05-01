#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

vector<vector<int>> setDp() { // dp 세팅하기
    vector<vector<int>> dp (N+1, {0, 0}); // dp[i][j] : i의 j 호출 횟수
    dp[0] = {1, 0}; // (0은 0을 1번, 1을 0번 호출)
    dp[1] = {0, 1}; // (1은 0을 0번, 1을 1번 호출)
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 1; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-2][j];
        }
    }
    return dp;
}

int main() {
    int t, n;
    cin >> t;

    vector<vector<int>> dp = setDp();
    while(t--) { // 테스트케이스 입력
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }
    return 0;
}