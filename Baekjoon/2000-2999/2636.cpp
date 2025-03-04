#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int CHEESE = 1, BLANK = 0, OUT = -1;

int n, m;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
vector<vector<int>> board;

bool canMelt(int r, int c) { // 치즈가 녹을 수 있는가 (== 바깥쪽 공기와 접촉했는가)
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == OUT) {
            return true;
        }
    }
    return false;
}

void dfs(int r, int c) { // 공기에 접촉한 빈 칸, 공기에 접촉하지 않은 빈 칸 구분
    if(r < 0 || r >= n || c < 0 || c >= m || board[r][c] != BLANK) {
        return;
    }
    board[r][c] = OUT;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        dfs(nr, nc);
    }
}

queue<pi> meltingCheese() {
    queue<pi> cheese; // 녹아야 하는 치즈 좌표
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(board[i][j] == CHEESE && canMelt(i, j)) { // 공기에 노출된 치즈 발견
                cheese.push({i, j});
            }
        }
    }
    return cheese;
}

void melt(queue<pi> cheese) { // 판에 치즈 녹은 것 표현하기
    while(!cheese.empty()) {
        int r = cheese.front().first;
        int c = cheese.front().second;
        cheese.pop();
        board[r][c] = BLANK;
        dfs(r, c);
    }
}

pi solution() {
    int time = 0, piece = 0;
    dfs(0, 0);
    while(true) {
        queue<pi> cheese = meltingCheese();
        if(cheese.empty()) { // 더 이상 녹을 치즈가 없는 경우
            break;
        }
        piece = cheese.size(); // 이번에 녹은 치즈 piece 변수에 임시 저장
        melt(cheese); // 치즈 녹이기
        time++;
    }
    return {time, piece};
}

int main() {
    cin >> n >> m;
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    pi answer = solution();
    cout << answer.first << '\n' << answer.second;
    return 0;
}