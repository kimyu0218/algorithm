#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int SIZE = 50, CNT = 10, UNVISITED = -1, WALL = 1;

int n, blank = 0, answer = -1;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상 하 좌 우
int lab[SIZE][SIZE]; // 연구소
pi pos[CNT], virus[CNT]; // 바이러스를 놓을 수 있는 위치, 활성화된 바이러스의 위치

void bfs(int m) {
    int cnt = blank; // 빈 칸 개수
    queue<pi> q;
    
    // 시작 정점 초기화
    vector<vector<int>> time (n, vector<int> (n, UNVISITED));
    for(int i = 0; i < m; i++) { // 활성 바이러스 세팅
        int r = virus[i].first, c = virus[i].second;
        time[r][c] = 0;
        q.push(virus[i]);
    }

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) { // 인접한 칸 탐색
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 벽이 아니고 아직 방문하지 않은 지점 발견
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && lab[nr][nc] != WALL && time[nr][nc] == UNVISITED) {
                time[nr][nc] = time[r][c] + 1;
                if(!lab[nr][nc]) { // 빈 칸인 경우
                    if(--cnt == 0) { // 모든 빈 칸에 바이러스를 퍼뜨릴 수 있는 경우, 답 갱신 후 종료
                        if(answer == -1) {
                            answer = time[nr][nc];
                        }
                        else {
                            answer = min(answer, time[nr][nc]);
                        }
                        return;
                    }
                }
                q.push({nr, nc});
            }
        }
    }
}

void backtracking(int idx, int cnt, int m, int p_cnt) { // 활성화 시킬 바이러스 선택하기
    if(cnt == m) { // 1. m개의 활성 바이러스 선정 완료
        bfs(m);
        return;
    }
    if(idx == p_cnt) { // 2. idx가 인덱스를 벗어난 경우
        return;
    }

    for(int i = idx; i < p_cnt; i++) {
        virus[cnt] = pos[i];
        backtracking(i+1, cnt+1, m, p_cnt);
    }
}

int main() {
    int m, p_cnt = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++) { // 연구소 상태 입력
        for(int j = 0; j < n; j++) {
            cin >> lab[i][j];
            if(!lab[i][j]) { // 빈 칸 개수 카운트
                blank++;
            }
            else if(lab[i][j] == 2) { // 바이러스를 놓을 수 있는 위치
                pos[p_cnt++] = {i, j};
            }
        }
    }

    if(blank == 0) { // 빈 칸이 존재하지 않는 경우 곧바로 0 출력
        cout << 0;
        return 0;
    }

    backtracking(0, 0, m, p_cnt);
    cout << answer;
    return 0;
}