#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<>> pq;
const int INF = 1e8;

int dijkstra(int n, int src, int dst, vector<pq> &bus) {
    vector<int> dist (n+1, INF);
    pq city;

    // 시작정점
    dist[src] = 0;
    while(!bus[src].empty()) {
        city.push(bus[src].top());
        bus[src].pop();
    }

    while(!city.empty()) {
        int node = city.top().second;
        int cost = city.top().first;
        city.pop();

        dist[node] = min(dist[node], cost);
        while(!bus[node].empty()) {
            int next = bus[node].top().second; // node에서 이동할 수 있는 다음 도시
            int new_cost = cost + bus[node].top().first; // 다음 도시까지 이동한 비용
            bus[node].pop();
            city.push({new_cost, next});
        }
    }
    return dist[dst];
}

int main() {
    int n, m, src, dst, cost;
    vector<pq> bus;

    cin >> n >> m;
    bus.assign(n+1, pq());
    for(int i = 0; i < m; i++) {
        cin >> src >> dst >> cost;
        bus[src].push({cost, dst});
    }
    cin >> src >> dst;

    cout << dijkstra(n, src, dst, bus);
    return 0;
}