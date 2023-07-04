#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
struct info {
    int row, col, cnt;
};

struct cmp {
    bool operator()(const info &i1, const info &i2) {
        if(i1.cnt != i2.cnt) { // 1. 가까운 순
            return i1.cnt > i2.cnt;
        }
        if(i1.row != i2.row) { // 2. 행 번호가 작은 순
            return i1.row > i2.row;
        }
        return i1.col > i2.col; // 열 번호가 작은 순
    }
};

int bfs(int n, int &sr, int &sc, int dsr, int dsc, vector<vector<int>> &board) {
    priority_queue<info, vector<info>, cmp> q;
    vector<vector<bool>> visited(n, vector<bool> (n, false));

    q.push({sr, sc, 0});
    visited[sr][sc] = true;

    while(!q.empty()) {
        int row = q.top().row;
        int col = q.top().col;
        int cnt = q.top().cnt;
        q.pop();

        // 1. dsr과 dsc가 -1인 경우 == 승객 찾기
        if(dsr == -1 && dsc == -1 && board[row][col] < 0) {
            sr = row; sc = col;
            return cnt;
        }
        // 2. 승객 이동시키기
        else if(row == dsr && col == dsc) {
            sr = row; sc = col;
            return cnt;
        }

        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] != 1 && !visited[nr][nc]) {
                q.push({nr, nc, cnt+1});
                visited[nr][nc] = true;
            }
        }
    }
    return -1;
}

int remainFuel(int n, int m, int fuel, int sr, int sc, vector<vector<int>> &board, vector<pi> &dst) {
    int cnt = 0, result;
    while(cnt < m) {
        // 1. 현재 위치에서 가장 가까운 승객 태우러 가기
        result = bfs(n, sr, sc, -1, -1, board);
        if(result == -1) { // 1-1. 승객 태울 수 없는 경우
            return -1;
        }
        fuel -= result; // 1-2. 승객 태우러 가는 길에 소모된 연료양 빼기
        if(fuel <= 0) { // 1-3. 승객 태우러 가는 길에 연료가 다 떨어진 경우
            return -1;
        }

        // 2. 승객 목적지로 이동시키기
        int g = 0 - board[sr][sc]; // g번 승객
        board[sr][sc] = 0; // 승차 처리
        result = bfs(n, sr, sc, dst[g].first, dst[g].second, board);
        if(result == -1) { // 2-1. 도착지에 도착할 수 없는 경우
            return -1;
        }
        if(fuel - result < 0) { // 2-2. 도착지에 가는 길에 연료가 다 떨어진 경우
            return -1;
        }
        fuel += result; // 2-3. 승객 이동 성공
        cnt++;
    }
    return fuel;
}

int main() {
    int n, m, fuel, sr, sc;
    int src_r, src_c, dst_r, dst_c;
    vector<vector<int>> board;
    vector<pi> dst; // 승객별 목적지

    cin >> n >> m >> fuel;
    board.assign(n, vector<int> (n, 0));
    dst.assign(m+1, {});
    for(int i = 0; i < n; i++) { // 지도 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cin >> sr >> sc;
    for(int i = 1; i <= m; i++) {
        cin >> src_r >> src_c >> dst_r >> dst_c;
        board[src_r-1][src_c-1] = -i; // 승객 번호 음수로 표기
        dst[i] = {dst_r-1, dst_c-1}; // 승객의 목적지 저장
    }

    cout << remainFuel(n, m, fuel, sr-1, sc-1, board, dst);
    return 0;
}