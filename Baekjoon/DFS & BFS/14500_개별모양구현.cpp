#include <iostream>
#include <vector>

using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> board, visited;

void backtracking(int row, int col, int sum, int len) { // 백트래킹
    if(len == 4) { // 정사각형 4개 이어붙인 경우
        answer = max(answer, sum);
        return;
    }

    int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우
    for(int i = 0; i < 4; i++) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];

        if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue; // 경계 넘어가는 경우
        if(visited[new_row][new_col]) continue; // 이미 방문한 경우

        visited[new_row][new_col] = true;
        backtracking(new_row, new_col, sum + board[new_row][new_col], len+1);
        visited[new_row][new_col] = false;
    }
}

void checkPink(int row, int col, int first) { // 핑크색 블록(ㅜ 블록) 모양 확인
    bool r_boundary1 = (row + 1 < n), r_boundary2 = (row + 2 < n), r_boundary3 = (row - 1 >= 0);
    bool c_boundary1 = (col + 1 < m), c_boundary2 = (col + 2 < m), c_boundary3 = (col - 1 >= 0);

    int sum;
    if(r_boundary1 && c_boundary2) { // ㅜ 모양
        sum = first + board[row][col + 1] + board[row][col + 2] + board[row + 1][col + 1];
        answer = max(answer, sum);
    }
    if(r_boundary2 && c_boundary1) { // ㅏ 모양
        sum = first + board[row + 1][col] + board[row + 2][col] + board[row + 1][col + 1];
        answer = max(answer, sum);
    }
    if(r_boundary3 && c_boundary2) { // ㅗ 모양
        sum = first + board[row][col + 1] + board[row][col + 2] + board[row - 1][col + 1];
        answer = max(answer, sum);
    }
    if(r_boundary2 && c_boundary3) { // ㅓ 모양
        sum = first + board[row + 1][col] + board[row + 2][col] + board[row + 1][col - 1];
        answer = max(answer, sum);
    }
}

void findMax() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true;
            backtracking(i, j, board[i][j], 1);
            visited[i][j] = false;
            checkPink(i, j, board[i][j]); // 핑크색 블록 확인
        }
    }
}

int main() {
    cin >> n >> m;

    board.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<int> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    findMax();
    cout << answer;
    return 0;
}