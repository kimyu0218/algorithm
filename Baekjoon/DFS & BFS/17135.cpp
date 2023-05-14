#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
const int CNT = 3;
typedef pair<int, int> pi;

struct info {
    int r, c, d, num;
};
int n, m, d, answer = 0;
int dr[3] = {0, -1, 0}, dc[3] = {-1, 0, 1}; // 시계 방향 (좌 상 우)
vector<vector<int>> board;
pi archer[CNT]; // 선발된 궁수 좌표 목록

int bfs(vector<vector<int>> &b) {
    queue<info> q; // (bfs 용)
    set<pi> enemy; // 이번에 궁수가 제거하는 적의 위치
    vector<bool> shot (CNT, false); // shot[i] : i 궁수가 적을 쏘았는가
    vector<vector<vector<bool>>> visited (n, vector<vector<bool>> (m, vector<bool> (CNT, false)));

    for(int i = 0; i < CNT; i++) {
        int r = archer[i].first, c = archer[i].second;
        q.push({r, c, 0, i});
    }

    while(!q.empty()) {
        int r = q.front().r, c = q.front().c;
        int dist = q.front().d;
        int num = q.front().num;
        q.pop();

        if(shot[num] || dist >= d) { // 이미 다른 적을 쏘았거나 더 멀리 쏠 수 없는 경우
            continue;
        }

        queue<info> tmp;
        for(int i = 0; i < 3; i++) { // 인접한 칸 탐색
            int nr = r + dr[i], nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc][num]) { // 아직 방문하지 않은 정점 중
                visited[nr][nc][num] = true; // 방문 체크
                if(b[nr][nc]) { // 1. 적을 발견한 경우
                    shot[num] = true;
                    enemy.insert({nr, nc});
                    break;
                }
                else  { // 2. 적을 발견하지 못한 경우
                    tmp.push({nr, nc, dist+1, num});
                }
            }
        }
        if(!shot[num]) { // num 궁수가 공격에 성공하지 못한 경우
            while(!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
        }
    }

    for(auto iter = enemy.begin(); iter != enemy.end(); iter++) { // 적 제거하기
        int r = iter->first;
        int c = iter->second;
        b[r][c] = 0;
    }
    return enemy.size(); // 공격으로 제거한 적의 수
}

void enemyMove(vector<vector<int>> &b) { // 아래로 한 칸씩 이동하기
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            b[i+1][j] = b[i][j];
        }
    }
    for(int j = 0; j < m; j++) { // 맨 윗줄 0 처리
        b[0][j] = 0;
    }
}

bool enemyExist(vector<vector<int>> &b) { // 적이 남아있는가
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j]) {
                return true;
            }
        }
    }
    return false;
}

void backtracking(int idx, int cnt) {
    if(cnt == CNT) { // 궁수 선발 완료
        vector<vector<int>> b = board;
        int remove_cnt = 0; // 선발된 궁수로 쏠 수 있는 적 카운트
        while(true) {
            remove_cnt += bfs(b);
            enemyMove(b);
            if(!enemyExist(b)) { // 적이 더이상 존재하지 않는 경우
                break;
            }
        }
        answer = max(answer, remove_cnt);
        return;
    }
    if(idx == m) { // 범위 벗어나는 경우
        return;
    }

    for(int i = idx; i < m; i++) {
        archer[cnt] = {n, i};
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin >> n >> m >> d;
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 격자판 상태 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    backtracking(0, 0);
    cout << answer;
    return 0;
}