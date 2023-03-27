#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 8방향 (시계방향 순)

int bfs(int sr, int sc, int n, int m, vector<vector<int>> &board) {
    // (sr, sc)부터 각 정점까지의 거리
    vector<vector<int>> dist(n, vector<int> (m, -1)); // (아직 방문히지 않은 지점 == -1)

    queue<pi> q;
    q.push({sr, sc}); dist[sr][sc] = 0;

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        if(board[r][c] == 1) { // 가장 가까운 아기 상어 발견 -> 안전 거리 리턴
            return dist[r][c];
        }

        for(int i = 0; i < 8; i++) { // 인접 정점 탐색
            int nr = r + dy[i], nc = c + dx[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || dist[nr][nc] != -1) { // 범위를 벗어나거나 이미 방문한 정점 pass
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 공간 상태 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                ans = max(ans, bfs(i, j, n, m, board));
            }
        }
    }
    cout << ans;
    return 0;
}