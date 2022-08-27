#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; // (한 번 이동했던 정점/간선도 다시 이동 가능)
int n;
vector<vector<ci>> graph;

int dijkstra(int start, int end) {
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 정점 초기화
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 탐색한 노드 pass
        // node와 연결된 정점 탐색
        for(int i = 0; i < graph[node].size(); i++) {
            int new_node = graph[node][i].first;
            int new_weight = graph[node][i].second + weight;
            if(dist[new_node] > new_weight) {
                dist[new_node] = new_weight;
                pq.push({new_weight, new_node});
            }
        }
    }
    return dist[end];
}

int main() {
    int e, a, b, c, v1, v2;
    cin >> n >> e;

    graph.assign(n+1, vector<ci> (0));
    while(e--) {
        cin >> a >> b >> c;
        // (무방향 그래프)
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;
    // 방법 1 : 1-v1, v1-v2, v2-n 최단 거리 합치기
    int case1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
    // 방법 2 : 1-v2, v2-v1, v1-n 최단 거리 합치기
    int case2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

    int ans = min(case1, case2);
    if(ans >= INF) cout << -1;
    else cout << ans;
    return 0;
}