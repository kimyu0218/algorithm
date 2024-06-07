#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const char W = 'W';
const char L = 'L';

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct info {
    int r, c, dist;
};

int bfs(int sr, int sc, int h, int w, vector<vector<char>> map) {
    int answer = 0;
    vector<vector<bool>> visited(h, vector<bool> (w, false));

    queue<info> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = true;

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int dist = q.front().dist;
        q.pop();

        answer = max(answer, dist);

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= h || nc < 0 || nc >= w || map[nr][nc] != L || visited[nr][nc]) {
                continue;
            }
            q.push({nr, nc, dist + 1});
            visited[nr][nc] = true;
        }
    }
    return answer;
}

int solution(int h, int w, vector<vector<char>> map) {
    int answer = 0;

    for(int i = 0 ; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == L) {
                answer = max(answer, bfs(i, j, h, w, map));
            }
        }
    }
    return answer;
}

int main() {
    int h, w;
    string input;
    vector<vector<char>> map;

    cin >> h >> w;

    map.assign(h, vector<char> (w, ' '));
    for(int i = 0; i < h; i++) {
        cin >> input;

        for(int j = 0; j < w; j++) {
            map[i][j] = input[j];
        }
    }

    cout << solution(h, w, map);
    return 0;
}