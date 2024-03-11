#include <iostream>
#include <vector>

using namespace std;
const int DISAPPEAR = -1;

struct info{
    int r, c, s, d, z; // 상어 위치, 속력, 이동 방향, 크기
};
typedef pair<int, int> pi;
int r, c, m;
vector<vector<pi>> board; // (first : 상어 번호, second : 차례)
vector<info> shark;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, 1, -1}; // 상 하 우 좌

int reverseDirection(int dir) { // 역방향 인덱스 계산
    return (dir/2)*2 + ((dir+1)%2);
}

void moveSharkToEdge(int &row, int &col, int nr, int nc, int &cells) { // 상어 가장자리로 이동시키고 남은 칸 수 세팅
    if(nr < 1) { // 1. 맨 윗칸으로 이동
        cells -= row-1;
        cells %= 2*(r-1); // 왕복하여 제자리
        row = 1;
        return;
    }
    if(nr > r) { // 2. 맨 아랫칸으로 이동
        cells -= r-row;
        cells %= 2*(r-1); // 왕복하여 제자리
        row = r;
        return;
    }
    if(nc < 1) { // 3. 맨 왼쪽칸으로 이동
        cells -= col-1;
        cells %= 2*(c-1); // 왕복하여 제자리
        col = 1;
        return;
    }
    // 4. 맨 오른쪽칸으로 이동
    cells -= c-col;
    cells %= 2*(c-1); // 왕복하여 제자리
    col = c;
}

void moveSharks(int turn) { // 상어 이동
    for(int i = 1; i <= m; i++) {
        if(shark[i].z == DISAPPEAR) { // 사라진 상어 pass
            continue;
        }

        int row = shark[i].r, col = shark[i].c;
        int cells = shark[i].s, dir = shark[i].d;
        int nr = row + dr[dir] * cells, nc = col + dc[dir] * cells;
        int back = dir; // 반대 방향

        if(board[row][col].second != turn) { // turn초에 새롭게 이동된 상어가 아니라면 (row, col)에서 상어 제거
            board[row][col] = {0, 0};
        }
        
        while(nr < 1 || nr > r || nc < 1 || nc > c) { // 격자에서 벗어나는 경우, 반대 방향으로 이동
            back = reverseDirection(back);
            moveSharkToEdge(row, col, nr, nc, cells);
            nr = row + dr[back] * cells;
            nc = col + dc[back] * cells;
            shark[i].d = back; // 상어 방향 재설정
        }
        
        int num = i; // (nr, nc)에 이동할 상어 번호
        if(board[nr][nc].second == turn) { // 이동하려는 칸에 상어가 있는 경우, 상어 크기 비교하기
            int prey; // 피식자 번호 (==먹히는 상어 번호)
            int cmp = board[nr][nc].first;
            if(shark[cmp].z < shark[i].z) { // i: 포식자, cmp: 피식자
                prey = cmp;
            }
            else { // cmp: 포식자, i: 피식자
                prey = i;
                num = cmp;
            }
            shark[prey].z = DISAPPEAR;
        }
        
        // 상어 이동
        shark[num].r = nr; shark[num].c = nc;
        board[nr][nc] = {num, turn};
    }
}

int fishing() { // 낚시왕이 잡은 상어 크기의 합
    int sum = 0;
    for(int j = 1; j <= c; j++) { // 1. 낚시왕 오른쪽으로 한 칸 이동
        // 2. 가장 가까운 상어 잡기
        for(int i = 1; i <= r; i++) {
            if(board[i][j].first) { // 잡을 수 있는 상어 발견
                int num = board[i][j].first;
                sum += shark[num].z;
                shark[num].z = DISAPPEAR;
                board[i][j] = {0, 0}; // 격자 비워짐
                break;
            }
        }
        // 3. 상어 이동
        moveSharks(j);
    }
    return sum;
}

int main() {
    int sr, sc, ss, sd, sz;

    cin >> r >> c >> m;
    board.assign(r+1, vector<pi> (c+1, {0, 0}));
    shark.assign(m+1, {0, 0, 0, 0, 0});
    for(int i = 1; i <= m; i++) {
        cin >> sr >> sc >> ss >> sd >> sz;
        shark[i] = {sr, sc, ss, sd-1, sz};
        board[sr][sc] = {i, 0};
    }

    cout << fishing();
    return 0;
}