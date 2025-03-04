#include <iostream>
#include <vector>

using namespace std;

const int NON = -1;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int m, n;
vector<vector<int>> map;
vector<vector<int>> dp;

bool is_valid_pos(int row, int col) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

int solution(int r, int c) {
    if(r == m - 1 && c == n - 1) {
        return dp[r][c] = 1;
    }
    if(dp[r][c] != NON) {
        return dp[r][c];
    }

    dp[r][c] = 0;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(!is_valid_pos(nr, nc) || map[nr][nc] >= map[r][c]) {
            continue;
        }
        dp[r][c] += solution(nr, nc);
    }
    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    map.assign(m, vector<int> (n, 0));
    dp.assign(m, vector<int> (n, NON));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << solution(0, 0);
    return 0;
}