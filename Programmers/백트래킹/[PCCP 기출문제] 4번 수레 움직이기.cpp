#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int SIZE = 4;
const int INF = SIZE * SIZE;
const int COLOR = 2;
const int RED = 0;
const int BLUE = 1;
const int WALL = 5;
const int UNVISITED = -1;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int answer = INF;
bool reached[COLOR];
vector<vector<vector<int>>> dist;

vector<pi> get_src(int n, int m, vector<vector<int>> maze) {
    vector<pi> src(COLOR, {0, 0});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 1 || maze[i][j] == 2) {
                src[maze[i][j] - 1] = {i, j};
            }
        }
    }
    return src;
}

bool co_exist(int turn, int cnt, int r, int c, pi other) {
    if(reached[!turn] && r == other.first && c == other.second) {
        return true;
    }
    if(turn == RED) {
        return false;
    }
    return cnt == dist[RED][r][c];
}

bool pass_by(int turn, int cnt, int cr, int cc, int nr, int nc) {
    if(turn == RED) {
        return false;
    }
    return dist[!turn][cr][cc] == cnt && dist[!turn][nr][nc] == cnt - 1;
}

void backtracking(int n, int m, int turn, vector<pi> pos, vector<int> cnt, vector<vector<int>> maze) {
    if(reached[RED] && reached[BLUE]) {
        answer = min(answer, max(cnt[RED], cnt[BLUE]));
        return;
    }

    if(reached[turn]) {
        backtracking(n, m, !turn, pos, cnt, maze);
        return;
    }

    cnt[turn]++;
    int r = pos[turn].first;
    int c = pos[turn].second;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m
           || dist[turn][nr][nc] != UNVISITED
           || maze[nr][nc] == WALL
           || co_exist(turn, cnt[turn], nr, nc, pos[!turn])
           || pass_by(turn, cnt[turn], r, c, nr, nc)
                ) {
            continue;
        }
        dist[turn][nr][nc] = cnt[turn];
        reached[turn] = (maze[nr][nc] == turn + 3);
        pos[turn] = {nr, nc};

        backtracking(n, m, !turn, pos, cnt, maze);

        dist[turn][nr][nc] = UNVISITED;
        pos[turn] = {r, c};
        reached[turn] = false;
    }
    cnt[turn]--;
}

int solution(vector<vector<int>> maze) {
    int n = maze.size();
    int m = maze[0].size();
    dist.assign(COLOR, vector<vector<int>> (n, vector<int> (m, UNVISITED)));

    vector<pi> src = get_src(n, m, maze);
    for(int i = 0; i < COLOR; i++) {
        int r = src[i].first;
        int c = src[i].second;
        dist[i][r][c] = 0;
    }

    backtracking(n, m, RED, src, {0, 0}, maze);
    return (answer == INF) ? 0 : answer;
}