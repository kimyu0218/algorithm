#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
struct info { // 블록 그룹 정보
    // 기준 행, 기준 열, 무지개 블록 개수, 총 블록 개수
    int row, col, rainbow, size;
};
typedef pair<int, int> pi;
const int RAINBOW = 0, BLACK = -1, BLANK = -2;
int n; // 격자판 크기
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0}; // 상 좌 우 하
vector<vector<int>> board; // 격자 정보

bool cmp(const info &i1, const info &i2) {
    if(i1.size != i2.size) { // 1. 크기가 가장 큰 블록 그룹 찾기
        return i1.size > i2.size;
    }
    if(i1.rainbow != i2.rainbow) { // 2. 무지개 블록 수가 가장 많은 블록 그룹
        return i1.rainbow > i2.rainbow;
    }
    if(i1.row != i2.row) { // 3. 기준 블록의 행이 가장 큰 것
        return i1.row > i2.row;
    }
    return i1.col > i2.col; // 4. 기준 블록의 열이 가장 큰 것
}

info bfs(int sr, int sc, vector<vector<bool>> &visited) { // bfs
    queue<pi> q;

    int size = 1, rainbow = 0;
    int color = board[sr][sc];
    q.push({sr, sc});
    visited[sr][sc] = true;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) { // 인접한 칸 탐색
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                // 같은 색상이나 무지개 색상 발견
                if(board[nr][nc] == color || board[nr][nc] == RAINBOW) {
                    rainbow += (board[nr][nc] == RAINBOW);
                    size++;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    if(size >= 2) { // 그룹에 속한 블록 개수가 2이상인 경우에만 유효
        return {sr, sc, rainbow, size};
    }
    return {-1, -1}; // 유효하지 않은 그룹
}

void resetRainbow(vector<vector<bool>> &visited) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == RAINBOW) {
                visited[i][j] = false;
            }
        }
    }
}

void removeGroup(int sr, int sc) { // 블록 그룹 제거
    queue<pi> q;

    int color = board[sr][sc]; // 블록 그룹의 색상
    q.push({sr, sc});
    board[sr][sc] = BLANK; // 빈칸 처리

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) { // 인접한 칸 탐색
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                // 같은 색상이나 무지개 색상 발견
                if(board[nr][nc] == color || board[nr][nc] == RAINBOW) {
                    board[nr][nc] = BLANK; // 빈칸 처리
                    q.push({nr, nc});
                }
            }
        }
    }
}

void rotate() { // 반시계 방향 회전
    vector<vector<int>> new_board(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            new_board[n-1-j][i] = board[i][j];
        }
    }
    board = new_board;
}

void gravity() {
    for(int j = 0; j < n; j++) { // j : 열
        for(int i = n-2; i >= 0; i--) { // i : 행
            // 현재 칸이 빈 칸이 아니고 검은색 블록이 아닌 경우
            if(board[i][j] != BLANK && board[i][j] != BLACK) {
                // 1. 이동할 행 번호 찾기
                int k, nr = i; // nr : 이동할 행 번호
                for(k = i+1; k < n; k++) {
                    if(board[k][j] != BLANK) { // 1-1. k행이 빈 칸이 아닌 경우 k-1까지 이동 가능
                        nr = k-1;
                        break;
                    }
                }
                if(k == n) { // 1-2. 맨 아랫칸까지 이동할 수 있는 경우
                    nr = n-1;
                }
                // 2. 중력 작용
                if(nr != i) {
                    board[nr][j] = board[i][j];
                    board[i][j] = BLANK;
                }
            }
        }
    }
}

int autoPlay() { // 오토 플레이 시작
    int score = 0; // 오토 플레이 점수
    while(true) {
        // 1. 크기가 가장 큰 블록 그룹 찾기
        vector<info> groups; // 블록 그룹 저장
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > 0 && !visited[i][j]) { // 일반 블록 발견
                    info tmp = bfs(i, j, visited);
                    if(tmp.row != -1 && tmp.col != -1) { // 유효한 그룹 발견
                        groups.push_back(tmp);
                    }
                    resetRainbow(visited);
                }
            }
        }
        if(groups.empty()) { // 종료 조건 (== 블록 그룹이 더 이상 존재하지 않는 경우)
            break;
        }
        sort(groups.begin(), groups.end(), cmp);

        // 2. 1번에서 찾은 블록 그룹 제거 & 점수 획득
        removeGroup(groups[0].row, groups[0].col);
        score += pow(groups[0].size, 2);

        // 3. 중력 작용
        gravity();

        // 4. 반시계 방향 회전
        rotate();

        // 5. 다시 중력 작용
        gravity();
    }
    return score;
}

int main() {
    int m;

    cin >> n >> m;
    board.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 격자 정보 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << autoPlay();
    return 0;
}