#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size(); // (지도 사이즈 : n x m)
    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; // 상 하 좌 우
    vector<vector<int>> w(n, vector<int> (m, -1)); // (-1 : 경로 없음)

    queue<pi> q;
    w[0][0] = 1; q.push({0, 0}); // 시작점
    while(!q.empty()) {
        int row = q.front().first, col = q.front().second; q.pop();
        int weight = w[row][col];

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            // 아직 방문하지 않은 빈칸이 있는 경우 이동
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m
            && maps[new_row][new_col] && w[new_row][new_col] == -1) {
                w[new_row][new_col] = weight + 1;
                q.push({new_row, new_col});
            }
        }
    }
    return w[n-1][m-1];
}