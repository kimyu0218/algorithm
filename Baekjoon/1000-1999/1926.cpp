#include <iostream>
#include <vector>

using namespace std;
const int VISITED = -1;
typedef pair<int, int> pi;

int n, m;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
vector<vector<int>> paper;

int dfs(int r, int c) {
    int width = 1;
    paper[r][c] = VISITED; // 방문 체크
    for(int i = 0; i < 4; i++) { // 인접한 그림 확인
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && paper[nr][nc] == 1) {
            width += dfs(nr, nc);
        }
    }
    return width; // 그림 너비 반환
}

pi solution() {
    int cnt = 0, width = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(paper[i][j] == 1) { // 그림 발견
                cnt++; // 그림 개수 카운트
                int tmp = dfs(i, j);
                width = max(width, tmp);
            }
        }
    }
    return {cnt, width};
}

int main() {
    cin >> n >> m;
    paper.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    pi ans = solution();
    cout << ans.first << '\n' << ans.second;
    return 0;
}