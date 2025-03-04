#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

pi solution(int r, int c, int k) {
    int last = r * c;
    if(k > last) { // 좌석을 배정할 수 없는 경우
        return {0, 0};
    }

    int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
    int row = r-1, col = 0, dir = 0;
    vector<vector<int>> board (r, vector<int> (c, 0));

    for(int i = 1; i <= last; i++) {
        board[row][col] = i;
        int nr = row + dr[dir];
        int nc = col + dc[dir];

        if(i == k) {
            return {col+1, r-row};
        }

        // 새로운 위치가 경계를 벗어났거나 이미 다른 관객에게 배정된 경우 회전
        if(nr < 0 || nr >= r || nc < 0 || nc >= c || board[nr][nc]) {
            dir = (dir+1) % 4;
            nr = row + dr[dir];
            nc = col + dc[dir];
        }

        // 자리 이동
        row = nr;
        col = nc;
    }
}

int main() {
    int r, c, k;

    cin >> c >> r >> k;
    pi answer = solution(r, c, k);
    if(answer.first == 0 && answer.second == 0) {
        cout << 0;
        return 0;
    }
    cout << answer.first << ' ' << answer.second;
    return 0;
}