#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int INF = 200;
int n;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
vector<vector<bool>> visited;
vector<vector<int>> board, dist; // board : 섬과 바다의 구분, dist : 섬 사이의 거리

void bfs(int sr, int sc, int num) {
    queue<pi> q;

    visited[sr][sc] = true;
    board[sr][sc] = -num;
    q.push({sr, sc});

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 아직 방문하지 않은 육지 발견
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && board[nr][nc]) {
                visited[nr][nc] = true;
                board[nr][nc] = -num; // 같은 섬 처리
                q.push({nr, nc});
            }
        }
    }
}

int bfs2(int sr, int sc, int num) { // 섬 사이의 거리 반환 (num 섬에서 갈 수 있는 가장 가까운 다른 섬까지의 거리)
    queue<pi> q;

    visited[sr][sc] = true;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 아직 방문하지 않은 지점
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                if(board[nr][nc] && board[nr][nc] != num) { // 1. 다른 섬 발견
                    return dist[r][c];
                }
                if(!board[nr][nc]) { // 2. 바다 발견
                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return INF;
}

void indexingIsland() { // 섬 구분하기
    visited.assign(n, vector<bool> (n, false));

    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] && !visited[i][j]) { // 방문하지 않은 땅 발견
                bfs(i, j, ++num);
            }
        }
    }
}

int shortestBridge() { // 가장 짧은 다리 길이
    indexingIsland(); // 섬 구분하기

    int len = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j]) {
                visited.assign(n, vector<bool> (n, false)); // bfs 탐색 전, 방문 체크 초기화
                int tmp = bfs2(i, j, board[i][j]); // 섬 사이의 길이
                len = min(len, tmp);
            }
        }
    }
    return len;
}

int main() {
    cin >> n;
    board.assign(n, vector<int> (n, 0));
    dist.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << shortestBridge();
    return 0;
}