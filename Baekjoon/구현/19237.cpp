#include <iostream>
#include <vector>

using namespace std;

struct info {
    int num, time; // 냄새의 주인(==상어의 번호), 냄새의 유효기간
};
struct info2 {
    int r, c, d;
};
const int OUT = -1, MAX = 1e3;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우

int n, m, k;
vector<vector<info>> board;
vector<vector<vector<int>>> dir;
vector<info2> shark;

void loseSmell() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j].num && --board[i][j].time == 0) {
                board[i][j].num = 0;
            }
        }
    }
}

void move() {
    vector<info2> next = {{}}; // 상어가 이동할 위치

    for(int i = 1; i <= m; i++) { // i : 상어 번호
        int r = shark[i].r, c = shark[i].c;
        if(r == OUT && c == OUT) { // 격자 밖으로 나간 상어 pass
            next.push_back({OUT, OUT, OUT});
            continue;
        }

        // 1. 인접한 칸 검사
        int d = shark[i].d;
        vector<info2> no_smell, my_smell;
        for(int j = 0; j < 4; j++) {
            int nd = dir[i][d][j];
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if(board[nr][nc].num == 0) { // 1-1. 무향의 칸 발견
                    no_smell.push_back({nr, nc, nd});
                }
                else if(board[nr][nc].num == i) { // 2-1. 자신의 냄새가 있는 칸 발견
                    my_smell.push_back({nr, nc, nd});
                }
            }
        }

        // 2. 상어가 이동할 칸 지정
        if(!no_smell.empty()) { // 2-1. 무향의 칸이 있는 경우, 무향의 칸으로 이동
            next.push_back({no_smell[0]});
        }
        else { // 2-2. 무향의 칸이 없는 경우, 자신의 냄새가 있는 칸으로 이동
            next.push_back({my_smell[0]});
        }
    }

    loseSmell(); // 상어의 이동 위치를 지정했으므로 냄새 줄어기

    // 3. 상어의 이동 및 냄새뿌리기
    for(int i = 1; i <= m; i++) { // i : 상어 번호
        int nr = next[i].r;
        int nc = next[i].c;
        int nd = next[i].d;
        if(nr == OUT && nc == OUT) { // 격자 밖으로 나간 상어 pass
            continue;
        }

        if(board[nr][nc].num == 0) { // 3-1. 무향의 칸에 냄새 쁘림
            board[nr][nc] = {i, k};
            shark[i] = {nr, nc, nd};
        }
        else if(board[nr][nc].num == i) { // 3-2. 자신의 냄새가 있던 칸에 냄새 뿌림
            board[nr][nc] = {i, k};
            shark[i] = {nr, nc, nd};
        }
        else { // 3-3. 이미 상위 포식자 상어가 있는 경우 격자 밖으로 쫓겨남
            shark[i] = {OUT, OUT, OUT};
        }
    }
}

bool oneShark() { // 상어가 한 마리 뿐인가
    // 1번 상어는 사라지지 않으므로 2번 상어부터 확인
    for(int i = 2; i <= m; i++) {
        int r = shark[i].r, c = shark[i].c;
        if(r >= 0 && c >= 0) {
            return false;
        }
    }
    return true;
}

int adultShark() {
    int time = 0;
    while(++time <= MAX) {
        move();

        // 1번 상어맘 격자에 남은 경우 time 리턴
        if(oneShark()) {
            return time;
        }
    }
    return -1;
}

int main() {
    int d, p, q, r, s;

    cin >> n >> m >> k;
    board.assign(n, vector<info> (n, {0, 0}));
    dir.assign(m+1, vector<vector<int>> (4, vector<int> (4, 0)));
    shark.assign(m+1, {});

    for(int i = 0; i < n; i++) { // 격자 정보 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].num;
            if(board[i][j].num) {
                shark[board[i][j].num] = {i, j};
                board[i][j].time = k;
            }
        }
    }

    // 상어 방향 입력
    for(int i = 1; i <= m; i++) { // i : 상어 번호
        cin >> d;
        shark[i].d = d-1;
    }

    // 상어 우선순위 입력
    for(int i = 1; i <= m; i++) { // i : 상어 번호
        for(int j = 0; j < 4; j++) { // j : 방향
            cin >> p >> q >> r >> s;
            dir[i][j] = {p-1, q-1, r-1, s-1};
        }
    }

    cout << adultShark();
    return 0;
}