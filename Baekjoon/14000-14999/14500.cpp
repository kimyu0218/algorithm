#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
vector<vector<int>> board;

void dfs(int x, int y, int cnt, int sum) {
    if(cnt == 4) { // 테트로미노 완성
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++) { // (x,y)에서 갈 수 있는 칸 탐색
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 종이를 벗어나거나 이미 방문한 지점 pass
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || !board[ny][nx]) {
            continue;
        }

        int w = board[ny][nx];
        board[ny][nx] = 0; // 방문 check
        if(cnt == 2) { // ㅜ 모양 탐색 (ㅜ 모양 탐색은 기존 dfs로 불가)
            // 기존 위치에서 다시 탐색
            dfs(x, y, cnt+1, sum+w);
        }
        dfs(nx, ny, cnt+1, sum+w);
        board[ny][nx] = w; // 방문 취소
    }
}

void bruteforce() {
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            int w = board[y][x];
            board[y][x] = 0; // 방문 check
            dfs(x, y, 1, w);
            board[y][x] = w; // 방문 취소
        }
    }
}

int main() {
    // 입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    bruteforce();
    cout << answer;
    return 0;
}