#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e4 + 1;

vector<pi> dijkstra(int n, vector<vector<pi>> &edge) {
    // (first : 1번 노드까지의 최단 거리, second : 연결해야 하는 노드)
    vector<pi> dist (n+1, {INF, 0});
    priority_queue<pi, vector<pi>, greater<>> pq;

    // 시작 정점 세팅
    pq.push({0, 1});
    dist[1] = {0, 1};

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(int i = 0; i < edge[node].size(); i++) {
            int new_node = edge[node][i].first;
            int new_weight = edge[node][i].second;

            if(dist[new_node].first > weight + new_weight) { // 최단 거리 갱신
                dist[new_node].first = weight + new_weight;
                dist[new_node].second = node; // node와 new_node를 연결하는 회선
                pq.push({dist[new_node].first, new_node});
            }
        }
    }

    vector<pi> answer;
    for(int i = 2; i <= n; i++) {
        answer.push_back({i, dist[i].second});
    }
    return answer;
}

int main() {
    int n, m, a, b, c;
    vector<vector<pi>> edge;

    cin >> n >> m;
    edge.assign(n+1, vector<pi> ());
    while(m--) {
        cin >> a >> b >> c;
        // 양방향 그래프
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    vector<pi> answer = dijkstra(n, edge);
    cout << answer.size() << '\n';
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].first << ' ' << answer[i].second << '\n';
    }
    return 0;
}