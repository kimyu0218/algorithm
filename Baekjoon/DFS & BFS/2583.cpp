#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int VISITED = 2;

int n, m;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
vector<vector<int>> paper;

int dfs(int r, int c) {
    int width = 1; // 영역의 넓이
    paper[r][c] = VISITED; // 방문 체크
    for(int i = 0; i < 4; i++) { // 인접한 칸 탐색
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !paper[nr][nc]) {
            width += dfs(nr, nc);
        }
    }
    return width;
}

vector<int> partition() {
    vector<int> width; // 영역들의 넓이 저장
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!paper[i][j]) {
                int tmp = dfs(i, j);
                width.push_back(tmp);
            }
        }
    }
    sort(width.begin(), width.end()); // 오름차순 정렬
    return width;
}

int main() {
    int k, lx, ly, rx, ry;

    cin >> n >> m >> k;
    paper.assign(n, vector<int> (m, 0));

    while(k--) {
        cin >> lx >> ly >> rx >> ry;
        for(int i = n-1-ly; i >= n-ry ; i--) { // (row 인덱스가 일반적인 배열 인덱스와 반대)
            for(int j = lx; j < rx; j++) {
                paper[i][j] = 1;
            }
        }
    }

    vector<int> answer = partition();
    int cnt = answer.size();
    cout << cnt << '\n'; // 영역 개수 출력
    for(int i = 0; i < cnt; i++) { // 영역 넓이 출력
        cout << answer[i] << ' ';
    }
    return 0;
}