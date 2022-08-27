#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e6;
vector<vector<ci>> graph, rev_graph; // 순방향 그래프, 역방향 그래프

vector<int> dijkstra(int start, int n, vector<vector<ci>> g) {
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 지점 초기화
    dist[start] = 0; pq.push({0, start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 방문한 노드 pass

        for(int i = 0; i < g[node].size(); i++) {
            int new_node = g[node][i].first;
            int new_weight = weight + g[node][i].second;
            if(dist[new_node] > new_weight) { // 더 짧은 경로 발견
                dist[new_node] = new_weight;
                pq.push({new_weight, new_node});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, x, u, v, w;
    cin >> n >> m >> x;

    graph.assign(n+1, vector<ci> (0));
    rev_graph.assign(n+1, vector<ci> (0));
    while(m--) { // m개의 간선
        cin >> u >> v >> w;
        // u에서 v로 가는 가중치 w
        graph[u].push_back({v, w});
        rev_graph[v].push_back({u, w});
    }

    vector<int> go_dist = dijkstra(x, n, rev_graph); // 모든 정점에서 x로 가는 최단 경로
    vector<int> back_dist = dijkstra(x, n, graph); // x에서 모든 정점까지 가는 최단 경로

    int time = 0;
    for(int i = 1; i <= n; i++)
        time = max(time, go_dist[i] + back_dist[i]);
    cout << time;
    return 0;
}