#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; // 북 남 서 동
struct info {
    int x, y, d;
};
vector<vector<int>> board;
vector<vector<bool>> collapse;

int attack(int n, int m, int sx, int sy, int d) {
    int cnt = 1;
    queue<pi> q;

    collapse[sx][sy] = true;
    q.push({sx, sy});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int h = board[x][y];
        for(int i = 1; i < h; i++) {
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                break;
            }
            if(!collapse[nx][ny]) {
                collapse[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

int dominoGame(int n, int m, int r, vector<info> cmd) { // 공격수 점수 구하기
    int score = 0, x, y, d;
    for(int i = 0; i < 2*r; i+=2) {
        // 1. 공격수 공격
        x = cmd[i].x, y = cmd[i].y, d = cmd[i].d;
        if(!collapse[x][y]) { // 해당 도미노가 쓰러지지 않은 경우, 공격 유효
            score += attack(n, m, x, y, d);
        }
        // 2. 수비수 공격
        x = cmd[i+1].x, y = cmd[i+1].y;
        collapse[x][y] = false;
    }
    return score;
}

int main() {
    int n, m, r, x, y;
    char d;
    map<char, int> dir = {{'E', 3}, {'W', 2}, {'S', 1}, {'N', 0}};
    vector<info> cmd;

    cin >> n >> m >> r;
    board.assign(n, vector<int> (m, 0));
    collapse.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cmd.assign(2*r, {0, 0, '\0'});
    for(int i = 0; i < 2*r; i+=2) {
        cin >> x >> y >> d;
        cmd[i] = {x-1, y-1, dir[d]};
        cin >> x >> y;
        cmd[i+1] = {x-1, y-1, '\0'};
    }

    cout << dominoGame(n, m, r, cmd) << '\n';
    for(int i = 0; i < n; i++) { // 도미노 상태 출력
        for(int j = 0; j < m; j++) {
            cout << (collapse[i][j] ? "F " : "S ");
        }
        cout << '\n';
    }
    return 0;
}