#include <iostream>

using namespace std;

const int SIZE = 19;
bool stop = false; // (승자 찾으면 탐색 종료하기 위함)
int winner = 0, row, col;
int board[SIZE+1][SIZE+1]; // 오목판
// 방향 : 오른쪽, 우하향, 하향, 좌하향
int dr[4] = {0, 1, 1, 1}, dc[4] = {1, 1, 0, -1};

int dfs(int row, int col, int dir, int color) {
    if(row <= 0 || col <= 0 || row > SIZE || col > SIZE) return 0;
    if(board[row][col] != color) return 0;
    int sum = 1; // (row, col) 포함
    sum += dfs(row+dr[dir], col+dc[dir], dir, color);
    return sum;
}

void game() {
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            if(stop) return; // 승자 찾은 경우 함수 종료
            if(board[i][j]) { // 바둑돌 발견
                for(int k = 0; k < 4; k++) { // (k: 방향)
                    if(board[i-dr[k]][j-dc[k]] == board[i][j]) continue; // 6 이상인 경우 pass
                    if(dfs(i, j, k, board[i][j]) == 5) { // 바둑돌 5개 연속으로 발견
                        stop = true; winner = board[i][j];
                        if(k == 3) { // 1. 좌하향 : 가장 왼쪽의 돌 출력해야 함
                            row = i + dr[k]*4;
                            col = j + dc[k]*4;
                        }
                        else { row = i; col = j; } // 2. 나머지 방향 : 시작돌 위치
                    }
                }
            }
        }
    }
}

int main() {
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            cin >> board[i][j];
        }
    }

    game();
    cout << winner << '\n'; // 게임 결과 출력
    if(winner) cout << row << ' ' << col; // 게임의 승패가 정해진 경우 바둑돌 번호 입력
    return 0;
}