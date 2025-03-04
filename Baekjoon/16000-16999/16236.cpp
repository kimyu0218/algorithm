#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
const int SIZE = 20;

struct info{
    // dist : 상어에서 현재 칸까지의 거리
    // time : 소요시간
    int dist, row, col, time;
};

int n, answer = 0;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
int space[SIZE][SIZE];
map<int, int> shark; // (key : 상어 크기, value : key 몸무게일 때 잡아먹은 물고기 수)

bool compare(const info &i1, const info &i2) {
    if(i1.row != i2.row) return i1.row < i2.row; // 1. 가장 위에 있는 물고기
    return i1.col < i2.col; // 2. 가장 왼쪽에 있는 물고기
}

void baby_shark(int row, int col, int size, int time) { // (row, col) 아기 상어 위치, size : 아기 상어 크기
    answer = max(answer, time);
    vector<vector<bool>> visited (n, vector<bool> (n, false));

    bool find = false;
    vector<info> fish; // 먹을 수 있는 물고기 후보
    queue<info> q; // 다음 칸 정보 저장
    q.push({0, row, col, time});

    while(!q.empty()) { // 상어의 이동
        int r = q.front().row, c = q.front().col;
        int dist = q.front().dist, sec = q.front().time; q.pop();

        if(visited[r][c]) continue; // 방문한 칸 pass
        visited[r][c] = true; // 방문 check

        // 먹을 수 있는 물고기를 발견했고, 더 이상 해당 물고기보다 먹을 수 있는 더 가까운 물고기를 찾을 수 없는 경우 탐색 종료
        if(find && (dist+1 != fish[0].dist)) break;

        for(int i = 0; i < 4; i++) { // (상하좌우 확인)
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue; // 경계 뛰어넘었거나 이미 방문한 곳 pass

            if(space[nr][nc] > size) continue; // 1. 자신의 크기보다 큰 몰고기 -> 지나갈 수 없음

            // 2. 나머지 칸
            // 2-1. 자신의 크기보다 작은 물고기 잡아먹기
            if(space[nr][nc] && space[nr][nc] < size) {
                fish.push_back({dist+1, nr, nc, sec+1});
                find = true; // 먹을 수 있는 물고기 발견
            }
            // 2-2. 지나가기
            else q.push({dist+1, nr, nc, sec+1});
        }
    }

    if(find) { // 상어 이동
        sort(fish.begin(), fish.end(), compare); // 먹을 물고기 정하기

        int nr = fish[0].row, nc = fish[0].col;
        space[nr][nc] = 0; // 잡아먹기

        if(++shark[size] == size) baby_shark(nr, nc, size+1, fish[0].time); // 크기 키우고 이동
        else baby_shark(nr, nc, size, fish[0].time); // 그대로 이동
    }
}

int main() {
    cin >> n; // 공간 크기

    int row, col; // 아기 상어 위치
    for(int i = 0; i < n; i++) { // 공간 상태 입력
       for(int j = 0; j < n; j++) {
           cin >> space[i][j];
           if(space[i][j] == 9) {
               row = i;
               col = j;
           }
       }
    }

    space[row][col] = 0;
    baby_shark(row, col, 2, 0);
    cout << answer;
    return 0;
}