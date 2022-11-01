#include <iostream>
#include <vector>

using namespace std;

int result = 0; // 상근이가 먹을 수 있는 사탕의 최대 기수
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void cntCandy(int n, vector<vector<char>> board) {

    // 가로줄에 있는 사탕 개수 세기
    for(int i = 0; i < n; i++) { // i : row
        int cnt = 1;
        char pre = board[i][0];

        for(int j = 1; j < n; j++) { // j : col
            if(pre != board[i][j]) {
                result = max(result, cnt);
                cnt = 1; pre = board[i][j];
            }
            else cnt++;
        }
        result = max(result, cnt);
    }

    // 세로줄에 있는 사탕 개수 세기
    for(int i = 0; i < n; i++) { // i : col
        int cnt = 1;
        char pre = board[0][i];

        for(int j = 1; j < n; j++) { // j : row
            if(pre != board[j][i]) {
                result = max(result, cnt);
                cnt = 1; pre = board[j][i];
            }
            else cnt++;
        }
        result = max(result, cnt);
    }
}

void bomboni(int n, vector<vector<char>> board) { // 봄보니 게임
    cntCandy(n, board); // 초기 사탕 개수 세기

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char color = board[i][j];
            for(int k = 0; k < 4; k++) { // 인접한 칸 검사
                int nr = i + dy[k], nc = j + dx[k];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue; // 보드 경계를 벗어나는 경우

                char new_color = board[nr][nc];
                if(color == new_color) continue; // 같은 색상 pass

                board[i][j] = new_color; board[nr][nc] = color; // swap
                cntCandy(n, board); // 사탕 개수 세기
                board[i][j] = color; board[nr][nc] = new_color; // 보드 원상태로 복구
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '\0'));
    string input;
    for(int i = 0; i < n; i++) { // 사탕 색상 입력
        cin >> input;
        for(int j = 0; j < n; j++) {
            board[i][j] = input[j];
        }
    }

    bomboni(n, board);
    cout << result;
    return 0;
}