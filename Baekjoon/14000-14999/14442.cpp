#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int row, col, cnt;
};
const int UNVISITED = -1;

int bfs(int n, int m, int k, vector<vector<int>> &map) {
    vector<vector<vector<int>>> dist(n, vector<vector<int>> (m, vector<int> (k+1, UNVISITED)));
    queue<info> q;
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우

    // 시작 정점 (0,0)
    dist[0][0][0] = 1;
    q.push({0, 0, 0});

    while(!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int cnt = q.front().cnt;
        q.pop();

        if(r == n-1 && c == m-1) { // 도착 정점 (n-1, m-1)
            return dist[r][c][cnt];
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m) { // 맵 범위 내
                if(map[nr][nc] && cnt < k && dist[nr][nc][cnt+1] == UNVISITED) { // 1. 벽을 부수고 이동할 수 있는 경우
                    dist[nr][nc][cnt+1] = dist[r][c][cnt] + 1;
                    q.push({nr, nc, cnt+1});
                }
                else if(!map[nr][nc] && dist[nr][nc][cnt] == UNVISITED) { // 2. 그냥 지나갈 수 있는 경우
                    dist[nr][nc][cnt] = dist[r][c][cnt] + 1;
                    q.push({nr, nc, cnt});
                }
            }
        }
    }
    return -1; // 도착 정점에 도달할 수 없는 경우
}

int main() {
    int n, m, k;
    vector<vector<int>> map;
    string input;

    cin >> n >> m >> k;
    map.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    cout << bfs(n, m, k, map);
    return 0;
}