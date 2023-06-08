#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int RED = 0, GREEN = 1;
struct info{
    int row, col, color;
};
int n, m, answer = 0;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;
vector<vector<int>> garden;

int bfs(int r, int g, vector<pi> &red, vector<pi> &green) { // 꽃 개수 세기
    int cnt = 0;
    vector<vector<vector<int>>> time (n, vector<vector<int>> (m, vector<int> (2, -1)));
    queue<info> curr, next;
    
    // 시작점 세팅
    for(int i = 0; i < r; i++) {
        int row = red[i].first;
        int col = red[i].second;
        curr.push({row, col, RED});
        time[row][col][RED] = 0;
    }
    for(int i = 0; i < g; i++) {
        int row = green[i].first;
        int col = green[i].second;
        curr.push({green[i].first, green[i].second, GREEN});
        time[row][col][GREEN] = 0;
    }
    
    while(!curr.empty()) {
        int row = curr.front().row;
        int col = curr.front().col;
        int color = curr.front().color;
        curr.pop();
        
        for(int i = 0; i < 4; i++) { // 인접한 칸 확인
            int nr = row + dr[i];
            int nc = col + dc[i];

            // 아직 color의 배양액이 퍼지지 않은 땅 발견
            if(nr >= 0 && nr < n && nc >= 0 && nc < m 
            && garden[nr][nc] && time[nr][nc][color] == -1) {
                time[nr][nc][color] = time[row][col][color] + 1;
                // 빨간색 배양액과 초록색 배양액이 퍼진 시간이 다른 경우 next에 push
                if(time[nr][nc][RED] != time[nr][nc][GREEN]) {
                    next.push({nr, nc, color});
                }
            }
        }

        if(curr.empty()) { // 현재 시간대에 뿌려야하는 배양액 뿌리기 완료
            while(!next.empty()) {
                int nr = next.front().row;
                int nc = next.front().col;
                int ncolor = next.front().color;
                next.pop();

                // 1. 빨간색 배양액과 초록색 배양액이 퍼진 시간이 다른 경우, 다시 배양액 퍼지기 시작함
                if(time[nr][nc][RED] != time[nr][nc][GREEN]) {
                    curr.push({nr, nc, ncolor});
                }
                // 2. 빨간색 배양액과 초록색 배양액이 퍼진 시간이 같은 경우, 꽃이 피어남
                else {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void backtracking(int r_cnt, int g_cnt, int r, int g, int idx, vector<pi> red, vector<pi> green) { // 배양액 뿌리기
    if(r_cnt == r && g_cnt == g) { // 기저 조건 : 빨간색 배양액 r개, 초록색 배양액 g개 뿌리기 완료
        int result = bfs(r, g, red, green);
        answer = max(answer, result);
        return;
    }
    for(int i = idx; i < n*m; i++) {
        int row = i / m, col = i % m;
        if(garden[row][col] == 2 && !visited[row][col]) {
            visited[row][col] = true; // 방문 체크
            if(r_cnt < r) { // 빨간색 배양액 뿌리기
                vector<pi> tmp = red;
                tmp.push_back({row, col});
                backtracking(r_cnt+1, g_cnt, r, g, i+1, tmp, green);
            }
            if(g_cnt < g) { // 초록색 배양액 뿌리기
                vector<pi> tmp = green;
                tmp.push_back({row, col});
                backtracking(r_cnt, g_cnt+1, r, g, i+1, red, tmp);
            }
            visited[row][col] = false; // 방문 취소
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int g, r;

    cin >> n >> m >> g >> r;
    garden.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<bool> (m, false));
    for(int i = 0; i < n; i++) { // 정원 정보 입력
        for(int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }

    backtracking(0, 0, r, g, 0, {}, {});
    cout << answer;
    return 0;
}