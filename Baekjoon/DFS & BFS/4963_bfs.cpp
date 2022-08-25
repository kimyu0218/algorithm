#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상, 하, 좌, 우, 좌상향, 우상향, 좌하향, 우하향
int w, h;
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs(int row, int col) {
    queue<pair<int, int>> q;

    // 시작 지점 push
    visited[row][col] = true;
    q.push({row, col});

    while(!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) { // 연결된 육지 탐색 (인접 노드 탐색)
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row >= 0 && new_row < h && new_col >= 0 && new_col < w && !visited[new_row][new_col] && map[new_row][new_col]) {
                visited[new_row][new_col];
                bfs(new_row, new_col);
            }
        }
    }
}

int main() {
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        map.assign(h, vector<int> (w, 0));
        visited.assign(h, vector<bool> (w, false));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++)
                cin >> map[i][j];
        }

        int cnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(map[i][j] && !visited[i][j]) { // 육지 발견
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}