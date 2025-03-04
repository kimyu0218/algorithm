#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
const int CNT = 10;

int answer = -1; // 구슬 움직이는 횟수
string action; // 동작
char direction[] = {'L', 'R', 'U', 'D'};
int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0}; // 좌 우 상 하

bool isRedFirst(pi &red, pi &blue, int dir) { // 빨간 구슬이 먼저 움직이는가
    if(dir == 0) { // L 왼쪽으로 기울이기
        return red.second < blue.second;
    }
    if(dir == 1) { // R 오른쪽으로 기울이기
        return red.second > blue.second;
    }
    if(dir == 2) { // U 위쪽으로 기울이기
        return red.first < blue.first;
    }
    return red.first > blue.first; // D 아래쪽으로 기울이기
}

bool canEscape(char color, int dir, pi &bead, vector<vector<char>> &board) { // color의 구슬이 구멍에 빠지는 가
    int sr = bead.first, sc = bead.second;
    board[sr][sc] = '.'; // 현재 구슬 빈칸 처리

    int r = sr + dr[dir], c = sc + dc[dir];
    while(board[r][c] == '.') { // 빈 칸인 경우, 계속 굴러감
        r += dr[dir];
        c += dc[dir];
    }

    // 1. 구멍에 빠지는 경우
    if(board[r][c] == 'O') {
        return true;
    }
    // 2. 장애물을 마주친 경우
    int er = r - dr[dir], ec = c - dc[dir];
    board[er][ec] = color; // 구슬이 멈추는 위치 갱신
    bead = {er, ec};
    return false;
}

void backtracking(int cnt, pi red, pi blue, string cmd, vector<vector<char>> board) {
    if(cnt == CNT) { // 10번 이하로 탈출 불가
        return;
    }

    for(int i = 0; i < 4; i++) { // i : 방향
        bool red_first = isRedFirst(red, blue, i);
        vector<vector<char>> tmp_board = board;
        pi tmp_red = red, tmp_blue = blue;

        // 1. 빨간 구슬이 먼저 움직이는 경우
        if(red_first) {
            bool r_escape = canEscape('R', i, tmp_red, tmp_board);
            bool b_escape = canEscape('B', i, tmp_blue, tmp_board);
            if(r_escape && !b_escape) { // 1-1. 빨간 구슬 탈출 성공
                string tmp = cmd + direction[i];
                if(answer == -1) {
                    answer = cnt+1;
                    action = tmp;
                }
                else if(answer > cnt+1){
                    answer = cnt+1;
                    action = tmp;
                }
                return;
            }
            if(!r_escape && !b_escape) { // 1-2. 빨간 구슬, 파란 구슬 새 위치로 이동
                backtracking(cnt+1, tmp_red, tmp_blue, cmd + direction[i], tmp_board);
            }
        }
        // 2. 파란 구슬이 먼저 움직이는 경우
        else {
            bool b_escape = canEscape('B', i, tmp_blue, tmp_board);
            bool r_escape = canEscape('R', i, tmp_red, tmp_board);
            if(r_escape && !b_escape) { // 2-1. 빨간 구슬 탈출 성공
                string tmp = cmd + direction[i];
                if(answer == -1) {
                    answer = cnt+1;
                    action = tmp;
                }
                else if(answer > cnt+1){
                    answer = cnt+1;
                    action = tmp;
                }
                return;
            }
            if(!r_escape && !b_escape) { // 2-2. 빨간 구슬, 파란 구슬 새 위치로 이동
                backtracking(cnt+1, tmp_red, tmp_blue, cmd + direction[i], tmp_board);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    string input;
    pi red, blue; // 빨간 구슬, 파란 구슬 위치 저장
    vector<vector<char>> board;

    cin >> n >> m;
    board.assign(n, vector<char> (m, '\0'));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            board[i][j] = input[j];
            if(board[i][j] == 'R') {
                red = {i, j};
            }
            else if(board[i][j] == 'B') {
                blue = {i, j};
            }
        }
    }

    backtracking(0, red, blue, "", board);
    cout << answer << '\n';
    for(int i = 0; i < answer; i++) {
        cout << action[i];
    }
    return 0;
}