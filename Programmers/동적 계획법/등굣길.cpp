#include <string>
#include <vector>

using namespace std;

const int PUDDLE = -1;
const int MOD = 1e9 + 7;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i = 0; i < puddles.size(); i++) {
        int r = puddles[i][1] - 1;
        int c = puddles[i][0] - 1;
        dp[r][c] = PUDDLE;
    }

    for(int i = 0; i < m; i++) {
        if(dp[0][i] == PUDDLE) {
            break;
        }
        dp[0][i] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(dp[i][0] == PUDDLE) {
            break;
        }
        dp[i][0] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(dp[i][j] == PUDDLE) {
                continue;
            }

            int up = max(dp[i - 1][j], 0);
            int left = max(dp[i][j - 1], 0);
            dp[i][j] = (up + left) % MOD;
        }
    }
    return dp[n - 1][m - 1];
}