#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 3;

int answer = -1;

bool ladderGame(int n, int h, vector<vector<bool>> &board) {
    for(int i = 0; i < n; i++) { // i : 열
        int dst = i;
        for(int j = 0; j < h; j++) { // j : 행
            if(board[j][dst]) { // 오른쪽으로 이동
                dst++;
            }
            else if(dst && board[j][dst-1]) { // 왼쪽으로 이동
                dst--;
            }
        }
        if(i != dst) {
            return false;
        }
    }
    return true;
}

void backtracking(int cnt, int a, int b, int n, int h, vector<vector<bool>> &board) {
    bool stop = ladderGame(n, h, board);
    if(stop) {
        if(answer == -1) {
            answer = cnt;
        }
        else {
            answer = min(answer, cnt);
        }
    }
    if(cnt == SIZE || b == n-1) { // 기저조건
        return;
    }

    // b번째 세로선에 사다리 놓기
    for(int j = a; j < h; j++) { // j : 행
        if(board[j][b]) { // 이미 사다리가 있는 곳 pass
            continue;
        }
        board[j][b] = true;
        backtracking(cnt+1, j+1, b, n, h, board);
        board[j][b] = false;
    }
    // b번째 세로선에 놓지 않고 b+1번째로 넘어가기
    backtracking(cnt, 0, b+1, n, h, board);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, h, a, b;
    vector<vector<bool>> board;

    cin >> n >> m >> h;
    board.assign(h, vector<bool> (n, false));
    while(m--) { // a 가로 / b 세로
        cin >> a >> b;
        board[a-1][b-1] = true;
    }

    backtracking(0, 0, 0, n, h, board);
    cout << answer;
    return 0;
}