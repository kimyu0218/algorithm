#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e4 + 1; // (T의 최댓값 + 1)
int n, m, t;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
vector<vector<int>> castle;

int bfs(bool sword, int sr, int sc, int er, int ec) {
    // sword : 그람 소유 여부
    // sr, sc : 출발지
    // er, ec : 목적지
    vector<vector<int>> time(n, vector<int> (m, INF));

    queue<pi> q;
    q.push({sr, sc}); time[sr][sc] = 0;

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();
        if(row == er && col == ec) break; // 목적지까지 탐색한 경우 중단
        if(time[row][col] == INF-1) break; // T의 최댓값을 초과하는 경우 항상 fail이므로 중단

        for(int i = 0; i < 4; i++) {
            int new_row = row + dr[i], new_col = col + dc[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue;
            if(time[new_row][new_col] != INF) continue;

            if(!sword && castle[new_row][new_col] == 1) continue; // 검이 없으므로 벽 뚫을 수 없음
            time[new_row][new_col] = time[row][col] + 1;
            q.push({new_row, new_col});
        }
    }
    return time[er][ec];
}

int main() {
    cin >> n >> m >> t;

    pi pos; // 그람의 위치 저장
    castle.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> castle[i][j];
            if(castle[i][j] == 2) { // 그람 발견
                pos = {i, j};
            }
        }
    }

    // 1. 그람 없는 최단 경로
    int without_sword = bfs(false, 0, 0, n-1, m-1);
    // 2. 그람 있는 최단 경로 (시작점에서 그람이 있는 위치까지 최단 경로 + 그람이 있는 위치부터 도착점까지 최단 경로)
    int with_sword = bfs(false, 0, 0, pos.first, pos.second) + bfs(true, pos.first, pos.second, n-1, m-1);

    int answer = min(without_sword, with_sword);
    if(answer >= INF || answer > t) cout << "Fail"; // T의 최댓값을 초과했거나 T초 내에 구하지 못한 경우 fail
    else cout << answer;
    return 0;
}