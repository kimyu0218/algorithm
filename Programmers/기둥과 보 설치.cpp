#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<bool>>> board; // (0 : 기둥, 1 : 보)

bool validate(int x, int y, int type, int n) {
    if(type) { // 1. 보
        if(y > 0 && board[x][y-1][0]) return true; // 왼쪽 끝이 기둥 위
        if(x < n && y > 0 && board[x+1][y-1][0]) return true; // 오른쪽 끝이 기둥 위
        if(x > 0 && x < n && board[x-1][y][1] && board[x+1][y][1]) return true; // 양쪽 끝이 보
    }
    else { // 2. 기둥
        if(!y) return true; // 바닥 위
        if(board[x][y][1] || (x-1 >= 0 && board[x-1][y][1])) return true; // 보 왼쪽 & 오른쪽 끝
        if(y > 0 && board[x][y-1][0]) return true; // 기둥 위
    }
    return false;
}

bool check(int x, int y, int n) {
    int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int nx = x + dx[i];
            int ny = y + dy[j];
            if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
            for(int k = 0; k < 2; k++) {
                if(board[nx][ny][k] && !validate(nx, ny, k, n))
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    board.assign(n+1, vector<vector<bool>> (n+1, vector<bool> (2, false)));

    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0], y = build_frame[i][1];
        int type = build_frame[i][2], cmd = build_frame[i][3];

        if(!cmd) { // 삭제
            board[x][y][type] = false; // 일단 삭제
            board[x][y][type] = !check(x, y, n); // 삭제했을 때 이전에 설치한 구조물에 영향을 미치진 않는가
        }
        else board[x][y][type] = validate(x, y, type, n); // 설치
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < 2; k++) {
                if(board[i][j][k]) answer.push_back({i, j, k});
            }
        }
    }
    return answer;
}
