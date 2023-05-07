#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2 * 1e4;
struct info {
    int dist, cnt, row, col;
};

struct cmp{
    bool operator() (const info &i1, const info &i2) {
        if(i1.dist != i2.dist) {
            return i1.dist > i2.dist;
        }
        return true;
    }
};

int dijkstra(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> b_cnt(n, vector<int> (m, INF)); // 벽 부순 횟수
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
    priority_queue<info, vector<info>, cmp> pq;

    // 시작 정점
    b_cnt[0][0] = 0;
    pq.push({0, 0, 0, 0});

    while(!pq.empty()) {
        int dist = pq.top().dist;
        int cnt = pq.top().cnt;
        int r = pq.top().row, c = pq.top().col;
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) { // 범위를 벗어나는 경우 pass
                continue;
            }

            if(maze[nr][nc] && b_cnt[nr][nc] > cnt+1) { // 1. 벽을 부술 수 있는 경우
                b_cnt[nr][nc] = cnt+1;
                pq.push({dist+1, cnt+1, nr, nc});
            }
            else if(!maze[nr][nc] && b_cnt[nr][nc] > cnt) { // 2. 그냥 지나갈 수 있는 경우
                b_cnt[nr][nc] = cnt;
                pq.push({dist+1, cnt, nr, nc});
            }
        }
    }
    return b_cnt[n-1][m-1];
}

int main() {
    int n, m;
    vector<vector<int>> maze;
    string input;

    cin >> m >> n;
    maze.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            maze[i][j] = input[j] - '0';
        }
    }

    cout << dijkstra(n, m, maze);
    return 0;
}