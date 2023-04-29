#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 25 * 25 * 6;
struct info {
    int row, col, dir; // 열, 행, 방향
};
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우

int bfs(int sr, int sc, int n, vector<vector<int>> &board) { // 최단거리 만들기
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (4, MAX)));
    queue<info> q;

    // 시작정점 초기화
    for(int i = 0; i < 4; i++) {
        dp[sr][sc][i] = 0;
    }
    q.push({sr, sc, 1}); // 아래 방향으로 탐색
    q.push({sr, sc, 3}); // 오른쪽 방향으로 탐색

    while(!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int d = q.front().dir;
        q.pop();

        for(int i = 0; i < 4; i++) { // 인접한 칸 탐색
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) { // 좌표를 벗어나거나 벽인 경우 pass
                continue;
            }

            int cost; // (nr, nc)까지 i 방향으로 이동하는 경우의 비용
            if(i == d) { // 직선
                cost = dp[r][c][d] + 1;
            }
            else { // 곡선
                cost = dp[r][c][d] + 6;
            }

            if(dp[nr][nc][i] < cost) { // 기존의 비용보다 높은 경우 pass
                continue;
            }
            dp[nr][nc][i] = cost;
            q.push({nr, nc, i});
        }
    }

    int answer = MAX;
    for(int i = 0; i < 4; i++) { // 최소 비용 찾기
        if(dp[n-1][n-1][i] < answer) {
            answer = dp[n-1][n-1][i];
        }
    }
    return answer * 100; // (answer에 100 곱한 값 == 경주로 건설 비용)
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    return bfs(0, 0, n, board);
}