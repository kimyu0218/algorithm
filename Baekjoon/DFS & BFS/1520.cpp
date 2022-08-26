#include <iostream>
#include <vector>

using namespace std;

int m, n;
// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<int>> dp;
vector<vector<int>> map;

int dfs_dp(int row, int col) {
    // 목표 지점 도달 (m-1, n-1)에서 (m-1, n-1)로 가는 경우의 수는 1
    if(row == m-1 && col == n-1) return dp[row][col] = 1;

    // 1. (m-1, n-1)에서 (row, col)까지 가는 경로 존재함 -> 바로 리턴
    if(dp[row][col] != -1) return dp[row][col];

    // 2. 아직 (m-1, n-1)에서 (row, col)까지 가는 경로 존재하지 않음 -> 경로 탐색
    dp[row][col] = 0;
    for(int i = 0; i < 4; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n
           && map[new_row][new_col] < map[row][col]) {
            dp[row][col] += dfs_dp(new_row, new_col);
        }
    }
    return dp[row][col];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    dp.assign(m, vector<int> (n, -1)); // -1 : (m-1, n-1)에서 (row, col)까지 갈 수 있는 경로 없음
    map.assign(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    cout << dfs_dp(0, 0);
    return 0;
}