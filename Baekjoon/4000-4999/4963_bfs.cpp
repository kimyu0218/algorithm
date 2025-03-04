#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int LAND = 1;
const int VISITED = -1;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_valid_pos(int r, int c, int h, int w) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

void bfs(int sr, int sc, int h, int w, vector<vector<int>> &map) {
    queue<pi> q;

    q.push({sr, sc});
    map[sr][sc] = VISITED;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!is_valid_pos(nr, nc, h, w) || map[nr][nc] != LAND) {
                continue;
            }
            map[nr][nc] = VISITED;
            q.push({nr, nc});
        }
    }
}

int solution(vector<vector<int>> map) {
    int result = 0;
    int h = map.size();
    int w = map[0].size();

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] != LAND) {
                continue;
            }
            bfs(i, j, h, w, map);
            result++;
        }
    }
    return result;
}

int main() {
    int w, h;
    vector<vector<int>> map;

    while(true) {
        cin >> w >> h;

        if(w == 0 && h == 0) {
            break;
        }

        map.assign(h, vector<int> (w, 0));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        cout << solution(map) << '\n';
    }
    return 0;
}