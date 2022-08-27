#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 * 2;
vector<vector<ci>> graph;

vector<int> dijkstra(int v, int k) {
    vector<int> dist (v+1, INF); // k에서 모든 정점들까지의 가중치
    // (거리 짧은 곳부터 탐색)
    priority_queue<ci, vector<ci>, greater<>> pq; // (first: 가중치, second: 정점)

    // 시작 정점 초기화
    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 확인한 노드 pass
        // 시작 정점에서 node를 거쳐 next_node로 가보자
        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if(dist[next_node] > next_weight) { // node를 거치는 게 좀 더 작은 가중치를 가지는 경우
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    int vertex, edge, k, u, v, w;
    cin >> vertex >> edge >> k;
    graph.assign(vertex + 1, vector<ci> (0));

    while(edge--) {
        cin >> u >> v >> w;
        // (방향 그래프)
        graph[u].push_back({v, w}); // (u에서 v로 가는 가중치 w 간선 존재)
    }

    vector<int> dist = dijkstra(vertex, k);
    for(int i = 1; i <= vertex; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}