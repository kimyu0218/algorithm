#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int SIZE = 100;
const int TRASH = 1;
const int VISITED = -1;

int answer = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int board[SIZE][SIZE];

void set_trash(int k, vector<pi> pos) {
    for(int i = 0; i < k; i++) {
        int r = pos[i].first - 1;
        int c = pos[i].second - 1;
        board[r][c] = TRASH;
    }
}

int dfs(int r, int c, int n, int m) {
    int answer = 1;
    board[r][c] = VISITED;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != TRASH) {
            continue;
        }
        answer += dfs(nr, nc, n, m);
    }
    return answer;
}

int solution(int n, int m, vector<pi> pos) {
    int answer = 0;
    int k = pos.size();

    set_trash(k, pos);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == TRASH) {
                answer = max(answer, dfs(i, j, n, m));
            }
        }
    }
    return answer;
}

int main() {
    int n, m, k;
    vector<pi> pos;

    cin >> n >> m >> k;

    pos.assign(k, {0, 0});
    for(int i = 0; i < k; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    cout << solution(n, m, pos);
    return 0;
}