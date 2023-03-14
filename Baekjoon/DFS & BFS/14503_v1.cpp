#include <iostream>
#include <vector>

using namespace std;

int result = 0;
// 북 동 남 서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<vector<int>> room;

void dfs(int row, int col, int d) {
    // 1. 현재 위치 청소 (이미 청소되어 있는 칸은 청소하지 않음)
    if(!room[row][col]) { room[row][col] = 2; result++; }

    // 2.현재 방향을 기준으로 왼족 방향부터 차례대로 탐색
    for(int i = 0; i < 4; i++) {
        int dir = (d + 3 - i) % 4;
        int new_row = row + dy[dir], new_col = col + dx[dir];

        // 아직 청소하지 않은 빈 칸 발견
        if(!room[new_row][new_col]) dfs(new_row, new_col, dir);
    }

    // 네 방향 모두 청소가 이미 되어있거나 벽인 경우
    int dir = (d + 2) % 4;
    int back_row = row + dy[dir], back_col = col + dx[dir];
    if(room[back_row][back_col] == 1) { // 4. 뒤쪽 방향이 벽인 경우 stop
        cout << result;
        exit(0);
    }
    dfs(back_row, back_col, d); // 3. 방향 유지한 상태로 후진
}

int main() {
    int n, m;
    cin >> n >> m;
    room.assign(n, vector<int> (m, 0));

    int r, c, d; // 로봇 청소기 위치 및 방향
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) { // 장소 상태 입력
        for(int j = 0; j < m; j++)
            cin >> room[i][j];
    }

    dfs(r, c, d);
    return 0;
}