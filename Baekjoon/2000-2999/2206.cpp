#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> ti;
vector<vector<int>> map;
vector<vector<vector<int>>> route;

int bfs(int n, int m) {
    // 상 하 좌 우
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    queue<ti> q; // (0: row, 1: col, 2: 벽 부순 횟수)
    q.push({0, 0, 0}); // 시작점 push
    route[0][0][0] = 1;

    while(!q.empty()) {
        int row = get<0>(q.front()), col = get<1>(q.front());
        int crack = get<2>(q.front()); q.pop();
        int w = route[row][col][crack];
        if(row == n-1 && col == m-1) break; // 목적지 도착

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                // 1. 벽 부수기
                if(map[new_row][new_col] && !crack && route[new_row][new_col][1] == -1) {
                    route[new_row][new_col][1] = w+1;
                    q.push({new_row, new_col, 1});
                }
                // 2. 빈 칸 발견
                if(!map[new_row][new_col] && route[new_row][new_col][crack] == -1) {
                    route[new_row][new_col][crack] = w+1;
                    q.push({new_row, new_col, crack});
                }
            }
        }
    }
    if(route[n-1][m-1][0] == -1) return route[n-1][m-1][1];
    return route[n-1][m-1][0];
}

int main() {
    int n, m;
    cin >> n >> m;
    map.assign(n, vector<int> (m, 0));
    route.assign(n, vector<vector<int>> (m, vector<int> (2, -1))); // '경로 없음'으로 초기화

    string input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++)
            map[i][j] = (input[j] - '0');
    }

    cout << bfs(n, m); // 최단 경로
    return 0;
}