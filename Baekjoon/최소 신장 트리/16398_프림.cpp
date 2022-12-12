#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
const ll INF = 1e11 + 1;

ll prim(int n, int start, vector<vector<int>> &graph) {
    ll sum = 0;
    vector<bool> visited(n, false);
    vector<ll> dist(n, INF);

    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto[curr_w, curr] = pq.top(); pq.pop();

        if(visited[curr]) { // 이미 방문한 정점 pass
            continue;
        }
        visited[curr] = true; // 방문 체크
        sum += curr_w;

        for(int i = 0; i < n; i++) {
            // 미방문 정점이고 더 짧은 가중치 발견
            if(!visited[i] && dist[i] > graph[curr][i]) {
                pq.push({graph[curr][i], i});
                dist[i] = graph[curr][i];
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 행성 플로우 관리 비용 입력
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << prim(n, 0, graph);
    return 0;
}