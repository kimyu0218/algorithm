#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200;
typedef pair<int, int> pi;

int r, c;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
queue<pi> q[MAX+4]; // 폭탄 위치 저장하는 큐 (q[i] : i초에 터지는 폭탄 위치)
vector<vector<char>> map;
vector<vector<int>> bomb; // 폭탄이 터져야 하는 시간 저장

void print() { // 격자 현황 출력
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

void bfs(int n) {
    int time = 0, install = 0; // (install : 폭탄 설치 시간)

    while(++time <= n) {
        while(!q[time].empty()) { // (time에 터지는 폭탄 위치)
            // 폭탄 폭발
            int row = q[time].front().first, col = q[time].front().second;
            q[time].pop();
            if(time != bomb[row][col]) continue; // time에 터지는 폭탄이 아닌 경우 (파괴된 폭탄 or 새롭게 생성된 폭탄)

            // 폭탄이 있는 칸 폭발
            map[row][col] = '.';
            bomb[row][col] = 0;
            for(int i = 0; i < 4; i++) { // 인접한 칸도 같이 폭발
                int new_row = row + dr[i], new_col = col + dc[i];
                if(new_row < 0 || new_row >= r || new_col < 0 || new_col >= c) continue;
                map[new_row][new_col] = '.';
                // 지금 폭발하는 폭탄이 아닌 경우 파괴
                if(time != bomb[new_row][new_col]) bomb[new_row][new_col] = 0;
            }
        }

        if(time == install+2) { // 폭탄이 없는 칸에 폭탄 설치
            install = time;
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    if(map[i][j] == '.') {
                        // 폭탄 설치 후 3초 후 폭팔
                        q[install+3].push({i, j});
                        bomb[i][j] = install+3;
                        map[i][j] = 'O';
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> r >> c >> n;

    map.assign(r, vector<char> (c, '\0'));
    bomb.assign(r, vector<int> (c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'O') {
                q[3].push({i, j});
                bomb[i][j] = 3; // (3초 뒤에 터짐)
            }
        }
    }

    bfs(n);
    print();
    return 0;
}