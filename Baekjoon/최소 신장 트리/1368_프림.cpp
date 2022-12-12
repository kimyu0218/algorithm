#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e7 * 3 + 1;

int prim(int n, int start, vector<vector<int>> &graph) {
    int sum = 0;
    vector<bool> visited(n+1, false); // 방문 여부 저장
    vector<int> dist(n+1, INF); // 각 정점까지의 거리

    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, start}); // 시작점
    dist[start] = 0;

    while(!pq.empty()) {
        auto[curr_w, curr] = pq.top(); pq.pop();

        if(visited[curr]) { // 이미 확인한 정점 pass
            continue;
        }
        visited[curr] = true; // 방문 체크
        sum += curr_w;

        for(int i = 0; i <= n; i++) {
            // 미방문 정점이고 더 짧은 가중치 발견
            if(!visited[i] && dist[i] > graph[curr][i]) {
                dist[i] = graph[curr][i];
                pq.push({graph[curr][i], i});
            }
        }
    }
    return sum;
}

int main() {
    int n, w;
    cin >> n;

    vector<vector<int>> graph(n+1, vector<int> (n+1, 0));
    for(int i = 0; i < n; i++) { // 우물 파는 비용 입력
        cin >> w;
        graph[i][n] = graph[n][i] = w;
    }

    for(int i = 0; i < n; i++) { // 논 연결 비용 입력
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << prim(n, 0, graph);
    return 0;
}