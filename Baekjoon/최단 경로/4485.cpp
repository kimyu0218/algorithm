#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 125 * 10;
typedef struct {
    int weight, row, col;
}s;
// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<int>> graph;

struct cmp {
    bool operator() (s &s1, s &s2) {
        if(s1.weight != s2.weight) return s1.weight > s2.weight;
        if(s1.row != s2.row) return s1.row > s2.row;
        return s1.col > s2.col;
    }
};

int dijkstra(int n) {
    vector<vector<int>> lose (n, vector<int> (n, INF));
    priority_queue<s, vector<s>, cmp> pq;

    // 젤다 위치 push (== 시작 지점)
    lose[0][0] = graph[0][0];
    pq.push({graph[0][0], 0, 0});

    while(!pq.empty()) {
        int row = pq.top().row;
        int col = pq.top().col;
        int weight = pq.top().weight;
        pq.pop();

        if(weight > lose[row][col]) continue; // 이미 방문한 노드 pass
        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row < 0 || new_col < 0 || new_row >= n || new_col >= n) continue; // 좌표 벗어남

            int new_weight = weight + graph[new_row][new_col];
            if(lose[new_row][new_col] > new_weight) {
                lose[new_row][new_col] = new_weight;
                pq.push({new_weight, new_row, new_col});
            }
        }
    }
    return lose[n-1][n-1];
}

int main() {
    int n, test_no = 1;
    while(true) {
        cin >> n;
        if(!n) break;

        graph.assign(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++) { // 도둑루피 크기 입력력
            for(int j = 0; j < n; j++)
                cin >> graph[i][j];
        }
        cout << "Problem " << test_no++ << ": " << dijkstra(n) << '\n';
    }
    return 0;
}