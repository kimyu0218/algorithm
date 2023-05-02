#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
vector<vector<int>> iceberg; // 빙산
vector<vector<bool>> visited;

int surroundingWater(int r, int c) { // 빙산 주변의 바닷물
    int water = 0;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || iceberg[nr][nc]) {
            continue;
        }
        water++;
    }
    return water;
}

void melt() {
    vector<vector<int>> melting_degree; // 빙산의 녹는 정도
    for(int i = 0; i < n; i++) { // 빙산이 얼마나 녹을지 계산
        for(int j = 0; j < m; j++) {
            if(iceberg[i][j] > 0) {
                int water = surroundingWater(i, j);
                if(water) {
                    melting_degree.push_back({i, j, water});
                }
            }
        }
    }
    for(int i = 0; i < melting_degree.size(); i++) { // 빙산 녹이기
        int row = melting_degree[i][0], col = melting_degree[i][1];
        int water = melting_degree[i][2];
        iceberg[row][col] -= water;
        if(iceberg[row][col] < 0) {
            iceberg[row][col] = 0;
        }
    }
}

void dfs(int r, int c) { // 빙산 연결하기
    visited[r][c] = true;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] || !iceberg[nr][nc]) {
            continue;
        }
        dfs(nr, nc);
    }
}

int cntLump() { // 빙산 덩어리 세기
    int cnt = 0; // 덩어리 개수
    visited.assign(n, vector<bool> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(iceberg[i][j] && !visited[i][j]) { // 아직 방문하지 않은 빙산 발견
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int separateIceberg() { // 빙산이 분리되는 데 걸리는 시간 반환
    int year = 0, lump = 1; // (초기 빙산은 덩어리 하나)
    while(lump < 2) {
        year++; melt(); // 1년이 지나고 빙산 녹음
        lump = cntLump();
        if(lump == 0) { // 빙산이 다 녹을 때까지 발견 못함
            return 0;
        }
    }
    return year;
}

int main() {
    cin >> n >> m;
    iceberg.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 빙산 정보 입력
        for(int j = 0; j < m; j++) {
            cin >> iceberg[i][j];
        }
    }
    cout << separateIceberg();
    return 0;
}