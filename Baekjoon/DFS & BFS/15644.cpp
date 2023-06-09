#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int CNT = 10;
struct info {
    pi red, blue;
    int cnt;
    string action = "";
};
struct ans {
    int cnt;
    string action = "";
};
char direction[4] = {'L', 'R', 'U', 'D'};
int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0}; // 좌 우 상 하

void move(int &r, int &c, int dir, vector<vector<char>> &board) {
    while(board[r][c] != 'O' && board[r][c] != '#') {
        r += dr[dir];
        c += dc[dir];
    }
    if(board[r][c] == '#') {
        r -= dr[dir];
        c -= dc[dir];
    }
}

ans bfs(int n, int m, pi red, pi blue, vector<vector<char>> &board) {
    vector<vector<vector<vector<bool>>>> visited (n, vector<vector<vector<bool>>> (m, vector<vector<bool>> (n, vector<bool> (m, false))));
    queue<info> q;
    q.push({red, blue, 0, ""});

    while(!q.empty()) {
        red = q.front().red;
        blue = q.front().blue;
        int cnt = q.front().cnt;
        string action = q.front().action;
        q.pop();

        if(cnt == CNT) { // 10번 이하로 움직여서 빼낼 수 없는 경우 stop
            return {-1, ""};
        }

        for(int i = 0; i < 4; i++) {
            int rr = red.first, rc = red.second;
            int br = blue.first, bc = blue.second;

            move(rr, rc, i, board); // 빨간 구슬 이동
            move(br, bc, i, board); // 파란 구슬 이동

            if(board[br][bc] == 'O') { // 1-1. 파란 구슬 탈출 불가
                continue;
            }
            if(board[rr][rc] == 'O') { // 1-2. 빨간 구슬 탈출 성공
                return {cnt+1, action + direction[i]};
            }
            if(rr == br && rc == bc) { // 1-3. 빨간 구슬과 파란 구슬 같은 칸에 있을 수 없음
                int rd = abs(red.first - rr) + abs(red.second - rc);
                int bd = abs(blue.first - br) + abs(blue.second - bc);
                if(rd > bd) { // 빨간 구슬이 더 많이 움직인 경우
                    rr -= dr[i];
                    rc -= dc[i];
                }
                else { // 파란 구슬이 더 많이 움직인 경우
                    br -= dr[i];
                    bc -= dc[i];
                }
            }
            if(visited[rr][rc][br][bc]) { // 이미 방문한 경우 pass
                continue;
            }
            visited[rr][rc][br][bc] = true;
            q.push({{rr, rc}, {br, bc}, cnt+1, action + direction[i]});
        }
    }
    return {-1, ""}; // 구슬 탈출 불가
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    string input;
    pi red, blue;
    vector<vector<char>> board;

    cin >> n >> m;
    board.assign(n, vector<char> (m, '\0'));

    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            board[i][j] = input[j];
            if(board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    ans answer = bfs(n, m, red, blue, board);
    cout << answer.cnt << '\n';
    for(int i = 0; i < answer.cnt; i++) {
        cout << answer.action[i];
    }
    return 0;
}