#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int sr, int sc, int er, int ec, int l, vector<vector<int>> &board) {
    queue<pair<int, int>> q;
    q.push({sr, sc}); board[sr][sc] = 0;

    int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(row == er && col == ec) return board[row][col];

        for(int i = 0; i < 8; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];

            // 아직 방문하지 않은 좌표
            if(new_row >= 0 && new_col >= 0 && new_row < l && new_col < l && board[new_row][new_col] == -1) {
                board[new_row][new_col] = board[row][col] + 1;
                q.push({new_row, new_col});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    int l, sr, sc, er, ec;
    while(t--) { // 테스트 케이스
        cin >> l;
        vector<vector<int>> board(l, vector<int> (l, -1));
        cin >> sr >> sc;
        cin >> er >> ec;
        cout << bfs(sr, sc, er, ec, l, board) << '\n';
    }
    return 0;
}