#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;
// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<int>> a;

int bfs(int row, int col, vector<vector<bool>> &visited) {
    vector<pair<int, int>> clan; // 연합 국가들 좌표 저장
    queue<pair<int, int>> q;

    // 시작 국가 push
    int sum = a[row][col]; // (sum : 연합 인구수 저장)
    visited[row][col] = true;
    clan.push_back({row, col});
    q.push({row, col});

    while(!q.empty()) {
        int row1 = q.front().first;
        int col1 = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int row2 = row1 + dy[i];
            int col2 = col1 + dx[i];

            // 1. 좌표를 벗어나거나 이미 연합에 속한 국가 pass
            if(row2 < 0 || col2 < 0 || row2 >= n || col2 >= n || visited[row2][col2]) continue;

            int diff = abs(a[row1][col1] - a[row2][col2]); // 두 나라 인구 차이
            if(diff >= l && diff <= r) { // 2. 국경선 열기
                sum += a[row2][col2];
                visited[row2][col2] = true;
                q.push({row2, col2});
                clan.push_back({row2, col2});
            }
        }
    }

    int cnt = clan.size();
    if(cnt == 1) return 0; // 국경선 열지 못한 경우 0 반환

    int pop = sum / cnt;
    for(int i = 0; i < cnt; i++) // 연합 인구 수 갱신
        a[clan[i].first][clan[i].second] = pop;
    return 1; // 국경선 연 경우 1 반환
}

int main() {
    cin >> n >> l >> r;

    a.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) { // 인구 수 입력
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    int date = 0;
    while(true) {
        vector<vector<bool>> visited (n, vector<bool>(n, false));
        int move = 0; // 하루동안 이동한 인구 수 저장
        for(int i = 0; i < n; i++) { // 인구 수 입력
            for(int j = 0; j < n; j++) {
                if(!visited[i][j])
                    move += bfs(i, j, visited);
            }
        }
        if(!move) break; // 1. 하루동안 이동한 인구 수 없는 경우 break
        date++; // 2. 하루동안 이동한 인구 수 있는 경우 날짜 증가
    }

    cout << date;
    return 0;
}