#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int dr[3] = { 0, 1, 1 };
int dc[3] = { 1, 0, 1 };

int solution(int n, int m) {
    vector<vector<int>> dp (n, vector<int> (m, 0));
    
    dp[0][0] = 1;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            for(int i = 0; i < 3; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }
                dp[nr][nc] = (dp[nr][nc] + dp[r][c]) % MOD;
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    cout << solution(n, m);
    return 0;
}