#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int UNVISITED = -1;

int solution(int n, int r1, int c1, int r2, int c2) {
    vector<vector<int>> board(n, vector<int> (n, UNVISITED));

    int dr[6] = {-2, -2, 0, 0, 2, 2};
    int dc[6] = {-1, 1, -2, 2, -1, 1};

    queue<pi> q;
    q.push({r1, c1});
    board[r1][c1] = 0;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(r == r2 && c == c2) {
            return board[r][c];
        }

        for(int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] != UNVISITED) {
                continue;
            }
            q.push({nr, nc});
            board[nr][nc] = board[r][c] + 1;
        }
    }
    return board[r2][c2];
}

int main() {
    int n, r1, c1, r2, c2;

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;


    cout << solution(n, r1, c1, r2, c2);
    return 0;
}