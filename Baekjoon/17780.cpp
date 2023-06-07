#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = 4, TURN = 1e3;
int dr[4] = {0, 0, -1, 1}, dc[4] = {1, -1, 0, 0}; // 우 좌 상 하
struct info1 {
    int row, col, dir, top, bottom;
};
struct info2 {
    int color;
    vector<int> chessman;
};
vector<info1> chessman;
vector<vector<info2>> board;

void stackUpChessman(int row, int col, int cnt, vector<int> &moves) {
    int top, start;
    if(cnt) { // 1. (row, col)에 다른 말이 있는 경우
        top = board[row][col].chessman[cnt-1];
        start = 0;
    }
    else { // 2. (row, col)에 다른 말이 없는 경우
        top = moves[0];
        board[row][col].chessman.push_back(top);
        chessman[top].row = row; chessman[top].col = col;
        //chessman[top].bottom = -1;
        start = 1;
    }
    for(int i = start; i < moves.size(); i++) { // top 위에 num 쌓기
        int num = moves[i];
        chessman[top].top = num;
        board[row][col].chessman.push_back(num);
        chessman[num].row = row; chessman[num].col = col;
        chessman[num].top = -1; chessman[num].bottom = top;
        top = num;
    }
}

void reverseChessman(vector<int> &moves) {
    reverse(moves.begin(), moves.end());
    for(int i = 0; i < moves.size(); i++) {
        int num = moves[i];
        int tmp = chessman[num].top;
        chessman[num].top = chessman[num].bottom;
        chessman[num].bottom = tmp;
    }
}

void moveToWhite(int r, int c, int nr, int nc, int next_cnt, vector<int> &moves) {
    board[r][c].chessman = {};
    stackUpChessman(nr, nc, next_cnt, moves);
}

void moveToRed(int r, int c, int nr, int nc, int next_cnt, vector<int> &moves) {
    board[r][c].chessman = {};
    reverseChessman(moves);
    stackUpChessman(nr, nc, next_cnt, moves);
}

bool reverseDirection(int r, int c, int d, int n, int curr_cnt, vector<int> &moves) {
    int bd = (d % 2) ? d-1 : d+1; // 반대 방향
    chessman[moves[0]].dir = bd; // a번 말 방향 전환

    int br = r + dr[bd], bc = c + dc[bd];
    if(br >= 0 && br < n && bc >= 0 && bc < n) {
        int b_color = board[br][bc].color;
        int next_cnt = board[br][bc].chessman.size();

        if(b_color == 0) { // 1. 반대 방향이 흰색 칸인 경우
            if(next_cnt + curr_cnt >= MIN) {
                return true;
            }
            moveToWhite(r, c, br, bc, next_cnt, moves);
        }
        else if(b_color == 1) { // 2. 반대 방향이 빨간색 칸인 경우
            if(next_cnt + curr_cnt >= MIN) {
                return true;
            }
            moveToRed(r, c, br, bc, next_cnt, moves);
        }
        // 3. 반대 방향이 파란색인 경우 가만히 있기
    }
    return false;
}

int chessGame(int n, int k) {
    int turn = 0;
    while(++turn <= TURN) { // 턴이 1000을 넘지 않는 경우
        for(int a = 0; a < k; a++) { // a번 말의 이동
            int r = chessman[a].row, c = chessman[a].col;
            int d = chessman[a].dir;
            int top = chessman[a].top, bottom = chessman[a].bottom;
            if(bottom != -1) { // 가장 아래에 있는 말이 아닌 경우
                continue;
            }

            vector<int> moves = {a}; // a번 말과 함께 이동하는 말들
            while(top != -1) {
                moves.push_back(top);
                top = chessman[top].top;
            }

            int nr = r + dr[d], nc = c + dc[d];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n) { // 1. 다른 칸으로 이동 가능한 경우
                int color = board[nr][nc].color;
                int curr_cnt = moves.size(); // 이번에 이동하는 말 개수
                int next_cnt = board[nr][nc].chessman.size(); // 이동하려는 칸의 말 개수

                if(color == 0) { // 1-1. 이동하려는 칸이 흰색인 경우
                    if(next_cnt + curr_cnt >= MIN) {
                        return turn;
                    }
                    moveToWhite(r, c, nr, nc, next_cnt, moves);
                }
                else if(color == 1) { // 1-2. 이동하려는 칸이 빨간색인 경우
                    if(next_cnt + curr_cnt >= MIN) {
                        return turn;
                    }
                    moveToRed(r, c, nr, nc, next_cnt, moves);
                }
                else if(color == 2) { // 1-3. 이동하려는 칸이 파란색인 경우
                    bool game_over = reverseDirection(r, c, d, n, curr_cnt, moves);
                    if(game_over) {
                        return turn;
                    }
                }
            }
            else { // 2. 체스판 밖으로 나가는 경우
                bool game_over = reverseDirection(r, c, d, n, moves.size(), moves);
                if(game_over) {
                    return turn;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, r, c, d;

    cin >> n >> k;
    board.assign(n, vector<info2> (n, {0, {}}));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].color;
        }
    }

    chessman.assign(k, {0, 0, 0, -1});
    for(int i = 0; i < k; i++) {
        cin >> r >> c >> d;
        chessman[i] = {r-1, c-1, d-1, -1, -1};
        board[r-1][c-1].chessman.push_back(i);
    }

    cout << chessGame(n, k);
    return 0;
}