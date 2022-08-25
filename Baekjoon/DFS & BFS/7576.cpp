#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tomato;
queue<pair<int, int>> q; // 익은 토마토 저장하는 큐

int bfs(int m, int n, int cnt) {
    int date = 0;
    // 상하좌우
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    while(!q.empty()) {
        // 익은 토마토
        int row = q.front().first;
        int col = q.front().second;
        date = tomato[row][col];
        q.pop();

        // 인접한 토마토에 영향 미치기
        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !tomato[new_row][new_col]) {
                tomato[new_row][new_col] = date + 1;
                cnt--;
                q.push({new_row, new_col});
            }
        }
    }
    // 1. 토마토가 다 익은 경우
    if(!cnt) return date - 1; // (처음부터 익어있던 토마토는 0일만에 익는데 1일부터 시작했으므로 -1을 해야 함)
    // 2. 익지 않은 토마토가 남아있는 경우
    return -1;
}

int main() {
    int m, n, cnt = 0; // (cnt : 안 익은 토마토 개수)
    cin >> m >> n;

    tomato.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 토마토 정보 입력
        for(int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) q.push({i, j}); // 1. 익은 토마토
            else if(tomato[i][j] == 0) cnt++; // 2. 익지 않은 토마토 개수 세기
        }
    }

    cout << bfs(m, n, cnt);
    return 0;
}