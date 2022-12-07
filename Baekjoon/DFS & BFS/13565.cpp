#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

string bfs(int m, int n, vector<vector<int>> board) {
    queue<pi> q;
    for(int i = 0; i < n; i++) { // outer side의 흰색 부분 push
        if(board[0][i] == 0) {
            board[0][i] = 2;
            q.push({0, i});
        }
    }

    while(!q.empty()) { // outer side부터 전류 침투 시작
        int row = q.front().first, col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) { continue; } // 좌표 벗어남
            if(board[new_row][new_col] == 0) { // 흰색 push
                board[new_row][new_col] = 2;
                q.push({new_row, new_col});
            }
        }
    }

    for(int i = 0; i < n; i++) { // inner side까지 침투했는가 확인
        if(board[m-1][i] == 2) {
            return "YES";
        }
    }
    return "NO"; // 안쪽까지 전달되지 않음
}

int main() {
    int m, n;
    cin >> m >> n;

    string input;
    vector<vector<int>> board(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++) { // 격자 상태 입력
        cin >> input;
        for(int j = 0; j < n; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    cout << bfs(m, n, board);
    return 0;
}