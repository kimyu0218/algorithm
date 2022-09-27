#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int SIZE = 4;
int answer = 0;
int dc[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 반시계 방향 회전
bool ate[SIZE*SIZE+1];

void swap(int fr1, int fc1, int fnum1, int fdir1, int fr2, int fc2, int fnum2, int fdir2, vector<vector<int>> &a, vector<vector<int>> &b, vector<pi> &pos) { // 자리 바꾸기
    pos[fnum1] = {fr2, fc2}; pos[fnum2] = {fr1, fc1}; // 위치 바꾸기
    a[fr2][fc2] = fnum1; a[fr1][fc1] = fnum2; // 번호 바꾸기
    b[fr2][fc2] = fdir1; b[fr1][fc1] = fdir2; // 방향 바꾸기
}

void move(int row, int col, vector<vector<int>> &a, vector<vector<int>> &b, vector<pi> &pos) { // 번호가 작은 물고기부터 순서대로 이동
    // (row, col) : 현재 상어 위치
    for(int i = 1; i <= SIZE*SIZE; i++) { // i : 이동할 물고기 번호 (작은 물고기부터 이동)
        pi fish = pos[i];
        int dir = b[fish.first][fish.second];

        if(ate[i]) continue; // 잡아먹힌 물고기 pass
        if(fish.first == row && fish.second == col) continue; // 상어가 있는 위치 pass

        for(int j = 0; j < 8; j++) { // 45도 반시계 회전
            int new_dir = (dir + j) % 8;
            int fr = fish.first + dr[new_dir], fc = fish.second + dc[new_dir];
            b[fish.first][fish.second] = new_dir;

            // 상어가 있거나 공간의 경계를 넘는 경우 이동 불가
            if(fr == row && fc == col) continue;
            if(fr < 0 || fr >= SIZE || fc < 0 || fc >= SIZE) continue;

            // 서로 자리 바꾸기
            swap(fish.first, fish.second, i, new_dir, fr, fc, a[fr][fc], b[fr][fc], a, b, pos);
            break;
        }
    }
}

void backtracking(int row, int col, int sum, vector<vector<int>> a, vector<vector<int>> b, vector<pi> pos) {
    // (row, col) : 잡아먹는 물고기 위치
    // sum : 잡아먹은 물고기 번호 합

    // 1. 물고기 잡아먹음
    int num = a[row][col];
    a[row][col] = 0; ate[num] = true; // (물고기 잡아먹기)

    // 2. 물고기 이동
    move(row, col, a, b, pos);

    // 3. 먹이 탐색
    int dir = b[row][col]; // 상어의 먹이 탐색 방향 (= 잡아먹은 물고기 방향)
    for(int i = 1; i < SIZE; i++) {
        int new_row = row + dr[dir] * i, new_col = col + dc[dir] * i; // 잡아먹을 수 있는 물고기 위치

        // 3-1. 상어가 물고기를 잡아먹을 수 없는 경우
        if(new_row < 0 || new_col < 0 || new_row >= SIZE || new_col >= SIZE) break; // 공간의 경계를 벗어남
        if(!a[new_row][new_col] || ate[a[new_row][new_col]]) continue; // 잡아먹을 물고기가 없음

        // 3-2. 상어가 물고기 잡아먹는 경우
        backtracking(new_row, new_col, sum + num, a, b, pos);
    }

    answer = max(answer, sum + num); // 최댓값 갱신
    a[row][col] = num; ate[num] = false; // (물고기 잡아먹지 않음)
}

int main() {
    vector<vector<int>> a(SIZE, vector<int> (SIZE, 0)), b(SIZE, vector<int> (SIZE, 0)); // 물고기 번호, 방향
    vector<pi> pos (SIZE*SIZE+1, {0, 0}); // 물고기별 위치

    for(int i = 0; i < SIZE; i++) { // 물고기 정보 입력
        for(int j = 0; j < SIZE; j++) {
            cin >> a[i][j] >> b[i][j];
            b[i][j]--;
            pos[a[i][j]] = {i, j};
        }
    }

    backtracking(0, 0, 0, a, b, pos);
    cout << answer;
    return 0;
}