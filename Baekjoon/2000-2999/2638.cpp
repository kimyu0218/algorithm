#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int BLANK = 0, CONTACTED = -1, CHEESE = 1;

int n, m;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
vector<vector<int>> board;

void dfs(int row, int col) { // 공기에 접촉한 빈 칸, 공기에 접촉하지 않은 빈 칸 구분
    if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != BLANK) {
        return;
    }
    board[row][col] = CONTACTED;
    for(int i = 0; i < 4; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        dfs(new_row, new_col);
    }
}

bool canMelt(int row, int col) { // (row, col)의 치즈가 녹을 수 있는가
    int out = 0;
    for(int i = 0; i < 4; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        if(board[new_row][new_col] == CONTACTED) {
            out++;
        }
    }
    return (out >= 2);
}

vector<pi> cheesePos() { // 녹을 수 있는 치즈 위치 반환
    vector<pi> pos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == CHEESE && canMelt(i, j)) {
                pos.push_back({i, j});
            }
        }
    }
    return pos;
}

int computeTime() {
    int time = 0;
    dfs(0, 0);

    while(true) {
        vector<pi> pos = cheesePos(); // 이번에 녹일 치즈들의 위치
        if(pos.empty()) { // 더 이상 녹일 치즈가 없음
            break;
        }

        for(int i = 0; i < pos.size(); i++) { // 치즈 녹이기
            int row = pos[i].first;
            int col = pos[i].second;
            board[row][col] = BLANK; // 치즈 녹음 (CHEESE -> BLANK)
            dfs(row, col);
        }
        time++;
    }
    return time;
}

int main() {
    // 입력
    cin >> n >> m;
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    cout << computeTime();
    return 0;
}