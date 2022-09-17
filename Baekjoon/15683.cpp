#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
int n, m, answer = 64;
// 기존 카메라 방향 (회전 전)
vector<int> cam1 = {0}, cam2 = {0, 2}, cam3 = {0, 1}, cam4 = {0, 1, 2};
vector<vector<int>> room;

void up(int row, int col, vector<vector<int>> &copyed) { // 위쪽 방향 감시
    for(int i = row-1; i >= 0; i--) {
        if(copyed[i][col] == 6) break;
        else if(!copyed[i][col]) copyed[i][col] = -1;
    }
}

void down(int row, int col, vector<vector<int>> &copyed) { // 아래쪽 방향 감시
    for(int i = row+1; i < n; i++) {
        if(copyed[i][col] == 6) break;
        else if(!copyed[i][col]) copyed[i][col] = -1;
    }
}

void left(int row, int col, vector<vector<int>> &copyed) { // 왼쪽 방향 감시
    for(int i = col-1; i >= 0; i--) {
        if(copyed[row][i] == 6) break;
        else if(!copyed[row][i]) copyed[row][i] = -1;
    }
}

void right(int row, int col, vector<vector<int>> &copyed) { // 오른쪽 방향 감시
    for(int i = col+1; i < m; i++) {
        if(copyed[row][i] == 6) break;
        else if(!copyed[row][i]) copyed[row][i] = -1;
    }
}

void supervise(int row, int col, int camera, int dir, vector<vector<int>> &copyed) {
    vector<int> directions;
    switch(camera) { // 카메라 방향 설정하기
        case 1: directions = cam1; break;
        case 2: directions = cam2; break;
        case 3: directions = cam3; break;
        case 4: directions = cam4; break;
    }

    for(int i = 0; i < directions.size(); i++) { // 카메라 90도 회전하기
        int new_dir = (directions[i] + dir) % 4; // dir만큼 회전

        switch(new_dir) {
            case 0: right(row, col, copyed); break;
            case 1: up(row, col, copyed); break;
            case 2: left(row, col, copyed); break;
            case 3: down(row, col, copyed); break;
        }
    }
}

void bfs(int idx, vector<pi> dir, vector<vector<int>> copyed) { // (dir : 카메라가 존재하는 칸의 좌표)
    if(idx == dir.size()) { // 모든 카메라 감시 완료, 사각지대 개수 세기
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!copyed[i][j]) cnt++;
            }
        }
        answer = min(answer, cnt);
        return;
    }

    int row = dir[idx].first, col = dir[idx].second;
    for(int i = 0; i < 4; i++) { // (i만큼 회전)
        vector<vector<int>> tmp = copyed;
        supervise(row, col, tmp[row][col], i, tmp);
        bfs(idx+1, dir, tmp);
    }
}

int main() {
    cin >> n >> m;

    vector<pi> all_dir, dir;
    room.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            if(room[i][j] == 5) all_dir.push_back({i, j});
            else if(room[i][j] >= 1 && room[i][j] <= 4) dir.push_back({i, j});
        }
    }

    for(int i = 0; i < all_dir.size(); i++) { // 전방향 감시
        int row = all_dir[i].first, col = all_dir[i].second;
        left(row, col, room); right(row, col, room);
        up(row, col, room); down(row, col, room);
    }

    bfs(0, dir, room);
    cout << answer;
    return 0;
}