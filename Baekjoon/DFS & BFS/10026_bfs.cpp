#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우
int n;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<bool>> visited;

void bfs(int row, int col, char color, vector<vector<char>> grid) {
    queue<pair<int, int>> q;
    visited[row][col] = true; q.push({row, col});

    while(!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row >= 0 && new_col >= 0 && new_row < n && new_col < n && !visited[new_row][new_col] && grid[new_row][new_col] == color) {
                visited[new_row][new_col] = true;
                q.push({new_row, new_col});
            }
        }
    }
}

int main() {
    int normal_cnt = 0, abnormal_cnt = 0;
    cin >> n;

    vector<vector<char>> grid, abnormal_grid; // 정상인이 보는 그림, 적록색약이 보는 그림
    grid.assign(n, vector<char> (n, '\0'));
    abnormal_grid.assign(n, vector<char> (n, '\0'));

    string tmp;
    for(int i = 0; i < n; i++) { // 그림 입력
        cin >> tmp;
        for(int j = 0; j < n; j++) {
            grid[i][j] = tmp[j];
            // (적록색약은 빨간색을 초록색으로 본다고 가정)
            if(tmp[j] == 'R') abnormal_grid[i][j] = 'G';
            else abnormal_grid[i][j] = tmp[j];
        }
    }

    visited.assign(n, vector<bool> (n, false));
    for(int i = 0; i < n; i++) { // 정상인이 보는 구역 카운트
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                normal_cnt++;
                bfs(i, j, grid[i][j], grid);
            }
        }
    }

    visited.assign(n, vector<bool> (n, false));
    for(int i = 0; i < n; i++) { // 적록색약이 보는 구역 카운트
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                abnormal_cnt++;
                bfs(i, j, abnormal_grid[i][j], abnormal_grid);
            }
        }
    }

    cout << normal_cnt << ' ' << abnormal_cnt << '\n';
    return 0;
}