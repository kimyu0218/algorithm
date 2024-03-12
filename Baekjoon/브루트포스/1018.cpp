#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;
const char BLACK = 'B';
const char WHITE = 'W';

int cnt_repaint(int sr, int sc, vector<vector<char>> board) {
    int b_start_cnt = 0;
    int w_start_cnt = 0;

    for(int i = sr; i < sr + SIZE; i++) {
        for(int j = sc; j < sc + SIZE; j++) {
            if((i + j) % 2) {
                b_start_cnt += board[i][j] != WHITE;
                w_start_cnt += board[i][j] != BLACK;
            }
            else {
                b_start_cnt += board[i][j] != BLACK;
                w_start_cnt += board[i][j] != WHITE;
            }
        }
    }
    return min(b_start_cnt, w_start_cnt);
}

int solution(int n, int m, vector<vector<char>> board) {
    int result = SIZE * SIZE;

    for(int i = 0; i <= n - SIZE; i++) {
        for(int j = 0; j <= m - SIZE; j++) {
            result = min(result, cnt_repaint(i, j, board));
        }
    }
    return result;
}

int main() {
    int n, m;
    string line;
    vector<vector<char>> board;

    cin >> n >> m;

    board.assign(n, vector<char> (m, '\0'));
    for(int i = 0; i < n; i++) {
        cin >> line;
        for(int j = 0; j < m; j++) {
            board[i][j] = line[j];
        }
    }

    cout << solution(n, m, board);
    return 0;
}