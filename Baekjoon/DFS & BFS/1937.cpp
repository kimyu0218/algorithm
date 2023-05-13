#include <iostream>

using namespace std;
const int SIZE = 500;

int n;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
int forest[SIZE][SIZE] = {0, };
int dp[SIZE][SIZE][4] = {0, };

void dfs(int r, int c, int dir) {
    dp[r][c][dir] = 1;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < n && forest[nr][nc] > forest[r][c]) { // 판다가 이동할 수 있는 칸인 경우
            if(!dp[nr][nc][i]) { // 아직 탐색하지 않은 지점인 경우
                dfs(nr, nc, i);
            }
            // dp[nr][nc][i] : (nr, nc) 지점으로 이동하는 칸 수
            // + 1 : (r, c) 자기 자신 포함
            dp[r][c][dir] = max(dp[r][c][dir], dp[nr][nc][i] + 1);
        }
    }
}

int bruteforce() {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                dfs(i, j, k);
                answer = max(answer, dp[i][j][k]);
            }
        }
    }
    return answer;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    cout << bruteforce();
    return 0;
}