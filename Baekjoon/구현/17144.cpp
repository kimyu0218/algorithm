#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> room;
vector<int> air_purifier;

int measure_dust(int r, int c) {
    int amount = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(room[i][j] > 0) amount += room[i][j];
        }
    }
    return amount;
}

void clockwise(int r, int c, int up_row) { // 시계 방향 회전
    for(int i = up_row-1; i >= 0; i--) room[i+1][0] = room[i][0];
    room[up_row][0] = 0; // 정화
    for(int i = 1; i < c; i++) room[0][i-1] = room[0][i];
    for(int i = 1; i <= up_row; i++) room[i-1][c-1] = room[i][c-1];
    for(int i = c-2; i >= 0; i--) room[up_row][i+1] = room[up_row][i];
}

void counter_clockwise(int r, int c, int down_row) { // 반시계 방향 회전
    for(int i = down_row+1; i < r; i++) room[i-1][0] = room[i][0];
    room[down_row][0] = 0; // 정화
    for(int i = 1; i < c; i++) room[r-1][i-1] = room[r-1][i];
    for(int i = r-2; i >= down_row; i--) room[i+1][c-1] = room[i][c-1];
    for(int i = c-2; i >= 0; i--) room[down_row][i+1] = room[down_row][i];
}

int spread(int r, int c, int t) {
    int time = 0;
    int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

    while(time < t) {
        vector<vector<int>> tmp = room;

        for(int i = 0; i < r; i++) { // i : row
            for(int j = 0; j < c; j++) { // j : col
                if(room[i][j] <= 0) continue;

                // 미세먼지 확산
                int cnt = 0, arc = room[i][j] / 5; // 방향 개수, 확산량
                for(int k = 0; k < 4; k++) {
                    int new_row = i + dy[k], new_col = j + dx[k];
                    // 공기 청정기가 없는 인접한 칸으로 확산
                    if(new_row >= 0 && new_row < r && new_col >= 0 && new_col < c && room[new_row][new_col] != -1) {
                        cnt++;
                        tmp[new_row][new_col] += arc;
                    }
                }
                tmp[i][j] -= (arc * cnt);
            }
        }
        room = tmp;

        // 공기청정기 작동
        int up_row = air_purifier[0], down_row = air_purifier[1];
        clockwise(r, c, up_row);
        counter_clockwise(r, c, down_row);

        room[up_row][0] = room[down_row][0] = -1;
        time++;
    }

    return measure_dust(r, c);
}

int main() {
    int r, c, t;
    cin >> r >> c >> t;

    room.assign(r, vector<int> (c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> room[i][j];
            if(room[i][j] == -1) air_purifier.push_back(i);
        }
    }

    cout << spread(r, c, t);
    return 0;
}