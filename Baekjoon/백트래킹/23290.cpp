#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 4; // 격자 크기
typedef pair<int, int> pi;
struct info { // 물고기 정보
    int row, col, dir;
};

int remove_cnt; // 격자에서 제거되는 물고기 수
int path[3], tmp[3]; // (path : 상어의 이동 경로, tmp : 백트래킹 경로)
int sr[4] = {-1, 0, 1, 0}, sc[4] = {0, -1, 0, 1}; // 상 좌 하 우
int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 물고기 이동방향
pi shark;
vector<vector<int>> smell; // 냄새 유효시간
vector<vector<queue<int>>> board; // board[i][j] : (i,j)에 있는 물고기 번호
vector<info> fish, replica; // 물고기, 물고기 복제본

void moveFish() { // 물고기의 이동
    for(int i = 1; i < fish.size(); i++) {
        int row = fish[i].row, col = fish[i].col;
        if(row == -1 && col == -1) { // 제거된 물고기 pass
            continue;
        }

        int dir = fish[i].dir;
        board[row][col].pop(); // 현재 칸에서 물고기 제거

        for(int j = 0; j < 8; j++) {
            int nr = row + dr[dir];
            int nc = col + dc[dir];
            // 1. 이동 가능한 칸 발견
            if(nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && !smell[nr][nc] && (shark.first != nr || shark.second != nc)) {
                row = nr; col = nc;
                break;
            }
            // 2. 이동 가능한 발견할 때까지 반시계 방향으로 회전
            dir = (dir + 7) % 8;
        }
        // 3. 물고기 이동 완료
        fish[i] = {row, col, dir};
        board[row][col].push(i); // 새로운 칸에 물고기 push
    }
}

void backtracking(int sx, int sy, int cnt, int idx, vector<vector<bool>> visited) { // 상어가 이동할 수 있는 경로 백트래킹
    if(idx == 3) { // 기저 조건
        if(cnt > remove_cnt) { // 1. 제거되는 물고기가 가장 많은 경로 발견
            remove_cnt = cnt;
            for(int i = 0; i < 3; i++) {
                path[i] = tmp[i];
            }
        }
        else if(cnt == remove_cnt) { // 2. 사전순으로 앞서는 경로 검사
            string a = "", b = "";
            for(int i = 0; i < 3; i++) {
                a += path[i];
                b += tmp[i];
            }
            if(b < a) { // 새로운 경로가 사전순으로 앞서는 경우, 상어 이동 경로 갱신
                for(int i = 0; i < 3; i++) {
                    path[i] = tmp[i];
                }
            }
        }
        return;
    }

    for(int i = 0; i < 4; i++) { // i : 방향
        int nr = sx + sr[i];
        int nc = sy + sc[i];
        if(nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
            tmp[idx] = i;
            if(!visited[nr][nc]) { // 1. 처음 방문하는 칸의 경우, 물고기 잡아먹음
                visited[nr][nc] = true;
                backtracking(nr, nc, cnt + board[nr][nc].size(), idx+1, visited);
            }
            else { // 2. 이미 방문한 칸인 경우, 이미 잡아먹어서 물고기 잡아먹지 못함
                backtracking(nr, nc, cnt, idx+1, visited);
            }
            visited[nr][nc] = false;
        }
    }
}

void moveShark() { // 상어의 이동
    for(int i = 0; i < 3; i++) { // 상어 3칸 이동
        int dir = path[i];
        int nr = shark.first + sr[dir];
        int nc = shark.second + sc[dir];

        // 1. 물고기 냄새 남김
        if(!board[nr][nc].empty()) {
            smell[nr][nc] = 3; // 냄새 남김 (4번에서 냄새가 바로 줄어들기 때문에 +1한 값 넣어주기)
        }
        // 2. 물고기 격자에서 제외시킴
        while(!board[nr][nc].empty()) {
            int f = board[nr][nc].front();
            board[nr][nc].pop();
            fish[f].row = -1; fish[f].col = -1; // 물고기 제거
        }
        shark = {nr, nc}; // 상어 이동
    }
}

void removeSmell() { // 냄새 제거하기
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(smell[i][j]) {
                smell[i][j]--;
            }
        }
    }
}

void replicateFish() { // 복제 마법 완료
    for(int i = 1; i < replica.size(); i++) {
        if(replica[i].row == -1 && replica[i].col == -1) { // 존재하지 않는 물고기 pass
            continue;
        }
        fish.push_back(replica[i]);
        int row = replica[i].row, col = replica[i].col;
        board[row][col].push(fish.size()-1);
    }
}

int magic(int s) { // 상어의 마법 연습
    int cnt = 0; // 격자에 있는 물고기 수
    while(s--) {
        // 1. 복제 마법 시작
        replica = fish;
        // 2. 모든 물고기 한 칸 이동
        moveFish();

        // 3. 상어 연속 3칸 이동
        // 3-1. 초기화
        remove_cnt = -1;
        vector<vector<bool>> visited(SIZE, vector<bool> (SIZE, false));
        // 3-2. 경로 선정
        backtracking(shark.first, shark.second, 0, 0, visited);
        // 3-3. 상어 실제로 이동
        moveShark();

        // 4. 물고기 냄새 사라짐
        removeSmell();
        // 5. 복제 마법 완료
        replicateFish();
    }

    // 물고기 수 세기
    for(int i = 1; i < fish.size(); i++) {
        if(fish[i].row != -1 && fish[i].col != -1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int m, s, fx, fy, d, sx, sy;

    cin >> m >> s;
    smell.assign(SIZE, vector<int> (SIZE, 0));
    board.assign(SIZE, vector<queue<int>> (SIZE, queue<int> ()));
    fish.assign(m+1, {});
    for(int i = 1; i <= m; i++) { // 물고기 정보 입력
        cin >> fx >> fy >> d;
        fish[i] = {fx-1, fy-1, d-1};
        board[fx-1][fy-1].push(i);
    }
    cin >> sx >> sy; // 상어 시작 위치 입력
    shark = {sx-1, sy-1};

    cout << magic(s);
    return 0;
}