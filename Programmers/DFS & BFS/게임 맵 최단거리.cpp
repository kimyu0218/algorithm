#include <vector>
#include <queue>

using namespace std;

const int EMPTY = 1;
const int VISITED = -1;

struct info {
    int row, col, cnt;
};

bool is_valid_pos(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<info> q;
    q.push({0, 0, 1});

    while(!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int cnt = q.front().cnt;
        q.pop();

        if(r == n - 1 && c == m - 1) {
            return cnt;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!is_valid_pos(nr, nc, n, m) || maps[nr][nc] != EMPTY) {
                continue;
            }
            maps[nr][nc] = VISITED;
            q.push({nr, nc, cnt + 1});
        }
    }
    return -1;
}