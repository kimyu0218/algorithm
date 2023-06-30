#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우

int bfs(int row, int col, int n, int m, vector<vector<int>> &board) {
    int score = (board[row][col] == 0) ? 1 : -2;
    queue<pi> q;

    q.push({row, col});
    board[row][col] = -1; // 방문 체크

    while(!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && (board[nr][nc] == 0 || board[nr][nc] == 2)) {
                score += (board[nr][nc] == 0) ? 1 : -2;
                q.push({nr, nc});
                board[nr][nc] = -1; // 방문체크
            }
        }
    }
    return score;
}

int highestScore(int n, int m, vector<vector<int>> &board) {
    int score = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || board[i][j] == 2) { // 아직 방문하지 않은 0칸 or 2칸 발견
                int result = bfs(i, j, n, m, board);
                score = max(score, result);
            }
        }
    }
    return score;
}

int main() {
    int n, m;
    vector<vector<int>> board;

    cin >> n >> m;
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << highestScore(n, m, board);
    return 0;
}