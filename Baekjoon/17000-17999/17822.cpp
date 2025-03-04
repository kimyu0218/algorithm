#include <iostream>
#include <vector>

using namespace std;

struct info{
    int x, d, k;
};

void rotate(int n, int m, int x, int d, int k, vector<vector<int>> &board) {
    int dir = (d == 0) ? 1 : m-1;
    for(int i = x; i <= n; i += x) { // i : 원판 번호
        vector<int> rotated(m, 0);
        for(int j = 0; j < m; j++) { // j : 원판 위의 수
            rotated[(j+dir*k) % m] = board[i][j];
        }
        board[i] = rotated;
    }
}

void dfs(int i, int j, int n, int m, vector<vector<int>> &board) {
    int num = board[i][j];
    board[i][j] = 0;

    // 1. i번째 원판 확인
    int left = (j+m-1) % m, right = (j+1) % m;
    if(board[i][left] == num) { // 1-1. 왼쪽 확인
        dfs(i, left, n, m, board);
    }
    if(board[i][right] == num) { // 1-2. 오른쪽 확인
        dfs(i, right, n, m, board);
    }

    // 2. 다른 원판 확인
    if(i-1 && board[i-1][j] == num) { // 2-1. i-1번째 원판 확인
        dfs(i-1, j, n, m, board);
    }
    if(i+1 <= n && board[i+1][j] == num) { // 2-2. i+1번째 원판 확인
        dfs(i+1, j, n, m, board);
    }
}

bool remove(int n, int m, vector<vector<int>> &board) {
    bool find = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]) { // 원판에 수가 남아있는 경우
                int left = (j+m-1) % m, right = (j+1) % m;
                // 인접한 칸에 같은 숫자 존재하는 경우
                if(board[i][j] == board[i][left] || board[i][j] == board[i][right]
                    || (i-1 && board[i][j] == board[i-1][j])
                    || (i+1 <= n && board[i][j] == board[i+1][j])) {
                    find = true;
                    dfs(i, j, n, m, board);
                }
            }
        }
    }
    return find;
}

bool computeAvg(int n, int m, vector<vector<int>> &board) {
    double sum = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]) {
                cnt++;
                sum += board[i][j];
            }
        }
    }
    if(cnt == 0) { // 원판에 숫자가 없음
        return true;
    }
    double avg = sum / cnt;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]) {
                if(board[i][j] > avg) {
                    board[i][j]--;
                }
                else if(board[i][j] < avg) {
                    board[i][j]++;
                }
            }
        }
    }
    return false;
}

int solution(int n, int m, int t, vector<vector<int>> &board, vector<info> &cmd) {
    int sum = 0;
    for(int i = 0; i < t; i++) { // t번 회전
        rotate(n, m, cmd[i].x, cmd[i].d, cmd[i].k, board); // 1. 회전
        if(!remove(n, m, board)) { // 2. 같은 수 제거
            if(computeAvg(n, m, board)) { // 3. 같은 수 없는 경우, 평균 계산
                return 0; // 3-1. 원판에 숫자가 없는 경우 바로 0 리턴
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            sum += board[i][j];
        }
    }
    return sum;
}

int main() {
    int n, m, t;
    vector<vector<int>> board;
    vector<info> cmd;

    cin >> n >> m >> t;
    board.assign(n+1, vector<int> (m, 0));
    cmd.assign(t, {});
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < t; i++) {
        cin >> cmd[i].x >> cmd[i].d >> cmd[i].k;
    }

    cout << solution(n, m, t, board, cmd);
    return 0;
}