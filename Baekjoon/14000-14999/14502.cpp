#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m, answer = 0;
vector<vector<int>> map; // 연구소 지도
vector<pi> zeros; // 지도 빈칸 좌표 저장

void bfs(queue<pi> q, vector<vector<int>> &installed) {
    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            //바이러스 전파
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !installed[new_row][new_col]) {
                installed[new_row][new_col] = 2;
                q.push({new_row, new_col});
            }
        }
    }
}

int cnt_blank(vector<vector<int>> installed) { // 안전 영역 카운트
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!installed[i][j]) cnt++;
        }
    }
    return cnt;
}

void install_wall(queue<pi> q) {
    int size = zeros.size();

    for(int i = 0; i < size; i++) { // 브루트포스 방법으로 벽 3개 설치
        for(int j = i+1; j < size; j++) {
            for(int k = j+1; k < size; k++) { // 벽 3개 설치 후, bfs 실행
                pi w1 = zeros[i], w2 = zeros[j], w3 = zeros[k];
                vector<vector<int>> installed = map; // 벽 3개 설치한 지도
                installed[w1.first][w1.second] = installed[w2.first][w2.second] = installed[w3.first][w3.second] = 1;
                bfs(q, installed);
                answer = max(answer, cnt_blank(installed));
            }
        }
    }
}

int main() {
    cin >> n >> m;

    queue<pi> q; // 바이러스 위치 저장
    map.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 지도 입력 (0 : 빈 칸, 1 : 벽, 2 : 바이러스)
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(!map[i][j]) zeros.push_back({i, j}); // 빈칸 push
            else if(map[i][j] == 2) q.push({i, j}); // 바이러스 push
        }
    }

    install_wall(q);
    cout << answer;
    return 0;
}