#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 5;
// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool bfs(int sr, int sc, vector<string> place) { // (row, col : 응시자 위치)
    vector<vector<int>> dist(SIZE, vector<int>(SIZE, 0)); // 맨허튼 거리 저장
    queue<pair<int, int>> q;

    q.push({sr, sc});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(dist[row][col] >= 3) continue; // 맨허튼 거리 3 이상은 거리두기 지킴

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];

            // 1. 범위를 벗어난 경우
            // 2. 이미 방문한 곳
            // 3. 파티션 있는 경우
            if(new_row < 0 || new_col < 0 || new_row >= SIZE || new_col >= SIZE ||
                    (new_row == sr && new_col == sc) || dist[new_row][new_col] ||
                    place[new_row][new_col] == 'X') continue;

            // 맨허튼 거리 계산
            dist[new_row][new_col] = abs(sr - new_row) + abs(sc - new_col);

            // 맨허튼 거리 2 이하의 사람 발견 -> 거리두기 지키지 못함
            if(place[new_row][new_col] == 'P' && dist[new_row][new_col] <= 2) return false;
            q.push({new_row, new_col});
        }
    }
    return true;
}

bool distancing(vector<string> place) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // (i, j) 위치의 사람이 거리두기 지키지 못함
            if(place[i][j] == 'P' && !bfs(i, j, place))
                return false;
        }
    }
    return true;
}