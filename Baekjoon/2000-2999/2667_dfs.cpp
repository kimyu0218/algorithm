#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n; // 지도 크기
// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<int>> map;
vector<vector<bool>> visited;

int dfs(int row, int col) {
    vector<pair<int, int>> result;
    stack<pair<int, int>> s;

    // 시작점 push
    visited[row][col] = true; s.push({row, col});
    result.push_back({row, col});

    while(!s.empty()) {
        row = s.top().first;
        col = s.top().second;

        bool find = false;
        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];

            // 1. (row, col)과 연결된 집 발견
            if(new_row >= 0 && new_col >= 0 && new_row < n && new_col < n && !visited[new_row][new_col] && map[new_row][new_col]) {
                visited[new_row][new_col] = true; s.push({new_row, new_col});
                result.push_back({new_row, new_col});
                find = true; break;
            }
        }
        if(!find) s.pop(); // 2. (row, col)과 연결된 집이 없음
    }
    return result.size();
}

int main() {
    cin >> n;

    map.assign(n, vector<int> (n, 0));
    visited.assign(n, vector<bool> (n, false));
    string tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < n; j++)
            map[i][j] = tmp[j] - '0';
    }

    vector<int> complex;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && map[i][j])
                complex.push_back(dfs(i, j));
        }
    }
    sort(complex.begin(), complex.end());

    int cnt = complex.size(); // 총 단지 수
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++) // 단지별 세대 수
        cout << complex[i] << '\n';
    return 0;
}