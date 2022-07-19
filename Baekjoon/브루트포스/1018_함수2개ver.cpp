#include <iostream>
#include <vector>

using namespace std;

// 1. 맨 왼족 위 칸이 흰색인 경우
int white_first(vector<vector<char>> board, int y, int x) {
    int cnt = 0;
    for(int i = y; i < y+8; i++) {
        for(int j = x; j < x+8; j++) {
            if((i + j) % 2 == 0 && board[i][j] == 'B') cnt++; // 검은색으로 잘못 칠해진 경우
            else if((i + j) % 2 && board[i][j] == 'W') cnt++; // 흰색으로 잘못 칠해진 경우
        }
    }
    return cnt;
}

// 2. 맨 왼족 위 칸이 검은색인 경우
int black_first(vector<vector<char>> board, int y, int x) {
    int cnt = 0;
    for(int i = y; i < y+8; i++) {
        for(int j = x; j < x+8; j++) {
            if((i + j) % 2 == 0 && board[i][j] == 'W') cnt++; // 흰색으로 잘못 칠해진 경우
            else if((i + j) % 2 && board[i][j] == 'B') cnt++; // 검은색으로 잘못 칠해진 경우
        }
    }
    return cnt;
}

int main() {
    int m, n;
    cin >> n >> m;

    vector<vector<char>> board;
    board.assign(n, vector<char>(m, '\0'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int min_cnt = 64;
    for(int i = 0; i <= n-8; i++) {
        for(int j = 0; j <= m-8; j++)
            min_cnt = min(min_cnt, min(white_first(board, i, j), black_first(board, i, j)));
    }
    cout << min_cnt;
    return 0;
}