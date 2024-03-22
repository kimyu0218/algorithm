#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int RED = 1;
const int GREEN = 0;
const int NONE = -1;

struct tomato {
    int r, c, day;
};

int cnt_tomatoes(int n, int m, vector<vector<int>> tomatoes) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result += (tomatoes[i][j] != NONE);
        }
    }
    return result;
}

bool is_valid_pos(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

pi bfs(int n, int m, vector<vector<int>> tomatoes) {
    int t_cnt = 0;
    int d_cnt = 0;
    queue<tomato> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tomatoes[i][j] != RED) {
                continue;
            }
            q.push({i, j, 0});
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int day = q.front().day;
        q.pop();

        d_cnt = day;
        t_cnt++;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!is_valid_pos(nr, nc, n, m) || tomatoes[nr][nc] != GREEN) {
                continue;
            }
            tomatoes[nr][nc] = RED;
            q.push({nr, nc, day + 1});
        }
    }
    return {t_cnt, d_cnt};
}

int solution(vector<vector<int>> tomatoes) {
    int n = tomatoes.size();
    int m = tomatoes[0].size();

    int t_cnt = cnt_tomatoes(n, m, tomatoes);
    pi result = bfs(n, m, tomatoes);

    return (t_cnt == result.first) ? result.second : -1;
}

int main() {
    int m, n;
    vector<vector<int>> tomatoes;

    cin >> m >> n;

    tomatoes.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tomatoes[i][j];
        }
    }

    cout << solution(tomatoes);
    return 0;
}