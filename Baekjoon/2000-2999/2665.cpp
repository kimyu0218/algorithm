#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info{
    int row, col, cnt;
};
struct cmp {
    bool operator() (const info &i1, const info &i2) {
        if(i1.cnt != i2.cnt) {
            return i1.cnt > i2.cnt;
        }
        if(i1.row != i2.row) {
            return i1.row > i2.row;
        }
        return i1.col > i2.col;
    }
};

int dijkstra(int n, vector<vector<int>> &board) {
    priority_queue<info, vector<info>, cmp> pq;
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우

    // 시작 정점
    visited[0][0] = true;
    pq.push({0, 0, 0});

    while(!pq.empty()) {
        int r = pq.top().row;
        int c = pq.top().col;
        int cnt = pq.top().cnt;
        pq.pop();

        if(r == n-1 && c == n-1) { // 도착
            return cnt;
        }

        for(int i = 0; i < 4; i++) { // 인접한 칸 확인
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 범위를 벗어나지 않고 방문하지 않은 방인 경우
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                visited[nr][nc] = true; // 방문 체크
                if(!board[nr][nc]) { // 1. 검은 방 : 흰 방으로 바꾸기
                    pq.push({nr, nc, cnt+1});
                }
                else { // 2. 흰색 방
                    pq.push({nr, nc, cnt});
                }
            }
        }
    }
}

int main() {
    int n;
    string input;
    vector<vector<int>> board;

    cin >> n;
    board.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 방 정보 입력
        cin >> input;
        for(int j = 0; j < n; j++) {
            board[i][j] = input[j]-'0';
        }
    }

    cout << dijkstra(n, board);
    return 0;
}