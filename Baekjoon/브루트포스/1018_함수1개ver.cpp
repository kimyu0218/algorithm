#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 64; // 체스판 칸 개수

int chessChange(int row, int cal, vector<vector<char>> &board) {
    int b_cnt = 0; // B로 시작하는 체스판
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i+j) % 2 == 0 && board[row+i][cal+j] != 'B')
                b_cnt++;
            else if((i+j) % 2 && board[row+i][cal+j] != 'W')
                b_cnt++;
        }
    }
    if(b_cnt > SIZE / 2) return SIZE - b_cnt;
    return b_cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    int ans = SIZE + 1; // 정답 초기화

    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i <= n-8; i++) {
        for(int j = 0; j <= m-8; j++) {
            int cnt = chessChange(i, j, board);
            ans = min(ans, cnt);
        }
    }

    cout << ans;
    return 0;
}